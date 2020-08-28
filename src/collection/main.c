#include "Collection.h"
#include <stdio.h>
#include <stdlib.h>

mdata_array_template(int)

int main(){
	mdata_array(int) arr = mdata_array_new(int,10);
	mdata_array_append_int(&arr,12);
    mdata_array_append_int(&arr,30);
    for(size_t i = 0;i < arr.length;i++)
    	printf("%d ",arr.list[i]);
    printf("\n");
    mdata_array_remove_int(&arr,1);
    for(size_t i = 0;i < arr.length;i++)
    	printf("%d",arr.list[i]);
    printf("\n");
    mdata_array_append_int(&arr,7);
    mdata_array_append_int(&arr,42);
    mdata_array_append_int(&arr,41);
    mdata_array_append_int(&arr,67);
    mdata_array_insert_int(&arr,4,100);
    for(size_t i = 0;i < arr.length;i++)
    	printf("%d ",arr.list[i]);
    printf("\n");
    mdata_array_reverse_int(&arr);
    for(size_t i = 0;i < arr.length;i++)
    	printf("%d ",arr.list[i]);
    printf("\n");
	return 0;
}
