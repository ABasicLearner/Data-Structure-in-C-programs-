#include<stdio.h>
int RecurBinarySearch(int*, int, int, int);
void main()
{
    int i, n, a[20], key, position;
    printf("\nHow many elements in the array?: ");
    scanf("%d", &n);
    printf("\nEnter elements of the array: ");
    for(i = 0; i < n; i++)
    {
        printf("\na[%d] = ", i);
        scanf("%d", &a[i]);
    }
    printf("Enter a key you want to search in the given array: ");
    scanf("%d", &key);
    position = RecurBinarySearch(a, 0, n-1, key);
    if(position == -1)
        printf("\nEntered element not found!");
    else
        printf("\nElement %d found at position %d ", key, position);
}

int RecurBinarySearch(int a[], int lb, int ub, int key)
{
    int mid;
    if(lb <= ub)
    {
        mid = (lb + ub)/2;
        if(a[mid] == key)
            return mid;
        else
            if(key < a[mid])
                return  RecurBinarySearch(a, lb, mid-1, key);
            else 
                return RecurBinarySearch(a, mid+1, ub, key);
    }
        return -1;
}
