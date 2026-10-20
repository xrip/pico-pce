#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define PCE_PSRAM_BASE ((uintptr_t)0x11000000u)
#define PCE_PSRAM_MAX_SIZE (16u * 1024u * 1024u)

#ifdef __cplusplus
extern "C" {
#endif

bool pce_psram_init(void);
bool pce_psram_available(void);
size_t pce_psram_size(void);
int pce_psram_cs1_gpio(void);
void pce_psram_prepare_reset(void);
void pce_psram_reclock(void); /* after every clk_sys change */

/* Ctrl+Alt+Del and all other watchdog resets use the same safe path. */
void pce_safe_reset(void);

#ifdef __cplusplus
}
#endif
