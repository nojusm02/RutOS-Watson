include $(TOPDIR)/rules.mk

PKG_NAME:=watson-sender
PKG_RELEASE:=1
PKG_VERSION:=1.0.0

include $(INCLUDE_DIR)/package.mk

define Package/watson-sender
	CATEGORY:=Base system
	TITLE:=watson-sender
	DEPENDS:= +libuci +libiotp_device +libubus +libubox +libblobmsg-json
endef

define Package/watson-sender/description
	IBM Watson data sender
endef

define Package/watson-sender/install
	$(INSTALL_DIR) $(1)/usr/bin $(1)/etc/init.d $(1)/etc/config
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/watson-sender $(1)/usr/bin/
	$(INSTALL_BIN) ./files/watson-sender.init $(1)/etc/init.d/watson-sender
	$(INSTALL_CONF) ./files/watson-sender.config $(1)/etc/config/watson-sender
endef

$(eval $(call BuildPackage,watson-sender))
