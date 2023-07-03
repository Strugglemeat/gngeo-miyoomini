
#ifndef WLAN_API_H
#define WLAN_API_H

#ifdef __cplusplus
	extern "C" {
#endif
/*----------------- macro define --------------------*/
#define SSID_MAX_LEN 32
#define KEY_MAX_LEN 63
#define ETH_ALEN 6
#define AUTO_CHANNEL 0
#define MAX_2G_AUTO_CHANNEL 13 // Auto channel of 2.4G is chose in channel 1 - 13, not includes channel 14
#define MAX_2G_CHANNEL  13
#define MAX_5G_CHANNEL  165

typedef enum
{
	WIFI_SECURITY_OPEN,
	WIFI_SECURITY_WPA,
    WIFI_SECURITY_WEP_PSK,
    WIFI_SECURITY_WEP_SHARED,
    WIFI_SECURITY_UNKNOWN
} T_WIFI_SECURITY;

typedef struct
{
	char    isConnect;  /* 0: wifi disconnected with ap.  1: wifi connected with ap */
    char	ssid[SSID_MAX_LEN + 1]; /* ap's ssid */
    char	ap_mac_addr[ETH_ALEN + 1];  /* ap's mac address */
    double	freq;	    //e.g.  2.462 GHz
    int    channel;
	int    signal_value;    //e.g.  -40 dBm
    int    signal_level;  /* 0: no signal, 1: Poor, 2: Fair, 3: Good, 4: Execllent */
	T_WIFI_SECURITY  security_mode;
	char password[KEY_MAX_LEN + 1];
} T_WIFI_INFO;

typedef struct
{
	unsigned ip_addr;
	unsigned netmask;
	unsigned gateway;
	unsigned primaryDNS;
	unsigned backupDNS;
	char mac_addr[ETH_ALEN + 1];
} T_IP_INFO;

/*--------------------------------- Extern definition ------------------------------*/

/******************************************************************
Function   : print_ip_info()
Description: print the ip info
Parameter  : ip: the struct that store the ip info
Return     : None
******************************************************************/
extern void print_ip_info(const T_IP_INFO *ip);

/*********************************************************************
Function   : wifi_api_init
Description: Allocate resources and search wlan card.
Parameter  : None
Return     : 0: Success
             -1: Fail
*********************************************************************/
extern int wifi_api_init(void);

/*********************************************************************
Function   : wifi_api_deinit
Description: Release resources.
Parameter  : None
Return     : None
*********************************************************************/
extern void wifi_api_deinit(void);

/*************************************************************
Function   : wifi_scan
Description: Scan wireless network. Then store the ap information to a list.
Parameter  : scan_list: return the scan result.
             apnum: return the ap number in the scan result.
Return     : 0: Successfully scan wireless network. If the returned "apnum" parameter is 0, it means not found any ap.
             -1: Error occur when scan wireless network.
**************************************************************/
extern int wifi_scan(T_WIFI_INFO **scan_list, int *apnum);

/****************************************************************
Function   : wifi_set_ssid
Description: Set the ssid of ap which wifi want to connect.
Parameter  : ap: return the information of ap which the wifi want to connect.
             ssid: the ssid of ap. It will be saved to the "ap" parameter.
Return     : None
****************************************************************/
extern void wifi_set_ssid(T_WIFI_INFO *ap, const char *ssid);

/****************************************************************
Function   : wifi_set_security_mode
Description: Set the security mode of ap which wifi want to connect.
Parameter  : ap: return the information of ap which the wifi want to connect.
             mode: the security mode of ap. The security mode includes open, wpa and wep. It will be saved to the "ap" parameter.
Return     : None
****************************************************************/
extern void wifi_set_security_mode(T_WIFI_INFO *ap, const T_WIFI_SECURITY mode);

/****************************************************************
Function   : wifi_set_password
Description: Set the password of ap which wifi want to connect.
Parameter  : ap: return the information of ap which the wifi want to connect.
             pwd: the password of ap. It will be saved to the "ap" parameter.
Return     : None
****************************************************************/
extern void wifi_set_password(T_WIFI_INFO *ap, const char *pwd);

/*************************************************************
Function   : wifi_connect_ap
Description: Connect an ap
Parameter  : ap: the information of the ap which the wifi want to connect.
                 The information includes the ap's ssid, security mode and password.
Return     : 0: Successfully connect ap
             -1��Failed to connect ap
**************************************************************/
extern int wifi_connect_ap(const T_WIFI_INFO *ap);

/****************************************************************
Function    : wifi_disconnect
Description : Wifi disconnected with ap
Parameter   : None
Return      : 0: wifi successfully disconnect with ap
             -1: wifi fail to disconnect with ap
****************************************************************/
extern int wifi_disconnect(void);

/*************************************************************
Function   : wifi_check_associated
Description: Check whether the wifi is connected with an ap
Parameter  : None
Return     : 0: wifi is NOT connected with any ap
             1��wifi is connected with an ap
**************************************************************/
extern int wifi_check_associated(void);

/*************************************************************
Function   : wifi_get_status
Description: Get the wifi status
Parameter  : wifi: return the wifi information.
                   The information includes the ap's ssid, the ap's mac address, channel, signal level and so on
Return     : 0: Successfully get wifi status.
			-1: Fail to get wifi status.
**************************************************************/
extern int wifi_get_status(T_WIFI_INFO *wifi);

/***************************************************************************
Function    : wifi_dhcp_client_start
Description	: Run dhcp client daemon to obtain ip address, gateway and dns.
Parameter   : ip: return the ip information. The information includes the ip address, gateway and dns.
Return      : 0: Successfully obtain ip address, gateway and dns using dhcp client.
             -1: Fail to obtain ip address, gateway and dns.
***************************************************************************/
extern int wifi_dhcp_client_start(T_IP_INFO *ip);

/****************************************************************
Function    : wifi_dhcp_client_stop
Description : Stop dhcp client daemon
Parameter   : None
Return      : 0: Successfully stop dhcp client daemon
             -1: Fail to stop dhcp client daemon
****************************************************************/
extern int wifi_dhcp_client_stop(void);

/*************************************************************
Function   : wifi_get_ip_info()
Description: Get wifi IP info, e.g. IP Address,Netmask....
Parameter  : ip: the pointer of if_info struct, it store the IP info
Return     : 0: success
            -1: fail to get the info
**************************************************************/
extern int wifi_get_ip_info(T_IP_INFO *ip);

/****************************************************************
Function   : softap_set_ssid
Description: Set the ssid of softap
Parameter  : softap: return the information of softap.
             ssid: the ssid of softap. It will be saved to the "softap" parameter.
Return     : None
****************************************************************/
extern void softap_set_ssid(T_WIFI_INFO *softap, const char *ssid);

/****************************************************************
Function   : softap_set_password
Description: Set the password of softap.
Parameter  : softap: return the information of softap.
             pwd: the password of softap. It will be saved to the "softap" parameter.
             If the password parameter is "NULL", the softap is open system without encryption.
             Otherwise the softap is WPA2-PSK authentication with AES encryption.
Return     : None
****************************************************************/
extern void softap_set_password(T_WIFI_INFO *softap, const char *pwd);

/****************************************************************
Function   : softap_set_channel
Description: Set the channel of softap.
Parameter  : softap: return the information of softap.
             channel: the channel of softap. It will be saved to the "softap" parameter.
             If the channel is auto (AUTO_CHANNEL), the softap will scan the ap nearby and using the less occupied channel by the ap nearby.
Return     : None
****************************************************************/
extern void softap_set_channel(T_WIFI_INFO *softap, const int channel);

/****************************************************************
Function   : softap_set_5G_channel
Description: Set the 5G channel of softap.
Parameter  : softap: return the information of softap.
             channel: the channel of softap. It will be saved to the "softap" parameter.
             If the channel is auto (AUTO_CHANNEL), the softap will scan the 5G ap nearby and using the less occupied channel by the 5G ap nearby.
Return     : None
****************************************************************/
extern void softap_set_5G_channel(T_WIFI_INFO *softap, const int channel);

/****************************************************************
Function   : softap_start
Description: Start softap
Parameter  : softap: the information of softap.
Return     : 0: Successfully start softap
             -1��Failed to start softap
****************************************************************/
extern int softap_start(const T_WIFI_INFO *softap);

/****************************************************************
Function   : softap_stop
Description: Stop softap
Parameter  : None
Return      : 0: Successfully stop softap
             -1: Fail to stop softap
****************************************************************/
extern int softap_stop(void);

/****************************************************************
Function   : softap_restart
Description: Firstly stop the softap. Then start the softap.
Parameter  : softap: the information of softap.
Return     : 0: Successfully restart softap
             -1��Failed to restart softap
****************************************************************/
extern int softap_restart(const T_WIFI_INFO *softap);

/***************************************************************************
Function    : softap_dhcp_server_start
Description	: Run the dhcp server daemon
Parameter   : local_ip_addr: the ip address of dhcp server.
Return      : 0: Successfully start dhcp server
             -1: Fail to start dhcp server
***************************************************************************/
extern int softap_dhcp_server_start(const unsigned local_ip_addr);

/***************************************************************************
Function    : softap_dhcp_server_stop
Description	: Stop the dhcp server daemon
Parameter   : None
Return      : 0: Successfully stop dhcp server
             -1: Fail to stop dhcp server
***************************************************************************/
extern int softap_dhcp_server_stop(void);

/***************************************************************************
Function    : softap_dhcp_server_restart
Description	: Firstly stop the dhcp server daemon. Then start the dhcp server daemon.
Parameter   : local_ip_addr_str: the ip address of dhcp server.
Return      : 0: Successfully restart dhcp server
             -1: Fail to restart dhcp server
***************************************************************************/
extern int softap_dhcp_server_restart(const unsigned local_ip_addr);

/*************************************************************
Function   : get_ip_addr()
Description: get ip addr
Parameter  : ifname: network interface name
			 p_ip_addr: returned ip address
Return     : 0: success to get the ip address
            -1: fail to get the ip address
**************************************************************/
extern int get_ip_addr(const char *ifname,  unsigned *p_ip_addr);

/*************************************************************
Function   : get_ip_info()
Description: get ip info, e.g. ip address, netmask....
Parameter  : ifname: network interface name
			 ip: returned ip info
Return     : 0: success
            -1: fail to get the info
**************************************************************/
extern int get_ip_info(const char *ifname, T_IP_INFO *ip);

#ifdef __cplusplus
  }
#endif

#endif // WLAN_API_H

