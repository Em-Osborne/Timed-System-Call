// for this I used the man pages for open() and 
// linuxhint.com/gettimeofday_c_language/#:~:text=The%20gettimeofday()%20function%20set,of%20microseconds%20elapsed%20from%20tv_sec.

#include <time.h> 
#include <sys/time.h> // for gettimeofday
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>

using namespace std;

int main(){
	struct timeval start, end;
	gettimeofday(&start, NULL);

	int x = open("main.txt", 0);

	gettimeofday(&end, NULL);
	
	double time_taken = (end.tv_usec - start.tv_usec) * 1e-3;
	std::cout << "Open() system call took: " << time_taken << " micro seconds.\n";
	
	return 0;
}
