project(
	'android-minui',
	'c',
	version: '0.0.1'
)

sources = [
	'events.c',
	'graphics.c',
	'resources.c',
]

headers = [
	'minui.h'
]

dependencies = [
	dependency('libpng', required: true),
]

add_project_arguments('-D_GNU_SOURCE', language: 'c')

fbdev_feature = get_option('with-fbdev')
if not fbdev_feature.disabled()
	sources += ['graphics_fbdev.c']
	add_project_arguments('-DWITH_FBDEV=1', language: ['c'])
endif

libdrm_dep = dependency('libdrm', required: get_option('with-drm'))
if libdrm_dep.found()
	dependencies += [libdrm_dep]
	sources += ['graphics_drm.c']
	add_project_arguments('-DWITH_DRM=1', language: ['c'])
endif

libadf_dep = dependency('libadf', required: get_option('with-adf'))
if libadf_dep.found()
	dependencies += [libadf_dep]
	sources += ['graphics_adf.c']
	add_project_arguments('-DWITH_ADF=1', language: ['c'])
endif

library(
	'minui',
	sources: sources,
	dependencies: dependencies,
	version: meson.project_version(),
	soversion: '0',
	install: true
)

pkg = import('pkgconfig')
pkg.generate(
	name: 'minui',
	libraries: ['-lminui'],
	version: meson.project_version(),
	description: 'Android minui',
	subdirs: ['minui']
)

install_headers(headers, subdir: 'minui')

