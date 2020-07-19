#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
int ticket, pid;
if(argc < 3 ){
printf(2, "Usage: nice pid priority\n" );
exit();
}
pid = atoi ( argv[1] );
ticket = atoi ( argv[2] );
chtk( pid,ticket);
exit();
}
