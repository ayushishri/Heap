#include<stdio.h>
#include<stdlib.h>
typedef struct {
   int *store;
   unsigned int size;
   unsigned int end;
} HeapType;

int initHeap (HeapType *pHeap,int size){
    printf("initHeap:\n");
    if (pHeap==NULL){
        printf("    if statement\n");
        return -1;
    }
    (pHeap->store)=(int*)malloc(size*sizeof(int));
    printf("    end malloc\n");
    pHeap->size=size;
    pHeap->end=size-1;
    printf("    end init\n");
    return 0;
}


int inorder  (HeapType *pHeap, int **output, int *o_size)
{
    int size = 0;
    int i = 0;
    int temp = 0;
    int j = 0;
    int smallest = 0;
    int minlocation = 0;
    if (pHeap == NULL)
        return -1;
    if (output == NULL)
        return -1;
    if (o_size == NULL)
        return -1;
   printf("inorder:\n");
    *o_size = (pHeap->end) + 1;
    size =pHeap->size;
    (*output) = (int*)malloc(sizeof(int) * size);
    printf("\twhile loop:\n");
    /*While loop*/
    while (size >= 0)
    {
        /*find smallest element*/
        printf("size:%d\n",size);
        smallest =(pHeap->store)[0];
        printf("smallestbeforeFOR:%d\t",(pHeap->store)[0]);
        for (i = 0;i < size;i++)
        {
            if ((pHeap->store)[i] < smallest)
            {
                smallest = (pHeap->store)[i];
                minlocation = i;
            }
        }
        printf("smallest:%d,Location:%d\n",smallest,minlocation);
        /*swap smallest with end*/
        if (minlocation!=size-1){
            temp = (pHeap->store)[minlocation];
            (pHeap->store)[minlocation] = (pHeap->store)[pHeap->end];
            (pHeap->store)[pHeap->end] = temp;
        }
        /*assign to output array*/
        *output[j] = smallest;
        j += 1;
        size -= 1;

        /*print array*/
        for (i=0;size<7;i++){
            printf(" %d ",(pHeap->store)[i]);

        }
    }
    return 0;
}




int preorder (HeapType *pHeap, int **output, int *o_size);

int postorder(HeapType *pHeap, int **output, int *o_size);


int main ()
{
    HeapType input;
    int *output;
    int size=0;
    int i=0;


    initHeap(&input,7);

    printf("\n");
    input.store[0]=24;
    input.store[1]=15;
    input.store[2]=7;
    input.store[3]=-5;
    input.store[4]=3;
    input.store[5]=0;
    input.store[6]=6;
    printf("end assigning values\n");/*
    for (i=0;i<7;i++){
        printf("in for");
        printf("%d\t",input.store[i]);
    }*/


    inorder(&input,&(output),&size);



    return 0;
}
                                          