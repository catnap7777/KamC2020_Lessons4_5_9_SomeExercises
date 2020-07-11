/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//Exercises Lesson 4 - page 89
//1.
/*
#include <stdio.h>
int x,y;int main(){printf(
"\nEnter two numbers");scanf(
"%d,%d",&x,&y);printf(
        "\n\n\%d is bigger",(x>y)?x:y);return 0;}
*/
//2.
/*#include <stdio.h>
int x,y;
int main(void)
{
    //input needs to be separated by a comma or pgm wont pick up value for "y"; it thinks it's a 0 instead
    // if there's a space or any other character between x and y
    printf("\nEnter two numbers separated by a comma as the delimiter\n");
    scanf("%d,%d",&x,&y);
    printf("\n\n\%d is bigger\n",(x>y)?x:y);
    return 0;}
 */
//4. & 5.

/*#include <stdio.h>

int x,y=0;
int main(void)
{
    printf ("Enter value for x:\n");
    scanf("%d", &x);
    printf("\n%d is 'x'\n",x);
    printf("\n%d is 'y'\n",y);

    //notice use of 'extra parenthesis around each expression (x>=)); readability and or precedence?
    y = ((x>=1) && (x<=20))? x:y;
    printf("\nWhat is 'y' now? Was 'x' between 1 and 20?\n",x);
    printf("\n%d is 'y'\n",y);

    //            ************ OR ************
    //Another way to write the above code with and 'if statement'
    //
    //notice use of 'extra parenthesis around each expression (x>=)); readability and or precedence?
    //if ((x>=1) && (x<=20))
    //{
    //    y = x;
    //    printf("\n'x' is between 1 and 20, therefor 'y' is now set to 'x'\n");
    //    printf("\n'y' is equal to %d\n",y);

    //}
return 0;
}
*/
//6.
/*#include <stdio.h>

int x;
int main(void)
{
    printf ("Enter value for x:\n");
    scanf("%d", &x);
    printf("\n%d is 'x'\n",x);
    if ((x<1)&&(x>10))
        printf("why would this stupid statement even work?\n");

    return 0;
}
*/
//10.
/*
#include <stdio.h>

int x=7;
int main(void)
{

   //notice the x==1; if you use x=1, this is the assignment of 1 to x and is thus always 'true'
   // you need '==' to do a comparison
   //if (x=1) **** this statement is WRONG
   if(x==1)
       printf("x equals 1\n");
   else
       printf("x does not equal 1\n");

   return 0;
}
 */
//Exercises Lesson 5 - page 117
//9.

#include <stdio.h>

int product(int x, int y);
int divide_em(int a, int b);

int main(void)
{
    int number1 = 10, number2 = 5;

    int x,y,z;

    x=product(number1, number2);
    y=divide_em(number1,number2);
    z=divide_em(number1,0);

    printf("\nNumber1 is %d and number2 is %d",number1,number2);
    printf("\nnumber1 * number2 is %d",x);
    printf("\nnumber1 / number2 is %d",y);

    //printf("\nnumber1 / 0 is %d\n",z); // this is stupid because anything divided by 0 is an error!
    // better way
    if (z == 0)
    // I initially had z=0 which does not work to compare z to 0 because that's the
    // assignment operator
    {
        printf("\nnumber1 / %d is an error because anything divided by zero is an error!\n",z);
    }
    else
        printf("\nnumber1 / number2 is %d\n",z);

    return 0;
}

int product(int x, int y)
{
    return (x*y);
}

int divide_em(int a, int b)
{
    int answer = 0;

    if (b == 0)
        answer = 0;
    else
        answer = a/b;

    return answer;
}
 

//11. - Recursion example to take value of 3 to the power of another number

/*#include <stdio.h>
int three_powered(int power);

int main(void)
{
    int a = 4;
    int b = 9;

    printf("\n3 to the power of %d is %d\n",a,three_powered(a));

    printf("\n3 to the power of %d is %d\n\n",b,three_powered(b));

    return 0;
}

int three_powered(int power)
{
    if (power <1)
        return(1);
    else
        return(3*three_powered(power-1));

}

*/
//Exercises Lesson 9 - page 211
//7. and 8.

/*#include <stdio.h>

#define MAX1 5
#define MAX2 8

int array1[MAX1] = {1,2,3,4,5};
int array2[MAX2] = {1,2,3,4,5,6,7,8};
int total;

int sumarrays(int x1[], int len_x1, int x2[], int len_x2);

int main(void)
{
    total = sumarrays(array1, MAX1, array2, MAX2);
    printf("The total is %d\n", total);

    return 0;
}

//functions sumarrays()
int sumarrays(int x1[], int len_x1, int x2[], int len_x2)
{
    int total=0, count=0;

    for(count=0; count<len_x1; count++)
        total+= x1[count];
    for(count=0; count<len_x2; count++)
        total+= x2[count];

    return total;
}
 */
//Exercises Lesson 9 - page 211
//9.
//NOTE: I TRIED TO ADD CODE TO RETURN THE ADDRESS OF THE LOCAL ARRAY TOTAL[]
// FROM THE FUNCTION BUT APPARENTLY YOU CANT DO THIS IS C BECAUSE THE STORAGE FOR THE
// LOCAL ARRAY IS WIPED OUT AFTER THE FUNCTION EXECUTES... SO THE ADDRESS TO IT DOESN'T
// MAKE SENSE ANYMORE.  I COULD PASS AN ACTUAL VALUE/ELEMENT OF THE ARRAY BACK (IE. TOTAL[5] FOR
// EXAMPLE BUT THAT'S IT. MAYBE SOMEWHERE LATER IN THE BOOK IT EXPLAINS THIS BETTER

/*#include <stdio.h>

#define SIZE 10

int ctr2;
int *p_total;

//function prototypes

//sorry, what does the following mean? That two arrays are going to be passed?
//int addarrays(int [], int []);
void addarrays(int [], int []);

int main(void)
{

    int a[SIZE] ={1,1,1,1,1,1,1,1,1,1};
    int b[SIZE] ={9,8,7,6,5,4,3,2,1,0};

    addarrays(a,b);
    //*p_total = addarrays(a,b);

    return 0;
}

void addarrays(int first[], int second[])
{
    //new array to hold the totals
    int total[SIZE];
    //declare pointer to new array and set it equal to
    //  the address of the beginning of the array
    int *ptr_total = &total[0];
    int ctr = 0;

    for(ctr=0; ctr<SIZE; ctr++)
    {
        total[ctr] = first[ctr] + second[ctr];
        printf("\n%d + %d = %d",first[ctr],second[ctr],total[ctr]);
    }
    printf("\n");
}
*/


