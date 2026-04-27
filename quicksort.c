#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int partition(int a[],int low,int high)
{
    int pivot=a[low];
    int i=low;
    int j=high+1;
    int temp;

    while(1){
        do{
            i++;
        }while(i<=high && a[i]<=pivot);
        do{
            j--;
        }while(a[j]>pivot);

        if(i>=j)
            break;

        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    temp=a[low];
    a[low]=a[j];
    a[j]=temp;

    return j;
}

void quickSort(int a[], int low, int high)
{
    if(low<high)
    {
        int j=partition(a,low,high);
        quickSort(a,low,j-1);
        quickSort(a,j+1,high);
    }
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];  // array size from user

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        a[i]=rand() % n;
    }

    clock_t start=clock();
    quickSort(a, 0, n - 1);
    clock_t end= clock();

    printf("Sorted array:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }

    double timetaken=(double)(end-start)*1000.0 /CLOCKS_PER_SEC;
    printf("Time Taken : %f",timetaken);

    return 0;
}
