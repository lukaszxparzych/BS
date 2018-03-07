/*
 * UDP_header.h
 *
 *  Created on: Nov 8, 2017
 *      Author: root
 */

#ifndef UDP_HEADER_H_
#define UDP_HEADER_H_

struct UDP_header{

    unsigned short source_port;
    unsigned short dest_port;
    unsigned short udp_length;
    unsigned short udp_checksum;
    //char dane;

};




#endif /* UDP_HEADER_H_ */
