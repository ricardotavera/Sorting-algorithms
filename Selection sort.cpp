#include <stdio.h>
#include "iostream"
#include <ctime>

using namespace std;

//#define size 1000
//int a[size];

int rand_seed=10;

/* from K&R
 - produces a random number between 0 and 32767.*/
int rand()
{
    rand_seed = rand_seed * 1103515245 + 12345;
    return (unsigned int)(rand_seed / 65536) % 32768;
}

void selection_sort(int a[], int n)
{
	int i, j, min, temp;
	i=0;
	
	while(i<n-1)
	{
		min = i;
		j = i+1;
		while(j<n)
		{
			if(a[j]<a[min])
			{
				min = j;		
			}
			j++;
				
		}
		
		temp = a[min];
		a[min] = a[i];
		a[i] = temp;
			
		i++;
		
    }
}



int main()
{
    int size;
    unsigned t0, t1;
    for(int k=1; k<=50; k++)
    {    
         size = k*1000;
         int a[size];
    	
    	 for(int i=0; i<size; i++)
        {
        a[i] = rand();
        }
        rand_seed=10;
    	 t0=clock();
         selection_sort(a,size);
         t1 = clock();
         double time = (double(t1-t0)/CLOCKS_PER_SEC);
         cout << time << endl;
         
         
	}
  return 0;
}
