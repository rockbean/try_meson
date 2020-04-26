libraries = [
    'foo', # foo
    'boo', # boo
]

default_cflags = machine_args

if cc.has_argument('-Wno-format-truncation')
	default_cflags += '-Wno-format-truncation'
endif

enabled_libs = [] # used to print summary at the end

foreach lb:libraries
	build = true
	name = lb

	sources = []
	headers = []
	includes = []
	cflags = default_cflags
	# other object files to link against, used e.g. for
	# instruction-set optimized versions of code
	objs = []
	# internal module dependencies
	deps = []

	dir_name = lb
	subdir(dir_name)

	if build
		mt_deps = []
		foreach dp: deps
			mt_deps += [get_variable('dep_mt_' + dp)]
		endforeach

		enabled_libs += name
		install_headers(headers)
		libname = 'mt_' + name
		includes += include_directories(dir_name)

		mt_lib = library(
			libname,
			sources,
			c_args: cflags,
			include_directories: includes,
			dependencies: mt_deps
		)
		mt_lib_dep = declare_dependency(
			link_with: mt_lib,
			include_directories: includes,
			dependencies: mt_deps
		)

		mt_libraries = [mt_lib] + mt_libraries

		set_variable('dep_mt_' + name, mt_lib_dep)
	else
		mt_libs_disabled += name
		set_variable(name.underscorify() + '_disable_reason', reason)
	endif


endforeach