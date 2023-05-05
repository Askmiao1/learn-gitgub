#ifndef __LIST__
#define __LIST__
#include <stdio.h>
#include <stdlib.h>

//return  differ from the type struct of begin and member address 
#define offsetof(type, member) (size_t) (&((type*)0)->member)

//return the ptr's type
//ptr = &member
#define container_of(ptr, type, member)\
({\
	const typeof(((type*)0)->member)* _mptr = (ptr);\
	(type*)((char*)_mptr - offsetof(type, member));\
})


struct List{
	struct List* prev;
	struct List* next;
};

//get the struct list point
#define List_entry(ptr, type, member) container_of(ptr, type, member)

//initialize
#define List_head_init(name) {&name, &name}
//use this function,you will gain two list
#define List_head(name) struct List name = List_head_init(name)


//iterate over a list
//
#define List_for_each(pos, head, member)\
for(pos = List_entry((head)->next, typeof(*pos), member);\
 	&pos->member != (head);\
	pos = List_entry(pos->member.next,typeof(*pos), member))
	

static inline void __List_add(struct List* new, struct List* prev, struct List* next){
	next->prev = new;
	new->prev = prev;
	new->next = next;
	prev->next = new;
}


static inline void List_add(struct List* new, struct List* head){
	__List_add(new, head, head->next);

}

static inline void Init_list_head(struct List* head){
	head->next = head;
	head->prev = head;
}

#endif
