#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A function that uses pointers to swap the values contained in two variables
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// This is a random generator function. This function populates the given array with random unique elements ranging from 1 to N.
int *randomGenerator(int N) {
    srand(time(NULL)); // Setting the seed to time of the machine for good quality random numbers
    int *checker = (int *)calloc(N+1,sizeof(int));
    int *arr = (int *)calloc(N,sizeof(int));
    int counter = 0;
    int value = 0;
    while(counter < N) {
        value = ((value + rand()) % N) + 1;
        if(checker[value] == 0) {
            checker[value] = 1;
            arr[counter] = value;
            counter++;
        }
    }
    return arr;
}

// This function uses user input to populate the given array dynamically
int *input(int N) {
    int i;
    int *arr = (int *)calloc(N,sizeof(int));
    printf("\nEnter array elements: \n");
    for(i=0;i<N;i++) {
        scanf("%d",&arr[i]);
    }
    return arr;
}

// Displaying the contents of the array
void display(int *arr, int N) {
    int i;
    printf("\nThe arrray elements are : \n");
    for(i=0;i<N;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}


// This is an implementation of Insertion Sort
// We run 2 loops one for using the elements of the array
// and the second loop to check id they are in their desired positon or not.
//We continue the second loop until the element reaches the desired position
void insertionSort(int *arr, int N) {
    int i,j;
    for(i=1;i<N;i++) {
        for(j=i-1;j>=0;j--) {
            if(arr[j+1] < arr[j]) {
                swap(&arr[j+1], &arr[j]);
            }
            else {
                break;
            }
        }
    }
}

// Driver program
// In the driver program the display funcions are commented! If you want to see the contents of the array uncomment it
int main() {
    int ch, N, *arr;
    arr = NULL;
    clock_t start,end;
    double timeTaken;
    printf("\nThis program is an implementation of Insertion Sort\n\n");
    printf("\nEnter the number of terms of the array: ");
    scanf("%d",&N);
    printf("\n1. Uses random values as array elements ranging from 1 to N");
    printf("\n2. User based input\n");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch) {
        case 1:
            arr = randomGenerator(N);
            //display(arr, N);
            break;
        case 2:
            arr = input(N);
            break;
        default:
            printf("\nWrong Choice entered!! Exiting Program.\n");
    }
    if(arr != NULL) {
        start = clock();
        insertionSort(arr,N);
        end=clock();
        //display(arr,N);
        timeTaken = (double)(end-start)/CLOCKS_PER_SEC;
        printf("\nTime taken for Insertion Sort is: %lf seconds.",timeTaken);
    }
}