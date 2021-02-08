/**********************************Copyright (c)**********************************
**                       鐗堟潈鎵�鏈� (C), 2015-2020, 娑傞甫绉戞妧
**
**                             http://www.tuya.com
**
*********************************************************************************/
/**
 * @file    mcu_api.h
 * @author  娑傞甫缁煎悎鍗忚寮�鍙戠粍
 * @version v2.5.6
 * @date    2020.12.16
 * @brief   鐢ㄦ埛闇�瑕佷富鍔ㄨ皟鐢ㄧ殑鍑芥暟閮藉湪璇ユ枃浠跺唴
 */

/****************************** 鍏嶈矗澹版槑 锛侊紒锛� *******************************
鐢变簬MCU绫诲瀷鍜岀紪璇戠幆澧冨绉嶅鏍凤紝鎵�浠ユ浠ｇ爜浠呬緵鍙傝�冿紝鐢ㄦ埛璇疯嚜琛屾妸鎺ф渶缁堜唬鐮佽川閲忥紝
娑傞甫涓嶅MCU鍔熻兘缁撴灉璐熻矗銆�
******************************************************************************/

#ifndef __MCU_API_H_
#define __MCU_API_H_


#ifdef MCU_API_GLOBAL
  #define MCU_API_EXTERN
#else
  #define MCU_API_EXTERN   extern
#endif

/**
 * @brief  hex杞琤cd
 * @param[in] {Value_H} 楂樺瓧鑺�
 * @param[in] {Value_L} 浣庡瓧鑺�
 * @return 杞崲瀹屾垚鍚庢暟鎹�
 */
unsigned char hex_to_bcd(unsigned char Value_H,unsigned char Value_L);

/**
 * @brief  姹傚瓧绗︿覆闀垮害
 * @param[in] {str} 瀛楃涓插湴鍧�
 * @return 鏁版嵁闀垮害
 */
unsigned long my_strlen(unsigned char *str);

/**
 * @brief  鎶妔rc鎵�鎸囧唴瀛樺尯鍩熺殑鍓峜ount涓瓧鑺傝缃垚瀛楃c
 * @param[out] {src} 寰呰缃殑鍐呭瓨棣栧湴鍧�
 * @param[in] {ch} 璁剧疆鐨勫瓧绗�
 * @param[in] {count} 璁剧疆鐨勫唴瀛橀暱搴�
 * @return 寰呰缃殑鍐呭瓨棣栧湴鍧�
 */
void *my_memset(void *src,unsigned char ch,unsigned short count);

/**
 * @brief  鍐呭瓨鎷疯礉
 * @param[out] {dest} 鐩爣鍦板潃
 * @param[in] {src} 婧愬湴鍧�
 * @param[in] {count} 鎷疯礉鏁版嵁涓暟
 * @return 鏁版嵁澶勭悊瀹屽悗鐨勬簮鍦板潃
 */
void *my_memcpy(void *dest, const void *src, unsigned short count);

/**
 * @brief  瀛楃涓叉嫹璐�
 * @param[in] {dest} 鐩爣鍦板潃
 * @param[in] {src} 婧愬湴鍧�
 * @return 鏁版嵁澶勭悊瀹屽悗鐨勬簮鍦板潃
 */
char *my_strcpy(char *dest, const char *src);

/**
 * @brief  瀛楃涓叉瘮杈�
 * @param[in] {s1} 瀛楃涓� 1
 * @param[in] {s2} 瀛楃涓� 2
 * @return 澶у皬姣旇緝鍊�
 * -         0:s1=s2
 * -         <0:s1<s2
 * -         >0:s1>s2
 */
int my_strcmp(char *s1 , char *s2);

/**
 * @brief  灏唅nt绫诲瀷鎷嗗垎鍥涗釜瀛楄妭
 * @param[in] {number} 4瀛楄妭鍘熸暟鎹�
 * @param[out] {value} 澶勭悊瀹屾垚鍚�4瀛楄妭鏁版嵁
 * @return Null
 */
void int_to_byte(unsigned long number,unsigned char value[4]);

/**
 * @brief  灏�4瀛楄妭鍚堝苟涓�1涓�32bit鍙橀噺
 * @param[in] {value} 4瀛楄妭鏁扮粍
 * @return 鍚堝苟瀹屾垚鍚庣殑32bit鍙橀噺
 */
