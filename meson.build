project('Data Structures and Algorithms', 'c', 'cpp',
  version : '0.1',
  default_options : ['c_std=c89', 'cpp_std=c++17', 'warning_level=3'])

message('meson.build file find successfully in: ' + meson.current_source_dir())

cmake = import('cmake')
catch2_proj = cmake.subproject('Catch2')
catch2_dep = catch2_proj.dependency('Catch2')

subdir('Homework1')
