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

// This function creates a min heap by compairing the value present in 'i' with its 
// left child -> (i*2) + 1 and right child -> (i*2)+2 and creates min heap recursively
void min_heapify(int *arr, int N, int i) {
    int smallest, left, right;
    smallest = i;//assumes that the node i has the lower values than its children
    left = i * 2 + 1;
    right = i * 2 + 2;
    if( left < N && arr[left] < arr[smallest] ) // if the left children has smaller value assign smallest = left
        smallest = left;
    if( right < N && arr[right] < arr[smallest] )// if the right children has smaller value assign smallest = right
        smallest = right;
    if( smallest != i ) { // if either child has a smaller value we swap the values and do a recursive check for the 
                          //childs and whether they break the min heap property or not
        swap(&arr[smallest], &arr[i]);
        min_heapify(arr, N, smallest);
    }
}

// This function creates a max heap by compairing the value present in 'i' with its 
// left child -> (i*2) + 1 and right child -> (i*2)+2 and creates max heap recursively
void max_heapify(int *arr, int N, int i) {
    int largest, left, right;
    largest = i;//assumes that the node i has the greater values than its children
    left = 2 * i + 1;
    right = 2 * i + 2;
    if(left < N && arr[left] > arr[largest])// if the left children has greater value assign larger = left
        largest = left;
    if(right < N && arr[right] > arr[largest])// if the left children has greater value assign larger = right
        largest = right;
    if(largest != i) {// if either child has a smaller value we swap the values and do a recursive check for the 
                      //childs and whether they break the min heap property or not
        swap(&arr[largest], &arr[i]);
        max_heapify(arr, N, largest);
    }
}

// One may argue why we start from N/2.
// We all know that the leafs maintain the heap property.
// It can be easily proved that of an array of size N array elements arr[N/2 +1],arr[N/2 +2], arr[N] are all leafs in the heap
// This fucntion builds the max heap of the given array recursively
void buildAsc(int *arr, int N) {
    int i;
    for(i=N/2;i>=0;i--) 
        max_heapify(arr, N, i);
}

// This fucntion builds the max heap of the given array recursively
void buildDesc(int *arr, int N) {
    int i;
    for(i=N/2;i>=0;i--)
        min_heapify(arr, N, i);
}

// This fucntion performs heap sort operation by first building heaps and then exchanging the last and the 
// first element and performing the heapify function on the root node again.
// This way we receive a sorted array
void heapSortAsc(int *arr, int N) {
    int i;
    buildAsc(arr, N);
    for(i=N-1;i>=1;i--) {
        swap(&arr[i],&arr[0]);
        max_heapify(arr, i, 0);
    }
}

void heapSortDesc(int *arr, int N) {
    int i;
    buildDesc(arr, N);
    for(i=N-1;i>=1;i--) {
        swap(&arr[i], &arr[0]);
        min_heapify(arr, i, 0);
    }
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

// This is the main driver program
// Note: for better time analysis of Heap sort, use random generator using high values of N
// Time calculated for heap sort excludes the time taken to generate the random array
int main() {
    // declaration and initialization of variables used
    int ch1, ch2, N, *arr, i;
    clock_t start, end; // clock variables to measure time
    double timeTaken;
    // Printing menu
    printf("\n1. Performs Heap Sort in ascending order");
    printf("\n2. Performs Heap Sort in descending order\n");
    printf("\nEnter your choice: ");
    scanf("%d",&ch1);
    printf("\n\nEnter the number of terms of the array: ");
    scanf("%d",&N);
    arr = (int *)calloc(N,sizeof(int));
    printf("\n1. Uses randomly generated numbers");
    printf("\n2. User input\n");
    printf("\nEnter your choice: ");
    scanf("%d",&ch2);
    // Performing operations according to user choice
    switch(ch2) {
        case 1:
            arr = randomGenerator(N);
            switch(ch1) {
                case 1:
                    start = clock();
                    heapSortAsc(arr,N);
                    end = clock();
                    break;
                case 2:
                    start = clock();
                    heapSortDesc(arr,N);
                    end = clock();
                    break;
                default:
                    printf("\nWrong choice entered!");
            }
            break;
        case 2:
            arr = input(N);
            switch(ch1) {
                case 1:
                    start = clock();
                    heapSortAsc(arr,N);
                    end = clock();
                    break;
                case 2:
                    start = clock();
                    heapSortDesc(arr,N);
                    end = clock();
                    break;
                default:
                    printf("\nWrong choice entered!\n");
            }
            break;
        default:
            printf("\nWrong choice Entered!\n");
    }
    if( ch1 < 3 && ch1 >=1 && ch2 < 3 && ch2 >= 1) {
        timeTaken = (double)(end - start) / CLOCKS_PER_SEC;// Calculating time taken by heap sort
        // If you want to print the sorted array uncomment line 176 to 179
        // printf("\nThe sorted array according to the choice entered is: \n");
        // for(i=0;i<N;i++) {
        //     printf("%d ", arr[i]);
        // }
        printf("\n");
        printf("\nTotal time taken to sort the array : %lf",timeTaken); // Total time taken to sort the array in seconds
    }
}