/*!
 * \file      se-identity_template.h
 *
 * \brief     Secure Element identity and keys
 *
 * \copyright Revised BSD License, see section \ref LICENSE.
 *
 * \code
 *                ______                              _
 *               / _____)             _              | |
 *              ( (____  _____ ____ _| |_ _____  ____| |__
 *               \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 *               _____) ) ____| | | || |_| ____( (___| | | |
 *              (______/|_____)_|_|_| \__)_____)\____)_| |_|
 *              (C)2020 Semtech
 *
 *               ___ _____ _   ___ _  _____ ___  ___  ___ ___
 *              / __|_   _/_\ / __| |/ / __/ _ \| _ \/ __| __|
 *              \__ \ | |/ _ \ (__| ' <| _| (_) |   / (__| _|
 *              |___/ |_/_/ \_\___|_|\_\_| \___/|_|_\\___|___|
 *              embedded.connectivity.solutions===============
 *
 * \endcode
 *
 */
/**
  ******************************************************************************
  *
  *          Portions COPYRIGHT 2020 STMicroelectronics
  *
  * @file    se-identity_template.c
  * @author  MCD Application Team
  * @brief   Secure Element identity and keys
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SOFT_SE_IDENTITY_H__
#define __SOFT_SE_IDENTITY_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Exported Includes --------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/

/*!
 ******************************************************************************
 ********************************** WARNING ***********************************
 ******************************************************************************
  The secure-element implementation supports both 1.0.x and 1.1.x LoRaWAN
  versions of the specification.
  Thus it has been decided to use the 1.1.x keys and EUI name definitions.
  The below table shows the names equivalence between versions:
               +---------------------+-------------------------+
               |       1.0.x         |          1.1.x          |
               +=====================+=========================+
               | LORAWAN_DEVICE_EUI  | LORAWAN_DEVICE_EUI      |
               +---------------------+-------------------------+
               | LORAWAN_APP_EUI     | LORAWAN_JOIN_EUI        |
               +---------------------+-------------------------+
               | LORAWAN_GEN_APP_KEY | LORAWAN_APP_KEY         |
               +---------------------+-------------------------+
               | LORAWAN_APP_KEY     | LORAWAN_NWK_KEY         |
               +---------------------+-------------------------+
               | LORAWAN_NWK_S_KEY   | LORAWAN_F_NWK_S_INT_KEY |
               +---------------------+-------------------------+
               | LORAWAN_NWK_S_KEY   | LORAWAN_S_NWK_S_INT_KEY |
               +---------------------+-------------------------+
               | LORAWAN_NWK_S_KEY   | LORAWAN_NWK_S_ENC_KEY   |
               +---------------------+-------------------------+
               | LORAWAN_APP_S_KEY   | LORAWAN_APP_S_KEY       |
               +---------------------+-------------------------+
 ******************************************************************************
 ******************************************************************************
 ******************************************************************************
 */

/*!
 * When set to 1 DevEui is LORAWAN_DEVICE_EUI
 * When set to 0 DevEui is automatically set with a value provided by MCU platform
 */
#define STATIC_DEVICE_EUI                                  1

/*!
 * end-device IEEE EUI (big endian)
 */
#define LORAWAN_DEVICE_EUI                                 { 0x00, 0x80, 0xE1, 0x15, 0x00, 0x07, 0x4C, 0xD5 }

/*!
 * App/Join server IEEE EUI (big endian)
 */
#define LORAWAN_JOIN_EUI                                   { 0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x03, 0xF0, 0x6A }

/*!
 * When set to 1 DevAddr is LORAWAN_DEVICE_ADDRESS
 * When set to 0 DevAddr is automatically set with a value provided by a pseudo
 *      random generator seeded with a value provided by the MCU platform
 */
#define STATIC_DEVICE_ADDRESS                              0

/*!
 * Device address on the network (big endian)
 */
#define LORAWAN_DEVICE_ADDRESS                             ( uint32_t )0x0100000A

