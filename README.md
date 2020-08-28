# mdata
ADT Data Strcuture with Template
## Documentation
-----------------------
### Installation
### Usage
###### C
First include the `src/collection/Collection.h` and then create template with specified data type.

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


