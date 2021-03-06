/*
 * Copyright (C) 2014 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdbool.h>

#include "minui.h"

typedef struct minui_backend {
	/* Initializes the backend and returns a gr_surface to draw into. */
	gr_surface (*init)(struct minui_backend *backend, bool blank);

	/* Causes the current drawing surface (returned by the most recent
	 * call to flip() or init()) to be displayed, and returns a new
	 * drawing surface. */
	gr_surface (*flip)(struct minui_backend *backend);

	/* Blank (or unblank) the screen. */
	void (*blank)(struct minui_backend *backend, bool blank);

	/* Device cleanup when drawing is done. */
	void (*exit)(struct minui_backend *backend);

	/* Save screen content to internal buffer. */
	void (*save)(struct minui_backend *backend);

	/* Restore screen content from internal buffer. */
	void (*restore)(struct minui_backend *backend);
} minui_backend;

#if WITH_FBDEV
minui_backend *open_fbdev(void);
#endif /* WITH_FBDEV */
#if WITH_ADF
minui_backend *open_adf(void);
#endif /* WITH_ADF */
#if WITH_DRM
minui_backend *open_drm(void);
#endif /* WITH_DRM */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _GRAPHICS_H_ */