unsigned long byte_to_int(const unsigned char value[4]);

/**
 * @brief  raw鍨媎p鏁版嵁涓婁紶
 * @param[in] {dpid} dpid鍙�
 * @param[in] {value} 褰撳墠dp鍊兼寚閽�
 * @param[in] {len} 鏁版嵁闀垮害
 * @return Null
 * @note   Null
 */
unsigned char mcu_dp_raw_update(unsigned char dpid,const unsigned char value[],unsigned short len);

/**
 * @brief  bool鍨媎p鏁版嵁涓婁紶
 * @param[in] {dpid} dpid鍙�
 * @param[in] {value} 褰撳墠dp鍊�
 * @return Null
 * @note   Null
 */
unsigned char mcu_dp_bool_update(unsigned char dpid,unsigned char value);

/**
 * @brief  value鍨媎p鏁版嵁涓婁紶
 * @param[in] {dpid} dpid鍙�
 * @param[in] {value} 褰撳墠dp鍊�
 * @return Null
 * @note   Null
 */
unsigned char mcu_dp_value_update(unsigned char dpid,unsigned long value);

/**
 * @brief  string鍨媎p鏁版嵁涓婁紶
 * @param[in] {dpid} dpid鍙�
 * @param[in] {value} 褰撳墠dp鍊兼寚閽�
 * @param[in] {len} 鏁版嵁闀垮害
 * @return Null
 * @note   Null
 */
unsigned char mcu_dp_string_update(unsigned char dpid,const unsigned char value[],unsigned short len);

/**
 * @brief  enum鍨媎p鏁版嵁涓婁紶
 * @param[in] {dpid} dpid鍙�
 * @param[in] {value} 褰撳墠dp鍊�
 * @return Null
 * @note   Null
 */
unsigned char mcu_dp_enum_update(unsigned char dpid,unsigned char value);

/**
 * @brief  fault鍨媎p鏁版嵁涓婁紶
 * @param[in] {dpid} dpid鍙�
 * @param[in] {value} 褰撳墠dp鍊�
 * @return Null
 * @note   Null
 */
unsigned char mcu_dp_fault_update(unsigned char dpid,unsigned long value);

#ifdef MCU_DP_UPLOAD_SYN
/**
 * @brief  raw鍨媎p鏁版嵁鍚屾涓婁紶
 * @param[in] {dpid} dpid鍙�
 * @param[in] {value} 褰撳墠dp鍊兼寚閽�
 * @param[in] {len} 鏁版嵁闀垮害
 * @return Null
 * @note   Null
 */
unsigned char mcu_dp_raw_update_syn(unsigned char dpid,const unsigned char value[],unsigned short len);

/**
 * @brief  bool鍨媎p鏁版嵁鍚屾涓婁紶
 * @param[in] {dpid} dpid鍙�
 * @param[in] {value} 褰撳墠dp鍊兼寚閽�
 * @return Null
 * @note   Null
 */
unsigned char mcu_dp_bool_update_syn(unsigned char dpid,unsigned char value);

/**
 * @brief  value鍨媎p鏁版嵁鍚屾涓婁紶
 * @param[in] {dpid} dpid鍙�
 * @param[in] {value} 褰撳墠dp鍊兼寚閽�
 * @return Null
 * @note   Null
 */
unsigned char mcu_dp_value_update_syn(unsigned char dpid,unsigned long value);

/**
 * @brief  string鍨媎p鏁版嵁鍚屾涓婁紶
 * @param[in] {dpid} dpid鍙�
 * @param[in] {value} 褰撳墠dp鍊兼寚閽�
 * @param[in] {len} 鏁版嵁闀垮害
 * @return Null
 * @note   Null
 */
unsigned char mcu_dp_string_update_syn(unsigned char dpid,const unsigned char value[],unsigned short len);

/**
 * @brief  enum鍨媎p鏁版嵁鍚屾涓婁紶
 * @param[in] {dpid} dpid鍙�
 * @param[in] {value} 褰撳墠dp鍊兼寚閽�
 * @return Null
 * @note   Null
 */
unsigned char mcu_dp_enum_update_syn(unsigned char dpid,unsigned char value);

