/*
 * Global header file for netinfo library
 *
 * Copyright (C) 2009-2012 Olaf Kirch <okir@suse.de>
 */

#ifndef __WICKED_CONSTANTS_H__
#define __WICKED_CONSTANTS_H__

/*
 * Address configuration modes
 */
typedef enum ni_addrconf_mode {
	NI_ADDRCONF_DHCP,
	NI_ADDRCONF_STATIC,
	NI_ADDRCONF_AUTOCONF,

	/* many interface types such as PPP, OpenVPN and iBFT use an
	 * intrinsic addrconf mechanism. We do not provide any services
	 * exposing these mechanisms, but we still want to be able to
	 * tag the ownership properly.
	 */
	NI_ADDRCONF_INTRINSIC,

	__NI_ADDRCONF_MAX
} ni_addrconf_mode_t;

/*
 * Interface flags
 */
enum {
	NI_IFF_DEVICE_UP		= 0x0001,
	NI_IFF_LINK_UP			= 0x0002,
	NI_IFF_POWERSAVE		= 0x0004,
	NI_IFF_NETWORK_UP		= 0x0008,
	NI_IFF_POINT_TO_POINT		= 0x0010,
	NI_IFF_ARP_ENABLED		= 0x0020,
	NI_IFF_BROADCAST_ENABLED	= 0x0040,
	NI_IFF_MULTICAST_ENABLED	= 0x0080,
};

/*
 * Interface types
 */
typedef enum ni_iftype {
	NI_IFTYPE_UNKNOWN = 0,
	NI_IFTYPE_LOOPBACK,
	NI_IFTYPE_ETHERNET,
	NI_IFTYPE_BRIDGE,
	NI_IFTYPE_BOND,
	NI_IFTYPE_VLAN,
	NI_IFTYPE_WIRELESS,
	NI_IFTYPE_INFINIBAND,
	NI_IFTYPE_INFINIBAND_CHILD,
	NI_IFTYPE_PPP,
	NI_IFTYPE_SLIP,
	NI_IFTYPE_SIT,
	NI_IFTYPE_GRE,
	NI_IFTYPE_ISDN,
	NI_IFTYPE_TUNNEL,	/* ipip tunnel */
	NI_IFTYPE_TUNNEL6,	/* ip6ip6 tunnel */
	NI_IFTYPE_TOKENRING,
	NI_IFTYPE_FIREWIRE,

	NI_IFTYPE_TUN,
	NI_IFTYPE_TAP,
	NI_IFTYPE_DUMMY,

	__NI_IFTYPE_MAX
} ni_iftype_t;

/*
 * rfkill types
 */
typedef enum {
	NI_RFKILL_TYPE_WIRELESS,
	NI_RFKILL_TYPE_BLUETOOTH,
	NI_RFKILL_TYPE_MOBILE,

	__NI_RFKILL_TYPE_MAX
} ni_rfkill_type_t;

/*
 * Modem types
 */
typedef enum ni_modem_type {
	MM_MODEM_TYPE_UNKNOWN = 0,
	MM_MODEM_TYPE_GSM = 1,
	MM_MODEM_TYPE_CDMA = 2,

	__MM_MODEM_TYPE_MAX,
} ni_modem_type_t;

/*
 * Events generated by the rtnetlink layer, and translated
 * by us.
 */
typedef enum ni_event {
	NI_EVENT_DEVICE_CREATE = 0,
	NI_EVENT_DEVICE_DELETE,
	NI_EVENT_DEVICE_UP,
	NI_EVENT_DEVICE_DOWN,
	NI_EVENT_LINK_ASSOCIATED,	/* wireless */
	NI_EVENT_LINK_ASSOCIATION_LOST,	/* wireless */
	NI_EVENT_LINK_SCAN_UPDATED,	/* wireless */
	NI_EVENT_LINK_UP,
	NI_EVENT_LINK_DOWN,
	NI_EVENT_NETWORK_UP,
	NI_EVENT_NETWORK_DOWN,
	NI_EVENT_ADDRESS_ACQUIRED,
	NI_EVENT_ADDRESS_RELEASED,
	NI_EVENT_ADDRESS_LOST,
	NI_EVENT_ADDRESS_UPDATE,
	NI_EVENT_ADDRESS_DELETE,
	NI_EVENT_PREFIX_UPDATE,
	NI_EVENT_PREFIX_DELETE,
	NI_EVENT_RDNSS_UPDATE,
	NI_EVENT_RESOLVER_UPDATED,

	__NI_EVENT_MAX
} ni_event_t;

typedef enum {
	NI_SUCCESS = 0,

	NI_ERROR_GENERAL_FAILURE,
	NI_ERROR_RETRY_OPERATION,

	NI_ERROR_INVALID_ARGS,
	NI_ERROR_PERMISSION_DENIED,
	NI_ERROR_DOCUMENT_ERROR,

	NI_ERROR_DEVICE_NOT_KNOWN,
	NI_ERROR_DEVICE_BAD_HIERARCHY,
	NI_ERROR_DEVICE_IN_USE,
	NI_ERROR_DEVICE_NOT_UP,
	NI_ERROR_DEVICE_NOT_DOWN,
	NI_ERROR_DEVICE_NOT_COMPATIBLE,
	NI_ERROR_DEVICE_EXISTS,

	NI_ERROR_AUTH_INFO_MISSING,

	NI_ERROR_ADDRCONF_NO_LEASE,

	NI_ERROR_CANNOT_CONFIGURE_DEVICE,
	NI_ERROR_CANNOT_CONFIGURE_ADDRESS,
	NI_ERROR_CANNOT_CONFIGURE_ROUTE,

	NI_ERROR_DBUS_CALL_FAILED,
	NI_ERROR_CANNOT_MARSHAL,
	NI_ERROR_SERVICE_UNKNOWN,
	NI_ERROR_METHOD_NOT_SUPPORTED,
	NI_ERROR_METHOD_CALL_TIMED_OUT,
	NI_ERROR_PROPERTY_NOT_PRESENT,

	NI_ERROR_UNRESOLVABLE_HOSTNAME,
	NI_ERROR_UNREACHABLE_ADDRESS,

	NI_ERROR_POLICY_EXISTS,
	NI_ERROR_RADIO_DISABLED,

	__NI_ERROR_MAX
} ni_error_t;

#endif /* __WICKED_CONSTANTS_H__ */
