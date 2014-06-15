#ifndef __AC_NLSMARTCAPWAP_HEADER__
#define __AC_NLSMARTCAPWAP_HEADER__

/* */
#define SMARTCAPWAP_AC_GENL_NAME			"smartcapwap_ac"

/* */
enum nlsmartcapwap_ac_attrs {
	NLSMARTCAPWAP_AC_ATTR_UNSPEC,

	NLSMARTCAPWAP_AC_ATTR_FLAGS,

	/* Last attribute */
	__NLSMARTCAPWAP_AC_ATTR_AFTER_LAST,
	NLSMARTCAPWAP_AC_ATTR_MAX = __NLSMARTCAPWAP_AC_ATTR_AFTER_LAST - 1
};

/* */
enum nlsmartcapwap_ac_commands {
	NLSMARTCAPWAP_AC_CMD_UNSPEC,

	NLSMARTCAPWAP_AC_CMD_LINK,

	/* Last command */
	__NLSMARTCAPWAP_AC_CMD_AFTER_LAST,
	NLSMARTCAPWAP_AC_CMD_MAX = __NLSMARTCAPWAP_AC_CMD_AFTER_LAST - 1
};

#endif /* __AC_NLSMARTCAPWAP_HEADER__ */
