project('noto', 'c',
  version : '1.0.0',
  default_options : [
    'warning_level=3',
    'werror=true',         # Treat all warnings as errors
    'c_std=c2x',           # Use latest C standard
    'b_ndebug=if-release', # Strip assert() in release builds
  ]
)

# All source files from src/
noto_sources = [
  'src/main.c',
  'src/create_entry.c',
  'src/create_new_db.c',
  'src/delete_line.c',
  'src/generate_hash.c',
  'src/get_path_to_db.c',
  'src/remove_entry.c',
  'src/show_all.c',
  'src/show_entry.c'
]

# Include directory for headers
inc = include_directories('include')

# Build the executable
noto = executable('noto',
  noto_sources,
  include_directories : inc,
  install : true,

  c_args : [
    '-Wall',
    '-Wextra',
    '-Wpedantic',
    '-Wshadow',
    '-Wconversion',
    '-Wsign-conversion',
    '-Wnull-dereference',
    '-Wdouble-promotion',
    '-Wformat=2',
    '-Wformat-overflow=2',
    '-Wformat-truncation=2',
    '-Wundef',
    '-Wswitch-default',
    '-Wswitch-enum',

    # Security hardening (requires -O1 or higher)
    '-D_FORTIFY_SOURCE=2',
    '-fstack-protector-strong',

    # Optimization
    '-O2',              # Or -O3 for even more speed if desired
    # '-march=native',  # Uncomment if building only for this machine
  ],

  link_args : [
    '-s',                # Strip debugging symbols for smaller binary
    '-Wl,--gc-sections', # Remove unused code and data
  ]
)

# Basic smoke test - just runs the binary
test('smoke test', noto)