/*!
 * Application root key
 */
#define LORAWAN_APP_KEY                                    2B,7E,15,16,28,AE,D2,A6,AB,F7,15,88,09,CF,4F,3C

/*!
 * Network root key
 */
#define LORAWAN_NWK_KEY                                    2B,7E,15,16,28,AE,D2,A6,AB,F7,15,88,09,CF,4F,3C

/*!
 * Forwarding Network session key
 */
#define LORAWAN_NWK_S_KEY                                  2B,7E,15,16,28,AE,D2,A6,AB,F7,15,88,09,CF,4F,3C

/*!
 * Application session key
 */
#define LORAWAN_APP_S_KEY                                  2B,7E,15,16,28,AE,D2,A6,AB,F7,15,88,09,CF,4F,3C

/*!
 * Format commissioning keys
 */
#define RAW_TO_INT8A(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) {0x##a,0x##b,0x##c,0x##d,\
                                                        0x##e,0x##f,0x##g,0x##h,\
                                                        0x##i,0x##j,0x##k,0x##l,\
                                                        0x##m,0x##n,0x##o,0x##p}

#define FORMAT_KEY(...) RAW_TO_INT8A(__VA_ARGS__)

#if (USE_LRWAN_1_1_X_CRYPTO == 1)
#define SESSION_KEYS_LIST                                                                                           \
           {                                                                                                        \
            /*!                                                                                                     \
             * Join session integrity key (Dynamically updated)                                                     \
             * WARNING: NOT USED FOR 1.0.x DEVICES                                                                  \
             */                                                                                                     \
            .KeyID    = J_S_INT_KEY,                                                                                \
            .KeyValue = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                          0x00 },                                                                                   \
        },                                                                                                          \
        {                                                                                                           \
            /*!                                                                                                     \
             * Join session encryption key (Dynamically updated)                                                    \
             * WARNING: NOT USED FOR 1.0.x DEVICES                                                                  \
             */                                                                                                     \
            .KeyID    = J_S_ENC_KEY,                                                                                \
            .KeyValue = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                          0x00 },                                                                                   \
        },                                                                                                          \
        {                                                                                                           \
            /*!                                                                                                     \
             * Forwarding Network session integrity key                                                             \
             * WARNING: NWK_S_KEY FOR 1.0.x DEVICES                                                                 \
             */                                                                                                     \
            .KeyID    = F_NWK_S_INT_KEY,                                                                            \
            .KeyValue = FORMAT_KEY(LORAWAN_NWK_S_KEY),                                                              \
        },                                                                                                          \
        {                                                                                                           \
            /*!                                                                                                     \
             * Serving Network session integrity key                                                                \
             * WARNING: NOT USED FOR 1.0.x DEVICES. MUST BE THE SAME AS \ref LORAWAN_F_NWK_S_INT_KEY                \
             */                                                                                                     \
            .KeyID    = S_NWK_S_INT_KEY,                                                                            \
            .KeyValue = { 0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, \
                          0x3C },                                                                                   \
        },                                                                                                          \
        {                                                                                                           \
            /*!                                                                                                     \
             * Network session encryption key                                                                       \
             * WARNING: NOT USED FOR 1.0.x DEVICES. MUST BE THE SAME AS \ref LORAWAN_F_NWK_S_INT_KEY                \
             */                                                                                                     \
            .KeyID    = NWK_S_ENC_KEY,                                                                              \
            .KeyValue = { 0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, \
                          0x3C },                                                                                   \
        },                                                                                                          \
        {                                                                                                           \
            /*!                                                                                                     \
             * Application session key                                                                              \
             */                                                                                                     \
            .KeyID    = APP_S_KEY,                                                                                  \
            .KeyValue = FORMAT_KEY(LORAWAN_APP_S_KEY),                                                              \
        },
