include $(TOPDIR)/rules.mk

PKG_NAME:=ubox
PKG_FLAGS:=hold
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL=$(PROJECT_GIT)/project/ubox.git
PKG_SOURCE_DATE:=2024-04-26
PKG_SOURCE_VERSION:=85f1053019caf4cd333795760950235ee4529ba7
PKG_MIRROR_HASH:=9e3fb6ab94854405fb91626a673b0547a061582c552ce719691be1bc8818da6c
CMAKE_INSTALL:=1

PKG_LICENSE:=GPL-2.0
PKG_LICENSE_FILES:=

PKG_MAINTAINER:=John Crispin <john@phrozen.org>

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/ubox
  SECTION:=base
  CATEGORY:=Base system
  DEPENDS:=+libubox +ubusd +ubus +libubus +libuci
  TITLE:=OpenWrt system helper toolbox
  ALTERNATIVES:=\
    100:/sbin/rmmod:/sbin/kmodloader \
    100:/sbin/insmod:/sbin/kmodloader \
    100:/sbin/lsmod:/sbin/kmodloader \
    100:/sbin/modinfo:/sbin/kmodloader \
    100:/sbin/modprobe:/sbin/kmodloader
endef

define Package/ubox/conffiles
/etc/modules.conf
endef

define Package/getrandom
  SECTION:=base
  CATEGORY:=Base system
  TITLE:=OpenWrt getrandom system helper
endef

define Package/logd
  SECTION:=base
  CATEGORY:=Base system
  DEPENDS:=+libubox +libubus +libblobmsg-json +libudebug
  TITLE:=OpenWrt system log implementation
  USERID:=logd=514:logd=514
  ALTERNATIVES:=200:/sbin/logread:/usr/libexec/logread-ubox
endef

define Package/getrandom/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/getrandom $(1)/usr/bin/
endef

define Package/ubox/install
	$(INSTALL_DIR) $(1)/sbin $(1)/usr/sbin $(1)/lib $(1)/usr/bin $(1)/etc

	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/sbin/{kmodloader,validate_data} $(1)/sbin/
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/lib/libvalidate.so $(1)/lib
	$(INSTALL_DATA) ./files/modules.conf $(1)/etc/modules.conf
endef

define Package/logd/install
	$(INSTALL_DIR) $(1)/sbin $(1)/usr/libexec/ $(1)/etc/init.d/ $(1)/usr/share/acl.d

	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/sbin/logd $(1)/sbin/
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/sbin/logread $(1)/usr/libexec/logread-ubox
	$(INSTALL_BIN) ./files/log.init $(1)/etc/init.d/log
	$(INSTALL_DATA) ./files/logd.json $(1)/usr/share/acl.d
endef

$(eval $(call BuildPackage,ubox))
$(eval $(call BuildPackage,getrandom))
$(eval $(call BuildPackage,logd))