/**
 * @brief  fault鍨媎p鏁版嵁鍚屾涓婁紶
 * @param[in] {dpid} dpid鍙�
 * @param[in] {value} 褰撳墠dp鍊兼寚閽�
 * @return Null
 * @note   Null
 */
unsigned char mcu_dp_fault_update_syn(unsigned char dpid,unsigned long value);
#endif

/**
 * @brief  mcu鑾峰彇bool鍨嬩笅鍙慸p鍊�
 * @param[in] {value} dp鏁版嵁缂撳啿鍖哄湴鍧�
 * @param[in] {len} dp鏁版嵁闀垮害
 * @return 褰撳墠dp鍊�
 * @note   Null
 */
unsigned char mcu_get_dp_download_bool(const unsigned char value[],unsigned short len);

/**
 * @brief  mcu鑾峰彇enum鍨嬩笅鍙慸p鍊�
 * @param[in] {value} dp鏁版嵁缂撳啿鍖哄湴鍧�
 * @param[in] {len} dp鏁版嵁闀垮害
 * @return 褰撳墠dp鍊�
 * @note   Null
 */
unsigned char mcu_get_dp_download_enum(const unsigned char value[],unsigned short len);

/**
 * @brief  mcu鑾峰彇value鍨嬩笅鍙慸p鍊�
 * @param[in] {value} dp鏁版嵁缂撳啿鍖哄湴鍧�
 * @param[in] {len} dp鏁版嵁闀垮害
 * @return 褰撳墠dp鍊�
 * @note   Null
 */
unsigned long mcu_get_dp_download_value(const unsigned char value[],unsigned short len);

/**
 * @brief  涓插彛鎺ユ敹鏁版嵁鏆傚瓨澶勭悊
 * @param[in] {value} 涓插彛鏀跺埌鐨�1瀛楄妭鏁版嵁
 * @return Null
 * @note   鍦∕CU涓插彛澶勭悊鍑芥暟涓皟鐢ㄨ鍑芥暟,骞跺皢鎺ユ敹鍒扮殑鏁版嵁浣滀负鍙傛暟浼犲叆
 */
void uart_receive_input(unsigned char value);

/**
 * @brief  涓插彛鎺ユ敹澶氫釜瀛楄妭鏁版嵁鏆傚瓨澶勭悊
 * @param[in] {value} 涓插彛瑕佹帴鏀剁殑鏁版嵁鐨勬簮鍦板潃
 * @param[in] {data_len} 涓插彛瑕佹帴鏀剁殑鏁版嵁鐨勬暟鎹暱搴�
 * @return Null
 * @note   濡傞渶瑕佹敮鎸佷竴娆″瀛楄妭缂撳瓨锛屽彲璋冪敤璇ュ嚱鏁�
 */
void uart_receive_buff_input(unsigned char value[], unsigned short data_len);

/**
 * @brief  wifi涓插彛鏁版嵁澶勭悊鏈嶅姟
 * @param  Null
 * @return Null
 * @note   鍦∕CU涓诲嚱鏁皐hile寰幆涓皟鐢ㄨ鍑芥暟
 */
void wifi_uart_service(void);

/**
 * @brief  鍗忚涓插彛鍒濆鍖栧嚱鏁�
 * @param  Null
 * @return Null
 * @note   鍦∕CU鍒濆鍖栦唬鐮佷腑璋冪敤璇ュ嚱鏁�
 */
void wifi_protocol_init(void);

#ifndef WIFI_CONTROL_SELF_MODE
/**
 * @brief  MCU鑾峰彇澶嶄綅wifi鎴愬姛鏍囧織
 * @param  Null
 * @return 澶嶄綅鏍囧織
 * -           0(RESET_WIFI_ERROR):澶辫触
 * -           1(RESET_WIFI_SUCCESS):鎴愬姛
 * @note   1:MCU涓诲姩璋冪敤mcu_reset_wifi()鍚庤皟鐢ㄨ鍑芥暟鑾峰彇澶嶄綅鐘舵��
 *         2:濡傛灉涓烘ā鍧楄嚜澶勭悊妯″紡,MCU鏃犻』璋冪敤璇ュ嚱鏁�
 */
unsigned char mcu_get_reset_wifi_flag(void);