#else /* USE_LRWAN_1_1_X_CRYPTO == 0 */
#define SESSION_KEYS_LIST                                                                                           \
        {                                                                                                           \
            /*!                                                                                                     \
             * Network session key                                                                                  \
             */                                                                                                     \
            .KeyID    = NWK_S_KEY,                                                                                  \
            .KeyValue = FORMAT_KEY(LORAWAN_NWK_S_KEY),                                                              \
        },                                                                                                          \
        {                                                                                                           \
            /*!                                                                                                     \
             * Application session key                                                                              \
             */                                                                                                     \
            .KeyID    = APP_S_KEY,                                                                                  \
            .KeyValue = FORMAT_KEY(LORAWAN_APP_S_KEY),                                                              \
        },
#endif /* USE_LRWAN_1_1_X_CRYPTO */

#if (LORAMAC_MAX_MC_CTX == 1)
#define SESSION_MC_KEYS_LIST                                                                                        \
        {                                                                                                           \
            /*!                                                                                                     \
             * Multicast group #0 root key (Dynamically updated)                                                    \
             */                                                                                                     \
            .KeyID    = MC_KEY_0,                                                                                   \
            .KeyValue = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                          0x00 },                                                                                   \
        },                                                                                                          \
        {                                                                                                           \
            /*!                                                                                                     \
             * Multicast group #0 application session key (Dynamically updated)                                     \
             */                                                                                                     \
            .KeyID    = MC_APP_S_KEY_0,                                                                             \
            .KeyValue = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                          0x00 },                                                                                   \
        },                                                                                                          \
        {                                                                                                           \
            /*!                                                                                                     \
             * Multicast group #0 network session key (Dynamically updated)                                         \
             */                                                                                                     \
            .KeyID    = MC_NWK_S_KEY_0,                                                                             \
            .KeyValue = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                          0x00 },                                                                                   \
        },
#else /* LORAMAC_MAX_MC_CTX > 1 */
#define SESSION_MC_KEYS_LIST                                                                                        \
        {                                                                                                           \
            /*!                                                                                                     \
             * Multicast group #0 root key (Dynamically updated)                                                    \
             */                                                                                                     \
            .KeyID    = MC_KEY_0,                                                                                   \
            .KeyValue = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                          0x00 },                                                                                   \
        },                                                                                                          \
        {                                                                                                           \
            /*!                                                                                                     \
             * Multicast group #0 application session key (Dynamically updated)                                     \
             */                                                                                                     \
            .KeyID    = MC_APP_S_KEY_0,                                                                             \
            .KeyValue = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                          0x00 },                                                                                   \
        },                                                                                                          \
        {                                                                                                           \
            /*!                                                                                                     \
             * Multicast group #0 network session key (Dynamically updated)                                         \
             */                                                                                                     \
            .KeyID    = MC_NWK_S_KEY_0,                                                                             \
            .KeyValue = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                          0x00 },                                                                                   \
        },                                                                                                          \
        {                                                                                                           \
            /*!                                                                                                     \
             * Multicast group #1 root key (Dynamically updated)                                                    \
             */                                                                                                     \
            .KeyID    = MC_KEY_1,                                                                                   \
            .KeyValue = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                          0x00 },                                                                                   \
        },                                                                                                          \
        {                                                                                                           \
            /*!                                                                                                     \
             * Multicast group #1 application session key (Dynamically updated)                                     \
             */                                                                                                     \
            .KeyID    = MC_APP_S_KEY_1,                                                                             \
            .KeyValue = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                          0x00 },                                                                                   \
        },                                                                                                          \
        {                                                                                                           \
            /*!                                                                                                     \
             * Multicast group #1 network session key (Dynamically updated)                                         \
             */                                                                                                     \
            .KeyID    = MC_NWK_S_KEY_1,                                                                             \
            .KeyValue = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                          0x00 },                                                                                   \
        },                                                                                                          \
        {                                                                                                           \
            /*!                                                                                                     \
             * Multicast group #2 root key (Dynamically updated)                                                    \
             */                                                                                                     \
            .KeyID    = MC_KEY_2,                                                                                   \
            .KeyValue = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                          0x00 },                                                                                   \
        },                                                                                                          \
        {                                                                                                           \
            /*!                                                                                                     \
             * Multicast group #2 application session key (Dynamically updated)                                     \
             */                                                                                                     \
            .KeyID    = MC_APP_S_KEY_2,                                                                             \
            .KeyValue = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                          0x00 },                                                                                   \
        },                                                                                                          \
        {                                                                                                           \
            /*!                                                                                                     \
             * Multicast group #2 network session key (Dynamically updated)                                         \
             */                                                                                                     \
            .KeyID    = MC_NWK_S_KEY_2,                                                                             \
            .KeyValue = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                          0x00 },                                                                                   \
        },                                                                                                          \
        {                                                                                                           \
            /*!                                                                                                     \
             * Multicast group #3 root key (Dynamically updated)                                                    \
             */                                                                                                     \
            .KeyID    = MC_KEY_3,                                                                                   \
            .KeyValue = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                          0x00 },                                                                                   \
        },                                                                                                          \
        {                                                                                                           \
            /*!                                                                                                     \
             * Multicast group #3 application session key (Dynamically updated)                                     \
             */                                                                                                     \
            .KeyID    = MC_APP_S_KEY_3,                                                                             \
            .KeyValue = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                          0x00 },                                                                                   \
        },                                                                                                          \
        {                                                                                                           \
            /*!                                                                                                     \
             * Multicast group #3 network session key (Dynamically updated)                                         \
             */                                                                                                     \
            .KeyID    = MC_NWK_S_KEY_3,                                                                             \
            .KeyValue = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                          0x00 },                                                                                   \
        },
