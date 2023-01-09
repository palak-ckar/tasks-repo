#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Product
{
    char name[50];
    int id;
    int cost;
    struct Product *next;
};
void insertion(struct Product **head_of_node)
{
    struct Product *new_product = (struct Product*)malloc(sizeof(struct Product));
    char n[50];
    int product_id, price;
    printf("Enter Product name, id and price\n");
    scanf("%s", &n);
    scanf("%d%d",&product_id, &price);
    strcpy(new_product->name, n); 
    new_product->id = product_id; 
    new_product -> cost = price;
    new_product->next = (*head_of_node);
    (*head_of_node)=new_product;
    printf("Data entered!\n");
}
void printll(struct Product *head_of_node)
{
    while(head_of_node!=NULL)
    {
        printf("%s\t%d\t%d\n", head_of_node->name, head_of_node->id, head_of_node->cost);
        head_of_node=head_of_node->next;
    }
}
void searching(struct Product *head_of_node)
{
    char search_name[50];
    printf("Enter the name you want to search for: ");
    scanf("%s", &search_name);
    struct Product *temp_product = head_of_node;
    while(temp_product!=NULL)
    {
        int result = strcmp(temp_product->name, search_name);
        //printf("%d\n", result);
        if(result == 0)
        {
            printf("%s\t%d\t%d\n", temp_product->name, temp_product->id, temp_product->cost);
        }
        temp_product=temp_product->next;
    }
}
void update(struct Product *head_of_node)
{
    int product_id;
    printf("Enter the id you want to update: ");
    scanf("%d", &product_id);
    struct Product *new_product = head_of_node;
    while(new_product!=NULL)
    {
        if(new_product->id == product_id)
        {
            char new_name[50]; int new_price;
            printf("Enter Product name: ");
            scanf("%s", &new_name);
            strcpy(new_product->name, new_name); 
            printf("Enter Product price: ");
            scanf("%d", &new_price);
            new_product->cost = new_price;
        }
        new_product=new_product->next;
    }
}
void deletion(struct Product **head_of_node)
{
    int delete_id;
    printf("Enter the id you want to delete: ");
    scanf("%d", &delete_id);
    
    struct Product *new_product = *head_of_node;
    struct Product *prev;
    if (new_product != NULL && new_product->id == delete_id)
    {
        *head_of_node = (new_product->next);
        free(new_product);
        return;
    };
    while (new_product != NULL && new_product->id != delete_id)
    {
        prev = new_product;
        new_product = new_product->next;
    }
    if (new_product == NULL)
    {
        printf("No Product with id %d\n", delete_id);
        return;
    }
    prev->next = new_product->next;
    free(new_product);
}
void saving(struct Product *head_of_node)
{
    FILE *fp = fopen("product.txt", "w");
    fprintf(fp, "Product name\tProduct ID\tPrice\n");
    while(head_of_node!=NULL)
    {
        fprintf(fp, "%s\t%d\t%d\n", head_of_node->name, head_of_node->id, head_of_node->cost);
        head_of_node=head_of_node->next;
    }
    fclose(fp);
    printf("Data added!\n");
    printf("\nThe file now contains:\n");
    char arr[255];
    //struct Product *read;
    FILE *fo = fopen("product.txt", "r");
    while(fgets(arr, 255, (FILE*)fo))
    {
        printf(arr);
        //read=read->next;
    }
    fclose(fo);
    printf("\n");
}
int main()
{
    int choice;
    struct Product *head=NULL;
    struct Product *first = (struct Product*)malloc(sizeof(struct Product));
    strcpy(first->name, "Microsoft"); first->id = 4401; first -> cost = 55000;
    head = first;
    first->next = NULL;
    
    while(choice!=7)
    {
        printf("Enter your choice:\n1: Insertion of details\n2: Searching the details with name\n3: Updating the data using product id\n4: Deletion of details\n5: Print the details\n6: Save the details into a file named Product.txt \n7: Exit\n");
        scanf("%d", &choice);
        if(choice == 1)
        {
            insertion(&head);
        }
        else if(choice == 2)
        {
            searching(head);
        }
         else if(choice == 3)
         {
            update(head);
         }
                
        else if(choice == 4)
        {
            deletion(&head);
        }
        else if(choice == 5)
        {
            printll(head);
        }
        else if(choice == 6)
        {
            saving(head);
        }
        else if(choice == 7)
        {
            printf("You have opted for exit!\n");
        }
        else
        {
            printf("Invalid option!\n");
        }
    }
}
