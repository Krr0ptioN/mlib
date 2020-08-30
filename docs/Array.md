# Array ADT
----------------------------
## C language
First include the `src/collection/Collection.h` and then create template with specified data type.
To creating a template with specified data type use the following syntax:
```c
mdata_array_template(type)
```
Example:
```c
mdata_array_template(int)
```
Creating a template make all methods with specified type and return.  
Defining the array:
```c
mdata_array(type) name = mdata_array_new(type,size);
```
To accessing the array elements use this struct elements.
```c 
array_name.list[index];
```
### Methods:  
* Is Empty(return boolean):
 ```c
array_name.isEmpty(&array_name); --> boolean
```
* Get value by idnex:
``` c
array_name.get(&array_name,index);
```
* Set value by index:
 ```c
array_name.set(&array_name,index,value);
```
* Adding to array size by specified number:
 ```c
array_name.resize(&array_name,add_size);
```
* Append value to list:
 ```c
array_name.append(&array_name,value);
```
* Append other array to list:
 ```c
array_name.append_arr(&array_name,&second_array);
```
* Search value(return index):
 ```c
array_name.search(&array_name,); --> index of vlaue
```
* Remove elements by index:
 ```c
array_name.remove(&array_name,index);
```
* Insert value or elements by index:
 ```c
array_name.insert(&array_name,index,value)
```
* Reverse array:
 ```c
array_name.revese(&array_name);
```
* Swap elements by index in array:
```c
array_name.swap(&array_name,index,index_second);
```
* Shift elements to right:
```c
array_name.shiftRight(&array_name);
```
* Shift elements to left:
```c
array_name.shiftLeft(&array_name);
```

##### Example:  
```c
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
```

## C++

Example:
```cpp
#include "Collection.h"

mdata::array<T> name_arr(size);
	// Copy other array
mdata::array<T> name_arr2 = name_arr;```
To accessing the array elements use this struct elements.
```cpp
name_arr[index];
```

Methods:
* Get value by idnex:
``` c
array_name.get(index);
```
* Set value by index:
 ```c
 array_name.set(index,value);
```
* Adding to array size by specified number:
 ```c
array_name.resize(add_size);
```
* Append value to list:
 ```c
array_name.append(value);
```
* Append other array(from mdata namespace) to list:
 ```c
array_name.append_arr(second_array);
```
* Search value(return index):<T>
 ```c
array_name.search(value); -> index of vlaue
```
* Remove elements by index:
 ```c
array_name.remove(index);
```
* Insert value or elements by index:
 ```c
array_name.insert(index,value)
```
* Reverse array:
 ```c
array_name.reverse();
```
* Swap elements by index in array:
 ```c
array_name.swap(index,index_second);
```