#endif /* LORAMAC_MAX_MC_CTX */

#define SOFT_SE_KEY_LIST                                                                                            \
    {                                                                                                               \
        {                                                                                                           \
            /*!                                                                                                     \
             * Application root key                                                                                 \
             * WARNING: FOR 1.0.x DEVICES IT IS THE \ref LORAWAN_GEN_APP_KEY                                        \
             */                                                                                                     \
            .KeyID    = APP_KEY,                                                                                    \
            .KeyValue = FORMAT_KEY(LORAWAN_APP_KEY),                                                                \
        },                                                                                                          \
        {                                                                                                           \
            /*!                                                                                                     \
             * Network root key                                                                                     \
             * WARNING: FOR 1.0.x DEVICES IT IS THE \ref LORAWAN_APP_KEY                                            \
             */                                                                                                     \
            .KeyID    = NWK_KEY,                                                                                    \
            .KeyValue = FORMAT_KEY(LORAWAN_NWK_KEY),                                                                \
        },                                                                                                          \
        SESSION_KEYS_LIST                                                                                           \
        {                                                                                                           \
            /*!                                                                                                     \
             * Multicast root key (Dynamically updated)                                                             \
             */                                                                                                     \
            .KeyID    = MC_ROOT_KEY,                                                                                \
            .KeyValue = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                          0x00 },                                                                                   \
        },                                                                                                          \
        {                                                                                                           \
            /*!                                                                                                     \
             * Multicast key encryption key (Dynamically updated)                                                   \
             */                                                                                                     \
            .KeyID    = MC_KE_KEY,                                                                                  \
            .KeyValue = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                          0x00 },                                                                                   \
        },                                                                                                          \
        SESSION_MC_KEYS_LIST                                                                                        \
        {                                                                                                           \
            /*!                                                                                                     \
             * All zeros key. (ClassB usage)(constant)                                                              \
             */                                                                                                     \
            .KeyID    = SLOT_RAND_ZERO_KEY,                                                                         \
            .KeyValue = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                          0x00 },                                                                                   \
        },                                                                                                          \
    }

/* USER CODE BEGIN EC */

/* USER CODE END EC */

#ifdef __cplusplus
}
#endif

#endif  /*  __SOFT_SE_IDENTITY_H__ */
