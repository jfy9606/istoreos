include $(TOPDIR)/rules.mk

PKG_NAME:=r8168
PKG_VERSION:=8.055.00
PKG_RELEASE:=3

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=https://github.com/openwrt/rtl8168/releases/download/$(PKG_VERSION)
PKG_HASH:=61deb2a9cb7d6b08748ad51734b108da95d629712b64b204e2e6bd3f16d0a48f

PKG_BUILD_PARALLEL:=1
PKG_LICENSE:=GPLv2
PKG_MAINTAINER:=Alvaro Fernandez Rojas <noltari@gmail.com>

include $(INCLUDE_DIR)/kernel.mk
include $(INCLUDE_DIR)/package.mk

define KernelPackage/r8168
  SUBMENU:=Network Devices
  TITLE:=Realtek RTL8168 PCI Gigabit Ethernet driver
  DEPENDS:=@PCI_SUPPORT +kmod-libphy
  FILES:=$(PKG_BUILD_DIR)/src/r8168.ko
  AUTOLOAD:=$(call AutoLoad,35,r8168)
  PROVIDES:=kmod-r8169
  VARIANT:=regular
endef

define KernelPackage/r8168/install/dkml
	$(INSTALL_DIR) $(1)/etc/modules-pending.d
	$(LN) ../modules.d/$(filter-out 0-,$(word 1,$(AUTOLOAD))-)$$(NAME) $(1)/etc/modules-pending.d/$$(NAME)
endef

ifeq ($(CONFIG_TARGET_x86),y)
KernelPackage/r8168/install = $(KernelPackage/r8168/install/dkml)
endif

define Package/kmod-r8168/postinst
#!/bin/sh
[ -n "$${IPKG_INSTROOT}" ] || rm -f /etc/modules-pending.d/$(NAME)
endef

define KernelPackage/r8168-rss
$(call KernelPackage/r8168)
  CONFLICTS:=kmod-r8168
  TITLE+= (RSS)
  VARIANT:=rss
endef

ifeq ($(BUILD_VARIANT),rss)
  PKG_MAKE_FLAGS += \
    ENABLE_MULTIPLE_TX_QUEUE=y \
    ENABLE_RSS_SUPPORT=y
endif

define Build/Compile
	+$(KERNEL_MAKE) $(PKG_JOBS) \
		M="$(PKG_BUILD_DIR)/src" \
		modules
endef

$(eval $(call KernelPackage,r8168))
$(eval $(call KernelPackage,r8168-rss))
