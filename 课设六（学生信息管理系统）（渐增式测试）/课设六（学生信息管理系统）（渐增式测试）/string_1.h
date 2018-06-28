/*************************************************
Copyright (C), 2018, Tyut
File name:     string_1.h
Author: fengjiawei    Version: 1.1     Date: 2018.6.28
Description:   ×Ö·û´®¿½±´Í·ÎÄ¼þ 
*************************************************/
#ifndef STRING_1_H
#define STRING_1_H

int Strcpy(char* str1,char* str2){

	while(*str2!='\0'){
		*str1++=*str2++;
	}
	*str1='\0';
	return 0;
}

#endif