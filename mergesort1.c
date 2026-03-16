#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int A[], int left, int mid, int right)
{
    int n1=(mid-left+1);
    int n2=(right-mid);

    int L [n1];
    int R[n2];
    for(int i=0;i<n1;i++)
    {
        L[i]=A[left+i];
    }
    for(int j=0;j<n2;j++)
    {
        R[j]=A[mid+1+j];
    }

    int i=0,j=0,k=left;

    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
        }
        else{
            A[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        A[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        A[k]=R[j];
        j++;
        k++;
    }
}
void mergesort(int A[], int left, int right)
{
    if(left<right)
    {
        int mid=(left+right)/2;

    mergesort(A,left,mid);
    mergesort(A,mid+1,right);
    merge(A,left,mid,right);
    }
}
int main()
{
    clock_t start,end;
    double timet;
    int n;
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    int arr[n];

    printf("Enter the nos. ");

    for(int i=0;i<n;i++)
    {
        arr[i] = rand() % n;
    }

    start=clock();
    mergesort(arr,0,n-1);
    end=clock();

    printf("Sorted Array : ");
    for(int i=0;i<5;i++)
    {
        printf("%d",arr[i]);
    }
    timet=(double)(end-start)*1000/CLOCKS_PER_SEC;
    printf("Time Taken : %f",timet);
}
