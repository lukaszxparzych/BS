/*
 * IP_header.h
 *
 *  Created on: Nov 8, 2017
 *      Author: root
 */

#ifndef IP_HEADER_H_
#define IP_HEADER_H_



struct IP_header{
    unsigned char ip_header_len;
        //unsigned char ip_version :4;
        unsigned char ip_type;
        unsigned short ip_total_length;
        unsigned short ip_id;
        unsigned short ip_off;                 /* fragment offset field */
        #define IP_RF 0x8000            /* reserved fragment flag */
        #define IP_DF 0x4000            /* dont fragment flag */
        #define IP_MF 0x2000            /* more fragments flag */
        #define IP_OFFMASK 0x1fff       /* mask for fragmenting bits */
        unsigned char ip_ttl;
        unsigned char ip_protocol;
        unsigned short ip_checksum;
        unsigned int ip_srcaddr;
        unsigned int ip_destaddr;

    };






#endif /* IP_HEADER_H_ */
