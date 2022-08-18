#ifndef _LINUX_LINUX_MMI_H_
#define _LINUX_LINUX_MMI_H_

/**
 * Controls the platform MMI interface implementation for linux and SDL2
 * display.
 */

void linuxmmi_init(void);
void linuxmmi_main_loop(void);
void linuxmmi_cleanup(void);

#endif
