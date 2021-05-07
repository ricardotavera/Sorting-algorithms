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

void merge(int a[], int f, int h, int l)
{
	int n1,n2;
	n1 = h-f+1;
	n2 = l-h;
	
	int x[n1], y[n2];
	for(int i=0; i<n1; i++)
	{
		x[i] = a[f+i];
	}
	
	for(int j=0; j<n2; j++)
	{
		y[j] = a[h+1+j];
	}
	
	int r, s, t;
	r = 0;
	s = 0;
	t = f;
	
	while(r<n1 && s<n2)
	{
		if(x[r]<=y[s])
		{
			a[t] = x[r];
			r++;
		}else
		{
			a[t] = y[s];
			s++;
		}
		
		t++;
	}
	
	while(r<n1)
	{
		a[t] = x[r];
		r++;
		t++;
	}
	
	while(s<n2)
	{
		a[t] = y[s];
		s++;
		t++;
	}
}

void merge_sort(int a[], int f, int l)
{   
    // h = half of array 
	int h;
	if(l>f)
	{
		h = (int) (f+l)/2;
		merge_sort(a, f, h);
		merge_sort(a, h+1, l);
		merge(a, f, h, l);
	}
	
}




int main()
{   
    int size;
    
    for(int k=1; k<=50; k++)
    {    
         size = k*1000;
         int a[size];
    	
    	 for(int i=0; i<size; i++)
        {
           a[i] = rand();
        }
        rand_seed=10;
         unsigned t0, t1;
    	 t0=clock();
         merge_sort(a,0,size-1);
         t1 = clock();
         double time = (double(t1-t0)/CLOCKS_PER_SEC);
         cout <<time<< endl;
         
	}
    
  return 0;
}
