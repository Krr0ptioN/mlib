/* template <typename TYPE>
 * class array {
 */

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#ifndef ARRAY_H
#define ARRAY_H

typedef long int index_t;

#define mdata_array(TYPE)			\
	struct mdata_array_##TYPE



#define mdata_array_template(TYPE)					\
	struct mdata_array_##TYPE {					\
		TYPE *list;						\
	        index_t length;						\
	        index_t size;						\
		bool (*isEmpty)(struct mdata_array_##TYPE *);		\
		TYPE (*get)(struct mdata_array_##TYPE *,index_t);	\
		void (*set)(struct mdata_array_##TYPE *,index_t,TYPE);	\
		void (*resize)(struct mdata_array_##TYPE *,index_t);	\
		void (*append)(struct mdata_array_##TYPE *,TYPE);	\
		void (*append_arr)(struct mdata_array_##TYPE *,		\
				   struct mdata_array_##TYPE *);	\
	        index_t (*search)(struct mdata_array_##TYPE *,TYPE);	\
		void (*remove)(struct mdata_array_##TYPE *,index_t);	\
		void (*swap)(struct mdata_array_##TYPE *,index_t,index_t); \
		void (*insert)(struct mdata_array_##TYPE *,index_t,TYPE); \
		void (*reverse)(struct mdata_array_##TYPE *);		\
		void (*shiftRight)(struct mdata_array_##TYPE *);	\
		void (*shiftLeft)(struct mdata_array_##TYPE *);		\
		TYPE (*pop_back)(struct mdata_array_##TYPE *)		\
		TYPE (*pop_front)(struct mdata_array_##TYPE *)		\
		void (*push_back)(struct mdata_array_##TYPE *,TYPE)	\
		void (*push_front)(struct mdata_array_##TYPE *,TYPE)	\
		void (*delete_self)(struct mdata_array_##TYPE *);	\
	};								\
									\
	/* Method */							\
	bool mdata_array_isEmpty_##TYPE(struct mdata_array_##TYPE * self){ \
		if(self->length == 0)					\
			return true;					\
		else							\
			return false;					\
	}								\
									\
        TYPE mdata_array_get_##TYPE(struct mdata_array_##TYPE* self,index_t index){\
		if(index <= self->length){				\
			if(index < 0)					\
				return self->list[length + index];	\
			else						\
				return self->list[index];		\
		} else {						\
			return 0;					\
		}							\
	}								\
									\
	void mdata_array_set_##TYPE(struct mdata_array_##TYPE* self	\
				    ,index_t index                      \
			,TYPE value){					\
	        self->list[index] = value;				\
	}								\
									\
	void mdata_array_resize_##TYPE(struct mdata_array_##TYPE* self	\
			   ,index_t add_size){				\
		TYPE* tmp = (TYPE*)malloc(self->size + add_size);	\
		for(index_t i = 0; i < self->length;i++)		\
			tmp[i] = self->list[i];				\
		free(self->list);				        \
	        self->list = tmp;					\
									\
	}								\
									\
	void mdata_array_append_##TYPE(struct mdata_array_##TYPE* self,TYPE value){ \
		if(self->length >= self->size){				\
			mdata_array_resize_##TYPE(self,1);		\
		        self->list[self->length++] = value;		\
		} else {						\
		        self->list[self->length++] = value;		\
		}							\
	}								\
									\
	void mdata_array_append_arr_##TYPE(struct mdata_array_##TYPE* self, \
					   struct mdata_array_##TYPE* other){ \
		int append_size = self->size - other->size;		\
		append_size = abs(append_size);				\
		if(append_size != 0)					\
			mdata_array_resize_##TYPE(self,append_size);	\
		for(index_t i = self->length;i < self->length+append_size;i++) \
		        self->list[self->length++] = other->list[i];	\
	}								\
									\
        index_t mdata_array_search_##TYPE(struct mdata_array_##TYPE* self,TYPE value){ \
	        index_t mid = self->length/2;				\
		for(index_t i = 0; i < mid;i++){			\
			if(self->list[i] == value)			\
				return i;				\
			else if(self->list[self->length - i] == value)	\
				return self->length - i;		\
		}							\
		return -1;						\
	}								\
									\
	void mdata_array_remove_##TYPE(struct mdata_array_##TYPE* self,index_t index){ \
		for(index_t i = index; i< self->length; i++)		\
		        self->list[i] = self->list[i+1];		\
	        self->length--;						\
	}								\
									\
	void mdata_array_swap_##TYPE(struct mdata_array_##TYPE* self,	\
				     index_t index,index_t index2){	\
		TYPE tmp = self->list[index];				\
	        self->list[index] = self->list[index2];			\
	        self->list[index2] = tmp;				\
	}								\
									\
	void mdata_array_insert_##TYPE(struct mdata_array_##TYPE* self,	\
				       index_t index,TYPE value){	\
		if(!(index < 0)){					\
			if(!(index >= self->size)){			\
				mdata_array_resize_##TYPE(self,1);	\
				for(index_t i = self->length;i> index;i--) \
				        self->list[i] = self->list[i-1]; \
			        self->list[index] = value;		\
			        self->length++;				\
			} else {					\
				for(index_t i = self->length;i > index;i--) \
				        self->list[i] = self->list[i+1]; \
			        self->list[index] = value;		\
			        self->length++;				\
			}						\
		}							\
	}								\
									\
	void mdata_array_reverse_##TYPE(struct mdata_array_##TYPE* self){ \
	        index_t mid = (self->length - 1)/2;			\
		for(index_t i = 0;i< mid; i++)				\
			mdata_array_swap_##TYPE(self,i,(self->length - (i+1))); \
	}								\
	void mdata_array_shiftRight_##TYPE(struct mdata_array_##TYPE* self){ \
		TYPE tmp = self->get(self,-1);				\
		for(index_t i = self->length;i > 0;i--)			\
		        self->list[i] = self->list[i - 1];		\
	        self->list[0] = tmp;					\
	}								\
									\
	void mdata_array_shiftLeft_##TYPE(struct mdata_array_##TYPE* self){ \
		TYPE tmp = self->list[0];				\
		for(index_t i = 0;i < self->length - 1;i++)		\
		        self->list[i] = self->list[i+1];		\
	        self->list[self->length-1] = tmp;			\
	}								\
									\
	void mdata_array_strip_##TYPE(struct mdata_array_##TYPE* self,	\
				      TYPE value){			\
		for(index_t i = 0; i < length;i++){			\
			if(list[i] == value){				\
				for(index_t j = i + 1;j < length;j++){	\
					if(list[j] == value)		\
						remove(j);		\
				}					\
			}						\
		 }							\
	}						         	\
									\
	TYPE mdata_array_pop_back_##TYPE(struct mdata_array_##TYPE* self,\
					 TYPE value){			\
		TYPE tmp = self->get(self,-1);				\
		self->remove(self,length - 1);				\
		return tmp;						\
	}								\
									\
	TYPE mdata_array_pop_front_##TYPE(struct mdata_array_##TYPE* self,\
					  TYPE value){			\
		TYPE tmp = self->get(self,0);				\
		self->remove(self,0);					\
		return tmp;						\
	}								\
									\
	void mdata_array_push_back_##TYPE(struct mdata_array_##TYPE* self, \
					  TYPE value){			\
		self->append(self,value);				\
	}								\
	void mdata_array_push_front_##TYPE(struct mdata_array_##TYPE* self,\
					  TYPE value){			\
		self->insert(self,0,value);				\
	}								\
	void mdata_array_delete_##TYPE(struct mdata_array_##TYPE *self){ \
		free(self->list);					\
	}
	
