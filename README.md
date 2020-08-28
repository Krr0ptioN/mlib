# mdata
ADT Data Strcuture with Template simulation for Clang.
## Documentation
-----------------------
### Installation
### Usage
#### C language
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
Methods:  
* Is Empty(return boolean):
 ```c
 mdata_array_isEmpty_typename(&name_arr);
```
* Get value by idnex:
``` c
mdata_array_get_typename(&name_arr,index);
```
* Set value by index:
 ```c
 mdata_array_set_typename(&name_arr,index,value);
```
* Adding to array size by specified number:
 ```c
 mdata_array_resize_typename(&name_arr,add_size);
```
* Append value to list:
 ```c
 mdata_array_append_typename(&name_arr,value);
```
* Append other array to list:
 ```c
 mdata_array_append_arr_typename(&name_arr,&second_array);
```
* Search value(return index):
 ```c
mdata_array_search_typename(&name_arr,); -> index of vlaue
```
* Remove elements by index:
 ```c
mdata_array_remove_typename(&name_arr,index);
```
* Insert value or elements by index:
 ```c
mdata_array_insert_typename(&name_arr,index,value)
```
* Reverse array:
 ```c
mdata_array_revese_typename(&name_arr);
```
* Swap elements by index in array:
```c
mdata_array_swap_typename(&name_arr,index,index_second);
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

#### C++

Example:
```cpp
#include "Collection.h"

mdata::array<T> name_arr(size);
	// Copy the array
mdata::array<T> name_arr2 = name_arr;```
To accessing the array elements use this struct elements.
```cpp
name_arr[index];
```

Methods:
* Get value by idnex:
``` c
name_arr.get(index);
```
* Set value by index:
 ```c
 name_arr.set(index,value);
```
* Adding to array size by specified number:
 ```c
name_arr.resize(add_size);
```
* Append value to list:
 ```c
name_arr.append(value);
```
* Append other array to list:
 ```c
name_arr.append_arr(&name_arr,&second_array);
```
* Search value(return index):<T>
 ```c
name_arr.search(value); -> index of vlaue
```
* Remove elements by index:
 ```c
name_arr.remove(index);
```
* Insert value or elements by index:
 ```c
name_arr.insert(index,value)
```
* Reverse array:
 ```c
name_arr.reverse();
```
* Swap elements by index in array:
 ```c
name_arr.swap(index,index_second);
```

### TODO
Data structure:
- [ ] Linked List
- [ ] Stack and Queue

Other:
- [ ] Polymorphism for C and C++
- [ ] Object oriented for C
- [ ] print method.
- [ ] Test for memory corruption.
