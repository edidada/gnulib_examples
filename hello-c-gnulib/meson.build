project('hello-c-gnulib', 'c', version: '0', default_options: ['c_std=c11'])

gnulib_inc = include_directories('.')

gnulib_sources = []
if run_command('test', '-d', meson.source_root() / 'lib').success()
    gnulib_sources = files(
        'lib/get_ppid_of.c',
        'lib/stdio.c',
        'lib/stdlib.c',
        'lib/unistd.c',
    )
else
    warning('Gnulib sources not found. Run autogen.sh first.')
endif

gnulib_lib = static_library('gnulib', gnulib_sources, include_directories: gnulib_inc)

executable('hello', 'hello.c', include_directories: gnulib_inc, link_with: gnulib_lib)
