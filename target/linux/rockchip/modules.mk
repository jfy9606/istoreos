
define KernelPackage/iio-rockchip-saradc
  TITLE:= Rockchip SARADC driver
  DEPENDS:=@TARGET_rockchip
  KCONFIG:=CONFIG_ROCKCHIP_SARADC
  FILES:=$(LINUX_DIR)/drivers/iio/adc/rockchip_saradc.ko
  AUTOLOAD:=$(call AutoProbe,rockchip_saradc)
  $(call AddDepends/iio,+kmod-industrialio-triggered-buffer)
endef
define KernelPackage/iio-rockchip-saradc/description
 Driver for the Rockchip SARADC.
endef

$(eval $(call KernelPackage,iio-rockchip-saradc))