#define mdata_array_new(TYPE,SIZE)				\
	{						        \
		.list = (TYPE*)malloc(SIZE * sizeof(TYPE)),	\
		.size = SIZE,				        \
		.isEmpty = mdata_array_isEmpty_##TYPE,	        \
		.get = mdata_array_get_##TYPE,			\
		.set = mdata_array_set_##TYPE,			\
		.resize = mdata_array_resize_##TYPE,		\
		.append = mdata_array_append_##TYPE,		\
		.append_arr = mdata_array_append_arr_##TYPE,	\
		.search = mdata_array_search_##TYPE,		\
		.remove = mdata_array_remove_##TYPE,		\
		.swap = mdata_array_swap_##TYPE,		\
		.insert = mdata_array_insert_##TYPE,		\
		.reverse = mdata_array_reverse_##TYPE,		\
		.shiftRight = mdata_array_shiftRight_##TYPE,	\
		.shiftLeft = mdata_array_shiftLeft_##TYPE,	\
		.strip = mdata_array_strip_##TYPE,	        \
		.pop_back = mdata_array_pop_back_##TYPE,	\
		.pop_front = mdata_array_pop_front_##TYPE,	\
		.push_back = mdata_array_push_back_##TYPE,	\
		.push_front = mdata_array_push_front_##TYPE,	\
		.delete_self = mdata_array_delete_##TYPE,	\
	};


#define mdata_array(TYPE)			\
	struct mdata_array_##TYPE	
#endif