/**
 * @brief  MCU涓诲姩閲嶇疆wifi宸ヤ綔妯″紡
 * @param  Null
 * @return Null
 * @note   1:MCU涓诲姩璋冪敤,閫氳繃mcu_get_reset_wifi_flag()鍑芥暟鑾峰彇閲嶇疆wifi鏄惁鎴愬姛
 *         2:濡傛灉涓烘ā鍧楄嚜澶勭悊妯″紡,MCU鏃犻』璋冪敤璇ュ嚱鏁�
 */
void mcu_reset_wifi(void);

/**
 * @brief  鑾峰彇璁剧疆wifi鐘舵�佹垚鍔熸爣蹇�
 * @param  Null
 * @return wifimode flag
 * -           0(SET_WIFICONFIG_ERROR):澶辫触
 * -           1(SET_WIFICONFIG_SUCCESS):鎴愬姛
 * @note   1:MCU涓诲姩璋冪敤mcu_set_wifi_mode()鍚庤皟鐢ㄨ鍑芥暟鑾峰彇澶嶄綅鐘舵��
 *         2:濡傛灉涓烘ā鍧楄嚜澶勭悊妯″紡,MCU鏃犻』璋冪敤璇ュ嚱鏁�
 */
unsigned char mcu_get_wifimode_flag(void);

/**
 * @brief  MCU璁剧疆wifi宸ヤ綔妯″紡
 * @param[in] {mode} 杩涘叆鐨勬ā寮�
 * @ref        0(SMART_CONFIG):杩涘叆smartconfig妯″紡
 * @ref        1(AP_CONFIG):杩涘叆AP妯″紡
 * @return Null
 * @note   1:MCU涓诲姩璋冪敤
 *         2:鎴愬姛鍚�,鍙垽鏂璼et_wifi_config_state鏄惁涓篢RUE;TRUE琛ㄧず涓鸿缃畐ifi宸ヤ綔妯″紡鎴愬姛
 *         3:濡傛灉涓烘ā鍧楄嚜澶勭悊妯″紡,MCU鏃犻』璋冪敤璇ュ嚱鏁�
 */
void mcu_set_wifi_mode(unsigned char mode);

/**
 * @brief  MCU涓诲姩鑾峰彇褰撳墠wifi宸ヤ綔鐘舵��
 * @param  Null
 * @return wifi work state
 * -          SMART_CONFIG_STATE: smartconfig閰嶇疆鐘舵��
 * -          AP_STATE: AP閰嶇疆鐘舵��
 * -          WIFI_NOT_CONNECTED: WIFI閰嶇疆鎴愬姛浣嗘湭杩炰笂璺敱鍣�
 * -          WIFI_CONNECTED: WIFI閰嶇疆鎴愬姛涓旇繛涓婅矾鐢卞櫒
 * -          WIFI_CONN_CLOUD: WIFI宸茬粡杩炴帴涓婁簯鏈嶅姟鍣�
 * -          WIFI_LOW_POWER: WIFI澶勪簬浣庡姛鑰楁ā寮�
 * -          SMART_AND_AP_STATE: WIFI smartconfig&AP 妯″紡
 * @note   濡傛灉涓烘ā鍧楄嚜澶勭悊妯″紡,MCU鏃犻』璋冪敤璇ュ嚱鏁�
 */
unsigned char mcu_get_wifi_work_state(void);
#endif

#ifdef SUPPORT_GREEN_TIME
/**
 * @brief  MCU鑾峰彇鏍兼灄鏃堕棿
 * @param  Null
 * @return Null
 * @note   MCU闇�瑕佽嚜琛岃皟鐢ㄨ鍔熻兘
 */
void mcu_get_green_time(void);
#endif

#ifdef SUPPORT_MCU_RTC_CHECK
/**
 * @brief  MCU鑾峰彇绯荤粺鏃堕棿,鐢ㄤ簬鏍″鏈湴鏃堕挓
 * @param  Null
 * @return Null
 * @note   MCU涓诲姩璋冪敤瀹屾垚鍚庡湪mcu_write_rtctime鍑芥暟鍐呮牎瀵箁tc鏃堕挓
 */
void mcu_get_system_time(void);
#endif

#ifdef WIFI_TEST_ENABLE
/**
 * @brief  mcu鍙戣捣wifi鍔熻兘娴嬭瘯
 * @param  Null
 * @return Null
 * @note   MCU闇�瑕佽嚜琛岃皟鐢ㄨ鍔熻兘
 */
void mcu_start_wifitest(void);
#endif

