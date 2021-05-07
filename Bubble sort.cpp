#include <stdio.h>
#include "iostream"
#include <ctime>



using namespace std;

//#define size 10000


int rand_seed=10;

/* from K&R
 - produces a random number between 0 and 32767.*/
int rand()
{
    rand_seed = rand_seed * 1103515245 + 12345;
    return (unsigned int)(rand_seed / 65536) % 32768;
}

void bubble_sort(int a[], int n)
{
    int r,s,t;
    for(r=0; r<n-1; r++)
    {
        for(s=0; s<n-r-1; s++)
        {
            if(a[s]>a[s+1])
            {
               t = a[s];
               a[s] = a[s+1];
               a[s+1] = t;
            }
        }
    }
}

int main()
{
    double time;
    int size;
    unsigned t0, t1;
    for(int k=50; k<=50; k++)
    {    
         size = 1000*k;
         int a[size];
         //cout<<"Size: "<<size<<endl;
    	
    	 for(int i=0; i<size; i++)
        {
           a[i] = rand();
           //cout<<i+1<<": "<<a[i]<<endl;
        }
         rand_seed=10;
    	 t0 = clock();
         bubble_sort(a,size);
         t1 = clock();
         
         
         time = (double(t1-t0)/CLOCKS_PER_SEC);
         //cout <<t1<<"========="<<t0<< endl;
		 cout <<time<< endl;
	}
   
   /* cout<<"-----------------------------------------------------"<<endl;

    for(int i=0; i<size; i++)
    {
        cout<<a[i]<<endl;
    }
    */

return 0;
}
