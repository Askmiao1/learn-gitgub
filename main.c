#include"List.h"


struct data{
	int a;
	struct List list;
};

int main(int argc, char *argv[]) {

	struct data d;
	d.a = 1;
	Init_list_head(&(d.list));
	
	
	for(int i = 0; i < 9; ++i){
		struct data* t = (struct data*)malloc(sizeof(struct data));;
		t->a = i*100;
		List_add(&(t->list), &(d.list));
	}	
	struct data* ptr;
	int i = 0;
	List_for_each(ptr, &(d.list), list)
	{
		printf("%d ", ptr->a);
	}
	
	struct data* pd = container_of(&d.list, struct data, list);
	return 0;
}
