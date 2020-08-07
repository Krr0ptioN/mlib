

#include <stddef.h>

#ifndef STRING_H
#define STRING_H
#include <stdlib.h>
#include <stdbool.h>

typedef long int index_t;

typedef struct string mdata_string;

typedef struct string {
	char *str;
	size_t length;
	size_t size;
	// methods
	bool (*isEmpty)(mdata_string *self);
	void (*resize)(mdata_string *self,index_t);
	void (*append)(mdata_string *self,const char*);
	index_t (*search)(mdata_string *self,char*); 
	void (*remove)(mdata_string *self,char*);   
	void (*swap)(mdata_string *self,index_t,index_t);
	void (*insert)(mdata_string *self,index_t,char*);
	void (*reverse)(mdata_string *self);
	void (*shiftRight)(mdata_string *self);
	void (*shiftLeft)(mdata_string *self);	        
        char* (*pop_back)(mdata_string *self);
        char* (*pop_front)(mdata_string *self);
	void (*push_back)(mdata_string *self,char*);
	void (*push_front)(mdata_string *self,char*);
	void (*delete_self)(mdata_string *self);  
} mdata_string;

bool mdata_string_isEmpty(mdata_string *self){
	if(self->length == 0)
		return true;
	else
		return false;
}

void mdata_string_resize(mdata_string *self,size_t add_size){
	self->size += add_size;
	if(add_size == 0)
		return;
	char *tmp = (char*)malloc(self->size);

	for(size_t i = 0;i < self->length;i++)
		tmp[i] = self->str[i];

	free(self->str);
	self->str = tmp;
}

void mdata_string_append(mdata_string *self,const char *__str){
	size_t len = sizeof(__str);
	if(self->length >= self->size || self->size < len){
		self->resize(self,len);
		for(size_t i = len; i < self->length;i++){
			self->str[i] = __str[i];
		}
	} else {
		for(size_t i = len; i < self->length;i++){
			self->str[i] = __str[i];
		}
	}
}

void mdata_string_reverse(){
	
}

void mdata_string_push_back(mdata_string *self){
	
}

void mdata_string_push_front(mdata_string *self){
	
}

void mdata_string_pop_back(mdata_string *self){
	
}

void mdata_string_pop_front(mdata_string *self){
	
}

#define mdata_string(size)				\
	{						\
		.isEmpty=mdata_string_isEmpty,		\
		.resize = mdata_string_resize,	        \
		.append = mdata_string_append,	        \
	}


#endif
