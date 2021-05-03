#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZEOFFILE 785
#define NUMBEROFIMAGES 1000

typedef struct
{
    int img_arr [SIZEOFFILE];
} image;

typedef struct
{
    image data;
    int key;

} data_item;

image Imgs [NUMBEROFIMAGES];
image arr_test [5];
data_item hash_table [NUMBEROFIMAGES];
int noOfCollisions=0;
int inserted_keys=0;
int hashCode(image img)
{
    int hash=0;
    int sum=0;
    int i;
    int rowno=1;
    for(i=0; i<SIZEOFFILE; i++)
    {
        if(i%28==0)
        {
            hash+=(sum*rowno);
            sum=0;
            rowno++;
        }
        sum=sum+img.img_arr[i];
    }
    return hash;
}
int get(image img)
{
    int i,j,av=0;
    for (i=0; i<NUMBEROFIMAGES; i++)
    {
        for (j=0; j<SIZEOFFILE-1; j++)
            if (hash_table[i].data.img_arr[j] != img.img_arr[j])
            {
                av =0;
                break;
            }
            else av=1;

        if (av==1) return hash_table[i].data.img_arr[SIZEOFFILE-1];
    }

    return -1;
}
int put (int key, image current_image)
{
    int ind = key%NUMBEROFIMAGES;
    int i,j;

    for (i=0; i<SIZEOFFILE; i++)
        if (hash_table[i].key == key) return key;

    if (hash_table[ind].key == NULL ||hash_table[ind].key == -1)
    {
        for (i=0; i<SIZEOFFILE; i++)
            hash_table[ind].data.img_arr[i] = current_image.img_arr[i];
        hash_table[ind].key = key;
        inserted_keys++;
        return NULL;
    }

    else
    {
        for (j=0; j<NUMBEROFIMAGES ; j++)
            if (hash_table[j].key == NULL ||hash_table[j].key == -1)
            {
                for (i=0; i<SIZEOFFILE; i++)
                    hash_table[j].data.img_arr[i] = current_image.img_arr[i];
                hash_table[j].key = key;
                noOfCollisions++;
                return NULL;
            }
    }
    return -1;
}



int removee(image img)
{
    int i,j,av=0,ID;
    for (i=0; i<NUMBEROFIMAGES; i++)
    {
        for (j=0; j<SIZEOFFILE-1; j++)
            if (hash_table[i].data.img_arr[j] != img.img_arr[j])
            {
                av =0;
                break;
            }
            else av=1;

        if (av==1)
        {
            ID = hash_table[i].data.img_arr[SIZEOFFILE-1];
            for (j=0; j<SIZEOFFILE; j++)
                hash_table[i].data.img_arr[j] = -1;
            hash_table[i].key = -1;
            return ID;
        }
    }

    return -1;

}
void ReadFile()
{
    FILE *f;
    f=fopen("MNIST.txt","r");

    if(f!=NULL)
    {
        int i=0;
        int size=0;
        while(!feof(f))
        {
            fscanf (f, "%d ", &Imgs[size].img_arr[i]);

            if(i==SIZEOFFILE)
            {

                i=0;
                size++;
            }
            i++;
        }

        fclose(f);
    }
}
void ReadTest()
{
    FILE *t;

    t=fopen("test_data.txt","r");

    if(t!=NULL)
    {
        int i=0;
        int size=0;
        while(!feof(t))
        {
            fscanf (t, "%d ", &arr_test[size].img_arr[i]);
            if(i==SIZEOFFILE-1)
            {
                i=0;
                size++;
            }
            i++;
        }


        fclose(t);
    }

}

int main()
{
    int i;
    clock_t begin;
    begin = clock();
    ReadFile();
    ReadTest();
    for (i=0; i<NUMBEROFIMAGES; i++)
        put(hashCode(Imgs[i]),Imgs[i]);
    begin= clock()-begin;
    printf("time needed for execution=%f\n", ((float)begin)/CLOCKS_PER_SEC);
    printf("Number of collisions : %d\n",noOfCollisions);
    printf("Inserted keys: %d", inserted_keys);
    printf("\n1-Remove Images \n2-Search for Images \nPlease select one\n");

    int x;
    scanf("%d",&x);
    int y;
    switch (x)
    {
    case 1 :
        for (i=0; i<5; i++)
        {
            y = removee(arr_test[i]);
            if (y!=-1) printf("Image is available and deleted at ID:%d\n",y);
            else printf("Image is not available!\n");

        }
        break;

    case 2 :
        for (i=0; i<5; i++)
        {
            y = get(arr_test[i]);
            if (y!=-1) printf("Image is available at ID:%d\n",y);
            else printf("Image is not available!\n");
        }
        break;
    default:
        printf("Invalid choice");
    }


    return 0;
}


