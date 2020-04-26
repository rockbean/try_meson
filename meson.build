project('my_test', 'c',
	version: run_command(find_program('cat', 'more'), files('VERSION')).stdout().strip(),
	default_options: ['buildtype=release', 'default_library=static'],
)

# set up some global vars for compiler, platform, configuration, etc.
cc = meson.get_compiler('c')
mt_conf = configuration_data()
mt_libraries = []
mt_libs_disabled = []

global_inc = include_directories(
	'.',
	'config',
	'include'
)

app_sources = files('main.c')

subdir('config')
subdir('lib')

default_cflags = machine_args
deps = ['foo', 'boo']

dp_objs = []
foreach dp: deps
	if dp not in mt_libs_disabled
		dp_objs += get_variable('dep_mt_' + dp)
	endif
endforeach

# write the build config
build_cfg = 'mt_build_config.h'
configure_file(
	output: build_cfg,
	configuration: mt_conf
)

executable('my_test',
			app_sources,
			c_args: default_cflags,
			dependencies: dp_objs,
			install: true
)

output_message = '\n=================\nContent Skipped\n=================\n'
output_message += '\nlibs:\n\t'
foreach lib:mt_libs_disabled
	reason = get_variable(lib.underscorify() + '_disable_reason')
	output_message += lib + ':\t' + reason + '\n\t'
endforeach
message(output_message + '\n')