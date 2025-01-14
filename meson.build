project(
    'yc-libvhost-server', 'c'
)

libvhost_log_verbosity = 'LOG_INFO'

libvhost_includes = include_directories(
    'include'
)

libvhost_sources = files([
    'blockdev.c',
    'event.c',
    'fs.c',
    'logging.c',
    'memlog.c',
    'memmap.c',
    'server.c',
    'vdev.c',
    'virtio/virtio_blk.c',
    'virtio/virtio_fs.c',
    'virtio/virt_queue.c'
])

libvhost_args = [
    '-Wall',
    '-Werror',
    '-Wextra',
    '-Wno-unused-parameter',
    '-g',
    '-O2',
]

cc = meson.get_compiler('c')

if cc.get_id() == 'gcc'
    libvhost_args += [
        '-Wno-error=unused-value',
        '-Wno-error=unused-result',
        '-Wno-error=strict-aliasing',
    ]
endif

libvhost_optional_args = cc.get_supported_arguments(
    '-Wmissing-prototypes',
    '-Wmissing-variable-declarations',
    '-Wzero-length-array',
    '-Wzero-length-bounds',
)

libvhost_defines = [
    '-D_GNU_SOURCE',
    '-DLOG_VERBOSITY=' + libvhost_log_verbosity
]

libvhost = static_library(
    'vhost',
    sources: libvhost_sources,
    include_directories: libvhost_includes,
    c_args: libvhost_args + libvhost_optional_args + libvhost_defines,
)

subdir('tests')
