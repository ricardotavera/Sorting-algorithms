
#include <stdio.h>
#include "iostream"
#include <ctime>

using namespace std;

int rand_seed=10;

/* from K&R
 - produces a random number between 0 and 32767.*/
int rand()
{
    rand_seed = rand_seed * 1103515245 + 12345;
    return (unsigned int)(rand_seed / 65536) % 32768;
}


void insertion_sort(int a[], int n)
{
    int key, s, r;
    
    for(r=1; r<n; r++)
    {
    	key = a[r];
    	s = r-1;
    	
    while(s>=0 && a[s]>key)
     {
		a[s+1] = a[s];
		s--;
	 }
	 
	   a[s+1] = key;
	}
	
}

int main()
{
	int size;
    unsigned t0, t1;
    for(int k=1; k<=50; k++)
    {    
         size = 1000*k;
         int a[size];
    	
    	//Fill array
    	 for(int i=0; i<size; i++)
        {
        a[i] = rand();
        }
        rand_seed=10;
    	 t0=clock();
         insertion_sort(a,size);
         t1 = clock();
         
         
         double time = (double(t1-t0)/CLOCKS_PER_SEC);
         cout <<time<< endl;
    }
    
    return 0;
}


