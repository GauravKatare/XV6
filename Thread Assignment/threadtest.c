#include "types.h"
#include "stat.h"
#include "user.h"

#define PGSIZE 4096


uint shared=0;
//uint temp;

struct add {
	int id;

	
};



void test(void* ab){
	int i, j;

	int temp;
	struct add * ptr = (struct add *) ab;
	printf(1,"thread id = %d started\n", ptr->id);
	for(i=0;i<10;i++){
		for(j=0; j<400000; j++) 
			__asm("nop")	;		
		temp = shared;
		for(j=0; j<400000; j++) ;		
		sleep(5);
		temp = temp+1;
		sleep(5);
		for(j=0; j<400000; j++) 
			__asm("nop")	;		
		shared=temp;
	}
	
	printf(1,"thread id = %d ended\n", ptr->id);

	exit();
}



int main(int argc, char *argv[]) 
{


	struct add a1;
	struct add a2;
	struct add a3;

	a1.id = 1;

	a2.id = 2;

	a3.id = 3;
 
  printf(1, "\nbalance created...");
  void *s1, *s2, *s3;
  int t1, t2, t3, r1, r2, r3;
  int * retv1, * retv2, * retv3;

  s1 = malloc(PGSIZE*2); //stack to be used by the thread
  s2 = malloc(PGSIZE*2); //stack to be used by the thread
  s3 = malloc(PGSIZE*2); //stack to be used by the thread, we can add this functionality in the kernel also
  
  if((uint)s1 % PGSIZE) //to make the stack page aligned
  	s1 = s1 + (PGSIZE - (uint)s1 % PGSIZE);
  
  if((uint)s2 % PGSIZE) //to make the stack page aligned
  	s2 = s2 + (PGSIZE - (uint)s2 % PGSIZE);

  if((uint)s3 % PGSIZE) //to make the stack page aligned
  	s3 = s3 + (PGSIZE - (uint)s3 % PGSIZE);
  
  printf(1, "\nstacks created...");

  t1 = thread_create(test , (void*)&a1, (void *)s1);
    printf(1, "\nt1 created...");

  t2 = thread_create(test, (void*)&a2, (void *)s2); 
  printf(1, "\nt2 created...");

  t3 = thread_create(test, (void*)&a3, (void *)s3); 
  printf(1, "\nt3 created...");

  r1 = thread_join(t1, (void **) &retv1);
    printf(1, "\nr1 joined...%d", r1);

  r2 = thread_join(t2, (void **) &retv2);
    printf(1, "\nr2 joined... %d", r2);

  r3 = thread_join(t3, (void **) &retv3);
    printf(1, "\nr3 joined... %d", r3);

  printf(1, "\nThreads finished: (%d):%d, (%d):%d, (%d):%d, shared balance : %d\n", 
      t1, *retv1, t2, *retv2, t3, *retv3, shared);

  exit();

}
