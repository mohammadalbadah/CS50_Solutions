#include <cs50.h>
#include <stdio.h>

int get_height();
void add_block(int row);
void add_space(int row, int height);

int main(void)
{
    //Get the user input for height.
    int height = get_height();
    //Loop through the rows based on height. Always at least 1 row.
    for (int row = 1; row <= height; row++)
    {   
        //Add leading spaces 
        add_space(row, height);
        //Add needed hashes and mid-spacing
        add_block(row);
        //Calling add space and passing 0,3 so it always = 1 spaces for the mid-spacing
        add_space(0, 2);
        add_block(row);
        //Begin a new line for the next row
        printf("\n");
    }
}

int get_height()
{
    //Get the height from the user. If input is greater than 8 or less than 0 keep 
    //prompting
    int height = 0;
    while (height > 8 || height <= 0)
    {
        height = get_int("Height: ");
    }
    return height;
}

void add_block(int row)
{
    //Add number of blocks depending on row number
    int count = 1;
    while (row >= count)
    {
        printf("#");
        count++;
    }
}

void add_space(int row, int height)
{
    //Height minus row will determine how many leading spaces to print.
    //Therefore, determining the number of loops.
    for (int i = 1; i <= height - row; i++)
    {
        printf(" ");
    }
}
