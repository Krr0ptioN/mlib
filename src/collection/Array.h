/* template <typename TYPE>
 * class array {
 */


#ifndef ARRAY_H
#define ARRAY_H
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#define mdata_array_template(TYPE)					\
	struct mdata_array_##TYPE {					\
		TYPE *list;						\
		size_t length;						\
		size_t size;						\
	};								\
	bool mdata_array_isEmpty_##TYPE(struct mdata_array_##TYPE * self_array){ \
		if(self_array->length == 0)				\
			return true;					\
		else							\
			return false;					\
	}								\
									\
        TYPE mdata_array_get_##TYPE(struct mdata_array_##TYPE* self_array,size_t index){\
		if(index <= self_array->length)				\
			return self_array->list[index];			\
		else							\
			return 0;					\
	}								\
									\
	void mdata_array_set_##TYPE(struct mdata_array_##TYPE* self_array,size_t index \
			,TYPE value){					\
		self_array->list[index] = value;			\
	}								\
									\
	void mdata_array_resize_##TYPE(struct mdata_array_##TYPE* self_array	\
			   ,size_t add_size){				\
		TYPE* tmp = (TYPE*)malloc(self_array->size + add_size);	\
		for(size_t i = 0; i < self_array->length;i++)		\
			tmp[i] = self_array->list[i];			\
		free(self_array->list);				        \
		self_array->list = tmp;					\
									\
	}								\
									\
	void mdata_array_append_##TYPE(struct mdata_array_##TYPE* self_array,TYPE value){ \
		if(self_array->length >= self_array->size){		\
			mdata_array_resize_##TYPE(self_array,1);	\
			self_array->list[self_array->length++] = value;	\
		} else {						\
			self_array->list[self_array->length++] = value;	\
		}							\
	}								\
									\
	void mdata_array_append_arr_##TYPE(struct mdata_array_##TYPE* self_array, \
					   struct mdata_array_##TYPE* array2){ \
		int append_size = self_array->size - array2->size;	\
		append_size = abs(append_size);				\
		if(append_size != 0)					\
			mdata_array_resize_##TYPE(self_array,append_size); \
		for(size_t i = self_array->length;i < self_array->length+append_size;i++) \
			self_array->list[self_array->length++] = array2->list[i]; \
	}								\
									\
	size_t mdata_array_search_##TYPE(struct mdata_array_##TYPE* self_array,TYPE value){ \
		size_t mid = self_array->length/2;			\
		for(size_t i = 0; i < mid;i++){				\
			if(self_array->list[i] == value)		\
				return i;				\
			else if(self_array->list[self_array->length - i] == value) \
				return self_array->length - i;		\
		}							\
		return -1;						\
	}								\
									\
	void mdata_array_remove_##TYPE(struct mdata_array_##TYPE* self_array,size_t index){ \
		for(size_t i = index; i< self_array->length; i++)	\
			self_array->list[i] = self_array->list[i+1];	\
		self_array->length--;					\
	}								\
									\
	void mdata_array_swap_##TYPE(struct mdata_array_##TYPE* self_array,size_t index,size_t index2){ \
		TYPE tmp = self_array->list[index];			\
		self_array->list[index] = self_array->list[index2];	\
		self_array->list[index2] = tmp;				\
	}								\
									\
	void mdata_array_insert_##TYPE(struct mdata_array_##TYPE* self_array,size_t index,TYPE value){ \
		if(!(index < 0)){					\
			if(!(index >= self_array->size)){		\
				mdata_array_resize_##TYPE(self_array,1); \
				for(size_t i = self_array->length;i> index;i--) \
					self_array->list[i] = self_array->list[i-1]; \
				self_array->list[index] = value;	\
				self_array->length++;			\
			} else {					\
				for(size_t i = self_array->length;i > index;i--) \
					self_array->list[i] = self_array->list[i+1]; \
				self_array->list[index] = value;	\
				self_array->length++;			\
			}						\
		}							\
	}								\
									\
	void mdata_array_reverse_##TYPE(struct mdata_array_##TYPE* self_array){\
		size_t mid = (self_array->length - 1)/2;		\
		for(size_t i = 0;i< mid; i++)				\
			mdata_array_swap_##TYPE(self_array,i,(self_array->length - (i+1))); \
	}
	

#define mdata_array_new(TYPE,SIZE)					\
	{								\
		.list = (TYPE*)malloc(SIZE * sizeof(TYPE)),		\
			.size = SIZE,					\
			};

#define mdata_array(TYPE)			\
	struct mdata_array_##TYPE	

#endif


/*void (*print_##TYPE)(struct mdata_array_##TYPE* self_array);	\*/ 
		/* bool (*isEmpty)(struct mdata_array_##TYPE* mdata_self_array);	\ */
	        /* TYPE (*get)(struct mdata_array_##TYPE* self_array,size_t index); \ */
		/* void (*set)(struct mdata_array_##TYPE* self_array,size_t index,TYPE value); \ */
		/* void (*append)(struct mdata_array_##TYPE* self_array,TYPE value); \ */
		/* void (*append_arr)(struct mdata_array_##TYPE* self_array,struct mdata_array_##TYPE* array2); \ */
		/* size_t (*search)(struct mdata_array_##TYPE* self_array,TYPE value); \ */
		/* void (*remove)(struct mdata_array_##TYPE* self_array,size_t index); \ */
		/* void (*insert)(struct mdata_array_##TYPE* self_array,size_t index,TYPE); \ */
		/* void _(*sw_ap)(struct mdata_array_##TYPE* self_array,size_t index,size_t index2); \ */
		/* void (*reverse)(struct mdata_array_##TYPE* self_array);	\ */
		/* void (*resize)(struct mdata_array_##TYPE* self_array,size_t add_size); \ */

	/* 								\ */
	/* struct mdata_array_##TYPE 
	/* 		.isEmpty = isEmpty_##TYPE,			\ */
	/* 		.get = mdata_get_##TYPE				\ */
	/* 		.set = set_##TYPE				\ */
	/* 		.append = mdata_append_##TYPE				\ */
	/* 		.append_arr = append_arr_##TYPE			\ */
	/* 		.search = search_##TYPE				\ */
	/* 		.remove = remove_##TYPE				\ */
	/* 		.insert = mdata_insert_##TYPE				\ */
	/* 		.swap = swap_##TYPE				\ */
	/* 		.reverse = reverse_##TYPE			\ */
	/* 		.resize = mdata_array_resize_##TYPE				\ */
    	/* &print_##TYPE					*/      