#ifdef WIFI_HEARTSTOP_ENABLE
/**
 * @brief  閫氱煡WIFI妯＄粍鍏抽棴蹇冭烦
 * @param  Null
 * @return Null
 * @note   MCU闇�瑕佽嚜琛岃皟鐢ㄨ鍔熻兘
 */
void wifi_heart_stop(void);
#endif

#ifdef GET_WIFI_STATUS_ENABLE
/**
 * @brief  鑾峰彇褰撳墠wifi鑱旂綉鐘舵��
 * @param  Null
 * @return Null
 * @note   MCU闇�瑕佽嚜琛岃皟鐢ㄨ鍔熻兘
 */
void mcu_get_wifi_connect_status(void);
#endif

#ifdef WIFI_STREAM_ENABLE
/**
 * @brief  娴佹湇鍔″彂閫�
 * @param[in] {id} ID鍙�
 * @param[in] {buffer} 鍙戦�佸寘鐨勫湴鍧�
 * @param[in] {buf_len} 鍙戦�佸寘闀垮害
 * @return 娴佹湇鍔′紶杈撶粨鏋�
 * -           0(ERROR): 澶辫触
 * -           1(SUCCESS): 鎴愬姛
 * @note   MCU闇�瑕佽嚜琛屽疄鐜拌鍔熻兘
 */
unsigned char stream_trans_send(unsigned int id, unsigned char *buffer, unsigned long buf_len);

/**
 * @brief  澶氬湴鍥炬祦鏈嶅姟鍙戦��
 * @param[in] {id} 鍦板浘娴佹湇鍔′細璇滻D
 * @param[in] {sub_id} 瀛愬湴鍥綢D
 * @param[in] {sub_id_pro_mode} 瀛愬湴鍥綢D鏁版嵁澶勭悊鏂瑰紡
 * @ref       0x00: 缁х画绱姞
 * @ref       0x01: 娓呴櫎涓婁紶鐨勬暟鎹�
 * @param[in] {buffer} 鏁版嵁鍖呭彂閫佺殑鍦板潃
 * @param[in] {buf_len} 鏁版嵁鍖呭彂閫佺殑闀垮害
 * @return 娴佹湇鍔′紶杈撶粨鏋�
 * -           0(ERROR): 澶辫触
 * -           1(SUCCESS): 鎴愬姛
 * @note   MCU闇�瑕佽嚜琛屽疄鐜拌鍔熻兘
 */
unsigned char maps_stream_trans_send(unsigned int id, unsigned char sub_id, unsigned char sub_id_pro_mode, unsigned char *buffer, unsigned long buf_len);
#endif

#ifdef WIFI_CONNECT_TEST_ENABLE
/**
 * @brief  mcu鍙戣捣wifi鍔熻兘娴嬭瘯(杩炴帴鎸囧畾璺敱)
 * @param[in] {ssid_buf} 瀛樻斁璺敱鍣ㄥ悕绉板瓧绗︿覆鏁版嵁鐨勫湴鍧�(ssid闀垮害鏈�澶ф敮鎸�32涓瓧鑺�)
 * @param[in] {passwd_buffer} 瀛樻斁璺敱鍣ㄥ悕绉板瓧绗︿覆鏁版嵁鐨勫湴鍧�(passwd闀垮害鏈�澶ф敮鎸�64涓瓧鑺�)
 * @return Null
 * @note   MCU闇�瑕佽嚜琛岃皟鐢ㄨ鍔熻兘
 */
void mcu_start_connect_wifitest(unsigned char *ssid_buf,unsigned char *passwd_buffer);
#endif

#ifdef GET_MODULE_MAC_ENABLE
/**
 * @brief  鑾峰彇妯″潡MAC
 * @param  Null
 * @return Null
 * @note   MCU闇�瑕佽嚜琛岃皟鐢ㄨ鍔熻兘
 */
void mcu_get_module_mac(void);
#endif

#ifdef IR_TX_RX_TEST_ENABLE
/**
 * @brief  mcu鍙戣捣绾㈠杩涘叆鏀跺彂浜ф祴
 * @param  Null
 * @return Null
 * @note   MCU闇�瑕佽嚜琛岃皟鐢ㄨ鍔熻兘
 */
void mcu_start_ir_test(void);
#endif

