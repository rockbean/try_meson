supported_exec_envs = ['freebsd', 'linux', 'windows']
exec_env = host_machine.system()
if not supported_exec_envs.contains(exec_env)
	error('unsupported system type "@0@"'.format(exec_env))
endif

foreach env:supported_exec_envs
	set_variable('is_' + env, exec_env == env)
endforeach

machine_args = []

toolchain = cc.get_id()
mt_conf.set_quoted('MT_TOOLCHAIN', toolchain)
mt_conf.set('MT_TOOLCHAIN_' + toolchain.to_upper(), 1)
mt_conf.set('MT_ARCH_64', cc.sizeof('void *') == 8)

if not is_windows
	add_project_link_arguments('-Wl,--no-as-needed', language: 'c')
endif

# for linux link against dl, for bsd execinfo
if is_linux
	link_lib = 'dl'
elif is_freebsd
	link_lib = 'execinfo'
else
	link_lib = ''
endif

# enable extra warnings and disable any unwanted warnings
warning_flags = [
	# -Wall is added by meson by default, so add -Wextra only
	'-Wextra',

	# additional warnings in alphabetical order
	'-Wcast-qual',
	'-Wdeprecated',
	'-Wformat-nonliteral',
	'-Wformat-security',
	'-Wmissing-declarations',
	'-Wmissing-prototypes',
	'-Wnested-externs',
	'-Wold-style-definition',
	'-Wpointer-arith',
	'-Wsign-compare',
	'-Wstrict-prototypes',
	'-Wundef',
	'-Wwrite-strings',

	# globally disabled warnings
	'-Wno-address-of-packed-member',
	'-Wno-packed-not-aligned',
	'-Wno-missing-field-initializers'
]

if not mt_conf.get('MT_ARCH_64')
# for 32-bit, don't warn about casting a 32-bit pointer to 64-bit int - it's fine!!
	warning_flags += '-Wno-pointer-to-int-cast'
endif

foreach arg: warning_flags
	if cc.has_argument(arg)
		add_project_arguments(arg, language: 'c')
	endif
endforeach

add_project_link_arguments('-pthread', language: 'c')
add_project_link_arguments('-lm', language: 'c')

# Feature Macros
mt_conf.set('MT_FOO_SUPPORT', true)
mt_conf.set('MT_BOO_SUPPORT', false)
