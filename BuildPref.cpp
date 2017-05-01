/*MIT License

Copyright (c) [2017] [Santokh Singh, Gurjot Singh]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

     |b*_*b|
ROLLSIDE SEARCH (RS)
*/
// SEARCH MIDDLE MAN, TO BE EXECUTED BY PHP WITH ARGUMENTS

#include<iostream>
using namespace std;
#include<semaphore.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdarg.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/stat.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<fstream>



int main() {

int val,coreppid;
      sem_t * sema;
      sema = sem_open("/reconSema",O_CREAT, S_IRUSR | S_IWUSR, 1);
      sem_getvalue(sema,&val);
      if(val==1){sem_wait(sema);}
      sem_getvalue(sema,&val);
      if(val==0){   cout<<"\n Search is locked. Build Preference activated ...\n"; }
      else{ cout<<"\n Search is still in open state. Try Again  \n";}
      sem_close(sema);

	ifstream mmlogr;
	mmlogr.open ("SearchPPID.txt");
	mmlogr>>coreppid;
	mmlogr.close();
        val=kill(coreppid, SIGURG);
        if(val==0){ cout<<"Build Signal sent...";}
        else { cout<<"Signal Failed...";}
    
     return 0;

}






















