#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZEOFFILE 784
#define NUMBEROFIMAGES 1000
int inserted_keys;
int noOfCollisions;
typedef struct image
{
    int img_arr[SIZEOFFILE];
} image;
image img;
typedef struct
{
    int key;
    image data;
    struct node *next;
} node;
typedef struct
{
    node *head;
    node *tail;

} arrayitem;

arrayitem array[1000];
int size = 0;
void put(int key, image current_image)
{
    int i = hashCode(current_image);
    i%= NUMBEROFIMAGES ;
    arrayitem list = array[i];
    node* item = (node*) malloc(sizeof(node));
    item->key = key;
    item->data = current_image;
    item->next = NULL;
    if (list.head == NULL )
    {

        array[i].head = item;
        array[i].tail = item;
        size++;
        inserted_keys++;
    }
    else
    {
        array[i].tail->next = item;
        array[i].tail = item;
        size++;
        noOfCollisions++;
    }
}
int removee(image img)
{
    int iHash = hashCode(img);
    iHash %= NUMBEROFIMAGES;
    node *list = array[iHash].head;

    if (list == NULL)
    {
        printf("This index does not exist\n");
        return -1;

    }
    else
    {
        node *c = list;
        node* p = list;

        while(1)
        {
            if(hashCode(c->data)== hashCode(img))
            {
                int key = c->key;
                p->next = c->next;
                free(c);
                return key;

            }
            else
            {
                if(c->next == NULL)
                    return -1;
                else
                {
                    p = c;
                    c = c->next;
                }
            }
        }
    }
}
int get(image img)
{

    int iHash = hashCode(img);
    iHash %= NUMBEROFIMAGES;
    node *list = array[iHash ].head;
    node *n = list;
    while(n!= NULL )
    {
        if(hashCode(n->data) == hashCode(img))
        {
            return n->key;
        }
        else
        {

            n = n->next;
        }
    }
    return -1;
}
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



void ReadFile()
{
    FILE *f;
    int i;
    int key;
    f=fopen("text.txt","r");
    if (f!=NULL)
    {
        while(!feof(f))
        {
            for( i=0; i<SIZEOFFILE+1 ; i++)
            {
                fscanf(f,"%d",&img.img_arr[i]);
            }
            key = img.img_arr[784];
            printf("%d ",key);
            put(key,img);
        }
    }
    fclose(f);
}



void ReadTest(char name[],int flag)
{
    int i;
    int key;
    image newin;
    FILE *f1;

    f1 = fopen(name,"r");
    if (f1!=NULL)
    {
        while(!feof(f1))
        {
            for( i=0; i<SIZEOFFILE; i++)
            {
                fscanf(f1,"%d ",&newin.img_arr[i]);
            }
            if(flag == 1)
            {
                key = removee(newin);
                if(key==-1)
                    printf("Image is not available!!\n");
                else
                    printf("Image is available and deleted at ID = %d\n",key);


            }
            else if(flag==2)
            {
                key = get(newin);
                if(key==-1)
                    printf("\nImage is not available!\n");
                else
                    printf("\nImage is available at ID = %d\n",key);
            }
        }
        fclose(f1);
    }
}

int main()
{
    clock_t begin;
    begin = clock();
    ReadFile();
    begin = clock()-begin;
    printf("\n\n time needed for execution =%f\n", ((float)begin)/CLOCKS_PER_SEC);
    printf("Inserted keys=%d\n",inserted_keys);
    printf("Number Of Collisions=%d\n",noOfCollisions);
    int x;
    char name[50];
    int flag =0;
    printf("size=%d",size);
    printf("\n1-Remove Images \n2-Search for Images \nPlease select one\n");
    scanf("%d",&x);

    printf("Enter The file's name\n");
    scanf("%s",name);
    switch(x)
    {
    case 1:
        flag = 1;
        ReadTest(name,1);
        break;
    case 2:
        ReadTest(name,2);
        break;
    default:
        printf("Invalid choice");
    }
    return 0;
}




