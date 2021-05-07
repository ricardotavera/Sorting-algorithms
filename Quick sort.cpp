#include <stdio.h>
#include "iostream"
#include <sys/time.h>

using namespace std;



int rand_seed=10;

/* from K&R
 - produces a random number between 0 and 32767.*/
int rand()
{
    rand_seed = rand_seed * 1103515245 + 12345;
    return (unsigned int)(rand_seed / 65536) % 32768;
}


int partition (int a[], int low, int high)
{
    int pivot = a[high];  // selecting last element as pivot
    int i = (low - 1);  // index of smaller element
    int t;
    for (int j = low; j <= high- 1; j++)
    {
        // If the current element is smaller than or equal to pivot
        if (a[j] <= pivot)
        {
            i++;    // increment index of smaller element
            
            t = a[i];
            a[i] = a[j];
            a[j] = t;
			
        }
    }
             t = a[i+1];
            a[i+1] = a[high];
            a[high] = t;
	
    return (i + 1);
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    
    {
        // pivot_index is partitioning index, arr[pivot_index] is now at correct place in sorted array
        int pivot_index = partition(arr, low, high);

        quick_sort(arr, low, pivot_index - 1);  // Before pivot_index
        quick_sort(arr, pivot_index + 1, high); // After pivot_index
    }
}

int main()
{   

    //Declaration
    double time;
    int size;
    unsigned t0, t1;
    
    
    //This for works like all executions form 1000 to 50000
    for(int k=1; k<=50; k++)
    {   
         rand_seed=10;
         size = 1000*k;
         int a[size];
    	
    	//Fill array
    	 for(int j=0; j<size; j++)
        {
        a[j] = rand();
        }
        
        
     
     
     // Here beguin the cronometer, run algorithm, stop time and clacutate execution time;
     t0 = clock();
     quick_sort(a,0,size-1);
     t1 = clock();
     time = (double(t1-t0)/CLOCKS_PER_SEC);
     
     cout<<time<<endl;
     
    
     
     
    

    }
return 0;
}
