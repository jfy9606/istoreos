
include $(TOPDIR)/rules.mk

PKG_NAME:=mali-csf-firmware
PKG_VERSION:=g18p0-01eac0
PKG_RELEASE:=1

PKG_SOURCE_VERSION:=ca33693a03b2782edc237d1d3b786f94849bed7d
PKG_HASH:=122f1ecc14d2de0fe93fc025f8c77e4531abd004fa172ffe69e40cd7d15d5c66
PKG_SOURCE_URL_FILE:=mali_csffw.bin
PKG_SOURCE:=mali_csffw-$(PKG_VERSION).bin
PKG_SOURCE_URL:=https://raw.githubusercontent.com/JeffyCN/mirrors/$(PKG_SOURCE_VERSION)/firmware/g610/

PKG_MAINTAINER:=jjm2473 <jjm2473@gmail.com>

include $(INCLUDE_DIR)/package.mk

define Package/mali-csf-firmware
  SECTION:=firmware
  CATEGORY:=Firmware
  TITLE:=Mali CSF firmware
  DEPENDS:=@TARGET_rockchip
  HIDDEN:=1
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
endef

define Build/Compile

endef

define Package/mali-csf-firmware/install
	$(INSTALL_DIR) $(1)/lib/firmware
	$(INSTALL_DATA) $(DL_DIR)/$(PKG_SOURCE) $(1)/lib/firmware/$(PKG_SOURCE_URL_FILE)
endef

$(eval $(call BuildPackage,mali-csf-firmware))
