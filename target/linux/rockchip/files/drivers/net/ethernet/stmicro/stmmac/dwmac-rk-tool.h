/* SPDX-License-Identifier: (GPL-2.0+ OR MIT) */
/*
 * Copyright (c) 2020 Fuzhou Rockchip Electronics Co., Ltd
 */

#ifndef __DWMAC_RK_TOOL_H__
#define __DWMAC_RK_TOOL_H__

#include <linux/phy.h>
#include "stmmac.h"

void dwmac_rk_set_rgmii_delayline(struct stmmac_priv *priv, int tx_delay, int rx_delay);
void dwmac_rk_get_rgmii_delayline(struct stmmac_priv *priv, int *tx_delay, int *rx_delay);
int dwmac_rk_get_phy_interface(struct stmmac_priv *priv);

int dwmac_rk_create_loopback_sysfs(struct device *dev);
int dwmac_rk_remove_loopback_sysfs(struct device *device);

#endif /* __DWMAC_RK_TOOL_H__ */

