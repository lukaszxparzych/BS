#include <stdio.h>
#include <stdlib.h>

#include <errno.h>
#include <string.h>

#include <sys/socket.h>
#include <linux/if_ether.h>
#include "netinet/in.h"

#include "UDP_header.h"
#include "IP_header.h"
#include "lista_wiazana.h"

struct element element1;
int licznik = 0 ;
int main(void) {


         struct element *poczatek = NULL;
        struct element *poprzedni, *biezacy;


        printf("Uruchamiam odbieranie ramek Ethernet.\n"); /* prints  */

        //Utworzenie bufora dla odbieranych ramek Ethernet
        char* buffer = (void*) malloc(ETH_FRAME_LEN);

        //Otwarcie gniazda pozwalającego na odbiór wszystkich ramek Ethernet
        int iEthSockHandl = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
        //Kontrola czy gniazdo zostało otwarte poprawnie, w przypadku bledu wyświetlenie komunikatu.
        if (iEthSockHandl<0)
                printf("Problem z otwarciem gniazda : %s!\n", strerror(errno));

        //Zmienna do przechowywania rozmiaru odebranych danych
        int iDataLen = 0;

        //Pętla nieskończona do odbierania ramek Ethernet
        while (1) {
            struct ethhdr *eth = (struct ethhdr*)(buffer);

            //Odebranie ramki z utworzonego wcześniej gniazda i zapisanie jej do bufora
            iDataLen = recvfrom(iEthSockHandl, buffer, ETH_FRAME_LEN, 0, NULL, NULL);

            //Kontrola czy nie było bledu podczas odbierania ramki
            if (iDataLen == -1)
                printf("Nie moge odebrac ramki: %s! \n", strerror(errno));
            else { //jeśli ramka odebrana poprawnie wyświetlenie jej zawartości
                printf("\nOdebrano ramke Ethernet o rozmiarze: %d [B]\n", iDataLen);


                if(eth->h_proto == ntohs(ETH_P_IP))
                            {

                    struct IP_header *ip_header = (struct IP_header*)(buffer + sizeof(struct ethhdr));

                    if((unsigned int)ip_header->ip_protocol == 6){



                    struct UDP_header *udp_header = (struct UDP_header*)(buffer + sizeof(struct IP_header) + sizeof(struct ethhdr));



                    /*printf(" |-Źródło Portu : %d \n",ntohs(udp_header->source_port));
                    printf(" |-Docelowy Port : %d \n",ntohs(udp_header->dest_port));
                    printf(" |-UDP Długość : %d \n",ntohs(udp_header->udp_length));
                    printf(" |-UDP CRC : %d \n",ntohs(udp_header->udp_checksum));*/

                    //LISTA WIAZANA
                        biezacy = (struct element *) malloc(sizeof(struct element));

                        if(poczatek == NULL)
                            poczatek = biezacy;
                        else
                            poprzedni -> nastepny = biezacy;


                            biezacy -> nastepny = NULL;
                            biezacy -> zmienna = udp_header->source_port;
                            biezacy -> zmienna1 = udp_header->dest_port;
                            biezacy -> zmienna2 = udp_header->udp_length;
                            biezacy -> zmienna3 = udp_header->udp_checksum;
                            poprzedni = biezacy;
                            licznik = licznik +1;
                        while(licznik > 5){
                            biezacy = poczatek;

                        while(licznik >0){
                            printf("|-Pakiet nr : %d \n",licznik);
                            printf("|-Zrodlo Portu : %d \n",ntohs(biezacy->zmienna));
                            printf("|-Docelowy Port : %d \n",ntohs(biezacy->zmienna1));
                            printf("|-UDP Dlugosc : %d \n",ntohs(biezacy->zmienna2));
                            printf("|-UDP CRC : %d \n",ntohs(biezacy->zmienna3));
                            biezacy = biezacy -> nastepny;
                            licznik = licznik -1;
                            }
                        if(licznik == 0){

                        while (biezacy != NULL ){
                            biezacy = poczatek;
                            poprzedni = biezacy;
                            biezacy = biezacy -> nastepny;
                            free(poprzedni);

                        }

                        free(biezacy);
                        free(poczatek);

                        }
                        }
            }
                            }

        }
        }
    return EXIT_SUCCESS;

        }
