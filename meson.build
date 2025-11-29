cc = meson.get_compiler('c')
userland_c_flags = ['-nostdlib', '-ffreestanding']

ilibc_sources = files(
  'src/c/stdio.c',
  'src/c/string.c',
  'src/c/unistd.c',
  'src/c/time.c',
  'src/c/signal.c',
  'src/c/stdlib.c',
)

nasm = find_program('nasm')

crt0_o = custom_target('crt0.o',
  input: 'src/asm/crt0.asm',
  output: 'crt0.o',
  command: [nasm, '-felf64', '@INPUT@', '-o', '@OUTPUT@'],
)

syscall_o = custom_target('syscall.o',
  input: 'src/asm/syscall.asm',
  output: 'syscall.o',
  command: [nasm, '-felf64', '@INPUT@', '-o', '@OUTPUT@'],
)

libilibc = static_library('ilibc',
  sources: ilibc_sources + [syscall_o],
  include_directories: include_directories('include'),
  c_args: userland_c_flags,
  pic: false,
)

crt0 = declare_dependency(
  sources: [crt0_o],
  include_directories: include_directories('include'),
)

