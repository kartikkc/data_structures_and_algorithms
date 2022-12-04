#include <stdio.h>
#include <conio.h>

insert_begining(int element)
{
    int array[10];
    int max;   // size of the array
    int n;     //  number of elements in the array
    if (max > n)
    {
        n+1;
        for(int i = n-1 ; i > 0 ; i--){
            array[i] = array[i-1];
        }
        array[0] = element;
    }
}

insert_position(int pos , int element)
{
    int array[10];
    int max; 
    int n;
    if (max > n){
    if(pos == array[0]){
        insert_begining(element);
    } 
        n+1;
        for (int i = pos-1; i > pos ; i--){
            array[i]=array[i-1];
        }
        array[pos] = element;
    }
}

insert_ending()
{
}

remove_begining()
{
}

remove_position()
{
}

remove_ending()
{
}

display_elements()
{
}

selection_sort()
{
}

bin_search(int number)
{
}

linear_search()
{
}

int main()
{
    int choice;
    int choice2;
    int choice3;
    int choice4;
    int element;
    int pos;
    printf("Programmed to perform operations on Array \n");
    printf(" Enter 1 to Traverse/Show the array \n Enter 2 to Insert the elements in the array \n Enter 3 to Remove the elements from the array \n Enter 4 to Search an element in the array \n Enter 'exit' to exit the program \n");
    printf("Enter your choice\n >");
    scanf("%d", &choice);
main_menu:
    if (choice == 1)
    {
    }
    if (choice == 2)
    {
        printf("You want to insert the element in the array ? \n");
        printf("where you want to insert the element in the array ? \n");
        printf("You can insert element from begining, ending and from a position \n");
        printf(" press 1 to insert element from the begining \n press 2 to remove element from the ending \n press 3 to remove element from the position \n press 'back' to go back to the main menu \n");
        printf("Enter your choice  \n > ");
        scanf("%d \n", &choice3);
        if (choice3 == 1)
        {
            remove_begining();
            display_elements();
        }
        if (choice3 == 2)
        {
            remove_ending();
            display_elements();
        }
        if (choice3 == 3)
        {
            printf("Enter the position from where you want to remove the element \n >");
            scanf("%d \n", &pos);
            remove_position(pos);
            display_elements();
        }
        if (choice3 == "back")
        {
            goto main_menu;
        }
    }
}
if (choice == 3)
{
    printf("You want to remove the element from the array ? \n");
    printf("From where you want to remove the element from the array ? \n");
    printf("You can remove element from begining, ending and from a position \n");
    printf(" press 1 to remove element from the begining \n press 2 to remove element from the ending \n press 3 to remove element from the position \n press 'back' to go back to the main menu \n");
    printf("Enter your choice  \n > ");
    scanf("%d \n", &choice3);
    if (choice3 == 1)
    {
        remove_begining();
        display_elements();
    }
    if (choice3 == 2)
    {
        remove_ending();
        display_elements();
    }
    if (choice3 == 3)
    {
        printf("Enter the position from where you want to remove the element \n >");
        scanf("%d \n", &pos);
        remove_position(pos);
        display_elements();
    }
    if (choice3 == "back")
    {
        goto main_menu;
    }
}
if (choice == 4)
{
    printf("How you want to search the element ?\n");
    printf("We have TWO options ! \n press 1  for Binary Search \n press 2 for Linear search \n 'back' to go back to previous menu");
    printf("Enter your Choice \n > ");
    scanf("%d \n", choice4);
    if (choice4 == 1)
    {
        printf("Enter the Element you want to search \n > ");
        scanf("%d \n", &element);
        bin_search(element);
    }
    if (choice4 == 2)
    {
        printf("Enter the Element you want to search \n > ");
        scanf("%d \n", &element);
        linear_search(element);
    }
    if (choice4 == "back")
    {
        goto main_menu;
    }
}
if (choice == "exit")
{
    goto exit;
}
exit : return 0;
}