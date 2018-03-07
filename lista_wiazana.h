/*
 * lista_wiazana.h
 *
 *  Created on: 13 lis 2017
 *      Author: root
 */

#ifndef LISTA_WIAZANA_H_
#define LISTA_WIAZANA_H_

 struct element{
     unsigned short zmienna;
     unsigned short zmienna1;
     unsigned short zmienna2;
     unsigned short zmienna3;

   struct element *nastepny; /* wskaźnik na kolejny element listy */

 };

#endif /* LISTA_WIAZANA_H_ */

