#include <stdio.h>
#include <stdlib.h>
#define FIFTY 50
	
void shift_element(int *arr, int i){
	int counter = 0;
	int *lastE = arr+i;
	int *Beforelast = lastE -1;
	
	while(counter != i){
	    *lastE = *Beforelast;
	    lastE--;
	    Beforelast--;
	    counter++;
	}
	}
int CounterNum(int *arr,int *ptr){
    int counter = 0;
    while(*ptr < *arr)
    {
	    counter++;
	    arr--;
	}
    return counter;
}
void insertion_sort(int* arr , int len) {
	int *ptr1 = arr;
    int *ptr2 = (arr+1);
    int *end = arr+len;
	int save = 0;
    while(ptr2!= end)  // if my Second pointer : ptr2 is pointing the last element of my array i need to step out
	{   
	    int counter = 0;
	    if(*ptr2 < *ptr1){  // if : the value of ptr2 < value of (ptr2-1) i gonna need to do swaping
            save = *(ptr2);  // save the value of ptr2 before i delete it
	        counter = CounterNum(ptr1,ptr2); //  khow how many stepback i need to put my element 
	        shift_element(ptr2-counter,counter); // and moove the elements 
            *(ptr2-counter) = save;  // put the value of ptr2 at the good place 
	    }
	    ptr1++;
	    ptr2++;
	    }
	    
	}
int nums[FIFTY];
void getNumbers(){
    for (int i = 0; i < FIFTY; i++)
	{
	    scanf("%d",nums+i);
	}
	return;
	}
	
int main(){
    
    getNumbers();
	insertion_sort(nums,FIFTY);
	for (int i = 0; i < FIFTY; i++)
	{
	   printf("%d,",*(nums+i));
	}
	putchar('\n');
	return 0;
	}