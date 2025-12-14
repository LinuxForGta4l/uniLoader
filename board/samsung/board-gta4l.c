/* SPDX-License-Identifier: GPL-2.0 */

#include <board.h>
#include <drivers/framework.h>
#include <lib/simplefb.h>

#ifdef CONFIG_SIMPLE_FB
static struct video_info gta4l_fb = {
	.format = FB_FORMAT_ARGB8888,
	.width = 1200,
	.height = 2000,
	.stride = 4,
	.address = (void *)0x5c000000
};
#endif

int gta4l_drv(void)
{
#ifdef CONFIG_SIMPLE_FB
	REGISTER_DRIVER("simplefb", simplefb_probe, &gta4l_fb);
#endif
	return 0;
}

struct board_data board_ops = {
	.name = "samsung-gta4l",
	.ops = {
		.drivers_init = gta4l_drv
	},
	.quirks = 0
};