#ifdef MODULE_EXPANDING_SERVICE_ENABLE
/**
 * @brief  鎵撳紑妯″潡鏃堕棿鏈嶅姟閫氱煡
 * @param[in] {time_type} 鏃堕棿绫诲瀷
 * @ref       0x00: 鏍兼灄鏃堕棿
 * @ref       0x01: 鏈湴鏃堕棿
 * @return Null
 * @note   MCU闇�瑕佽嚜琛岃皟鐢ㄨ鍔熻兘
 */
void open_module_time_serve(unsigned char time_type);

/**
 * @brief  涓诲姩璇锋眰澶╂皵鏈嶅姟鏁版嵁
 * @param  Null
 * @return Null
 * @note   MCU闇�瑕佽嚜琛岃皟鐢ㄨ鍔熻兘
 */
void request_weather_serve(void);

/**
 * @brief  鎵撳紑妯″潡閲嶇疆鐘舵�侀�氱煡
 * @param  Null
 * @return Null
 * @note   MCU闇�瑕佽嚜琛岃皟鐢ㄨ鍔熻兘
 */
void open_module_reset_state_serve(void);
#endif

#ifdef BLE_RELATED_FUNCTION_ENABLE
/**
 * @brief  mcu鍙戣捣钃濈墮鍔熻兘鎬ф祴璇曪紙鎵弿鎸囧畾钃濈墮淇℃爣锛�
 * @param  Null
 * @return Null
 * @note   MCU闇�瑕佽嚜琛岃皟鐢ㄨ鍔熻兘
 */
void mcu_start_BLE_test(void);
#endif

#ifdef VOICE_MODULE_PROTOCOL_ENABLE
/**
 * @brief  鑾峰彇璇煶鐘舵�佺爜
 * @param  Null
 * @return Null
 * @note   MCU闇�瑕佽嚜琛岃皟鐢ㄨ鍔熻兘
 */
void get_voice_state(void);

/**
 * @brief  MIC闈欓煶璁剧疆
 * @param[in] {set_val} 闈欓煶璁剧疆鍊�
 * @ref       0x00: mic寮�鍚�
 * @ref       0x01: mic闈欓煶
 * @ref       0xA0: 鏌ヨ闈欓煶鐘舵��
 * @return Null
 * @note   MCU闇�瑕佽嚜琛岃皟鐢ㄨ鍔熻兘
 */
void set_voice_MIC_silence(unsigned char set_val);

/**
 * @brief  speaker闊抽噺璁剧疆
 * @param[in] {set_val} 闊抽噺璁剧疆鍊�
 * @ref       0~10: 闊抽噺鑼冨洿
 * @ref       0xA0: 鏌ヨ闊抽噺鍊�
 * @return Null
 * @note   MCU闇�瑕佽嚜琛岃皟鐢ㄨ鍔熻兘
 */
void set_speaker_voice(unsigned char set_val);

/**
 * @brief  闊抽浜ф祴
 * @param[in] {set_val} 闊抽浜ф祴鍊�
 * @ref       0x00: 鍏抽棴闊抽浜ф祴
 * @ref       0x01: mic1闊抽鐜矾娴嬭瘯
 * @ref       0x02: mic2闊抽鐜矾娴嬭瘯
 * @ref       0xA0: 鏌ヨ褰撳墠浜ф祴鐘舵��
 * @return Null
 * @note   MCU闇�瑕佽嚜琛岃皟鐢ㄨ鍔熻兘
 */
void voice_test(unsigned char test_val);

/**
 * @brief  鍞ら啋浜ф祴
 * @param  Null
 * @return Null
 * @note   MCU闇�瑕佽嚜琛岃皟鐢ㄨ鍔熻兘
 */
void voice_awaken_test(void);

/**
 * @brief  璇煶妯＄粍MCU鍔熻兘璁剧疆
 * @param[in] {play} 鎾斁/鏆傚仠鍔熻兘 1(鎾斁) / 0(鏆傚仠)
 * @param[in] {bt_play} 钃濈墮寮�鍏冲姛鑳� 1(寮�) / 0(鍏�)
 * @return Null
 * @note   MCU闇�瑕佽嚜琛岃皟鐢ㄨ鍔熻兘
 */
void voice_mcu_fun_set(unsigned char play, unsigned char bt_play);
#endif
void wifi_state_get(void);
#endif
