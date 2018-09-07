// usrfunc.c
//  user defined functions for sh_kyle
//  Kyle Pollina

#include "../include/usrfunc.h"

//TODO document
//TODO THREADS BABY




//
int exec_usrfunc(list_t *input)
{
	node_t *first = input->head->next;		

	if(first->id != ID_STR){
		return ERR;
	}
    return 0;
	
}

/***************************************
*  User created functions go down here *
*      *    *    *					   *
*      *    *    *					   *
*      V    V    V					   *
****************************************/
