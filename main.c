#include <stdlib.h>
#include <stdio.h>
#include <time.h>




int main(int ac,char **av)
{


    /* Start creating an arbitrary array*/

    int m, n ; /* m-number of storks, n-number of columns*/
    printf ("Creating array");
    /*scanf ("%d%d", &m, &n);*/

    srand(time(NULL));

    m=4+rand()%(10-3);  /* lines  4 to 10 */
    n=5+rand()%(10-4);  /* columns 5 to 10 */

    int a [m][n];

    int i,j, mi=0,lmi,cmi; /* (mi)- the smallest element, (lmi)- line the smallest element, (cmi)- column the smallest element*/



    if(m>3 && n>4)

    {
     printf("\n\n");
    for (i = 0; i<m; i++)
        {
            for (j = 0; j<n; j++)
                {
                    a[i][j]= rand()%1000+1;
                    printf ("%d\t", a[i][j]);

                }
            printf("\n\n");
        }
    mi= a[0][0];
    }

    else
    {
        printf("\n\nenter again\n");
        return 0;
    }
/* End creating an arbitrary array    */


    /* Change the first and second lines and deploy them*/
    printf ("\n\nChange the first and second lines and deploy them\n");

            for (j = 0; j < n/2; j++)
                {
                    int temp = a[0][j];
                    a[0][j] = a[0][n-(1+j)];
                    a[0][n-(1+j)]= temp;

                }

            for (j = 0; j < n/2; j++)
                {
                    int temp = a[m-1][j];
                    a[m-1][j] = a[m-1][n-(1+j)];
                    a[m-1][n-(1+j)]= temp;

                }
            for (j = 0; j<n; j++)
                {
                    int temp = a[0][j];
                    a[0][j] = a[m-1][j];
                    a[m-1][j]= temp;
                }

            printf("\n\n");
            for (i = 0; i<m; i++)
                {
                    for (j = 0; j<n; j++)
                        {
                            /* Assignment of the minimum element - (mi), the lines of this element - (lmi) and the column of this element - (cmi)*/
                            if(mi>a[i][j])
                            {
                                mi=a[i][j];
                                lmi=i;
                                cmi=j;
                            }
                            /* End assignment*/

                            printf("%d\t" ,a[i][j]);

                        }
                    printf("\n\n");
                }
                /* End change  */

            /* start delete the lines and the column of the minimum element*/
            printf ("\n\nDelete line and column of the minimum element: %d   \n\n", mi);

            int new_a[m-1][n-1];

            for (i=0;i<m-1;i++)
            {
                int ni=0, nj=0;
                for(j=0;j<n-1;j++)
                {
                    if (i>=lmi)
                           ni=1;
                    if (j>=cmi)
                            nj=1;

                    new_a[i][j]=a[i+ni][j+nj];
                    printf ("%d\t", new_a [i][j]);
                }
                printf("\n\n");
            }

            /* End delete*/

            /* Creating an Array Manually */

            printf("\n\nCreating new array for multiplication.\n\n");
            int s, em,en;
            m--;
            n--;
            em=n;
            en=m;

            int new_b[em][en],ed;
            char input;
            for (i = 0; i<em; i++)
                {
                    for (j = 0; j<en; j++)
                    {
                        new_b[i][j]= 0;  /* FILLING A NEW MASSIVE OF ZERO*/

                    }
                }
            s=0;
            i=0;
            j=0;
            ed=0;
            while (ed==0)
                {
                    input=getchar();
                    switch (input)
                   {
                        case '0':
                        case '1':
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                        case '9':
                            s=s*10+input-'0';
                            break;
                        case ' ':
                            new_b[i][j]=s;
                            if (j<en)
                            {
                                j++;
                                s=0;
                            }
                            else
                            {
                               printf("End of line!!! Enter ',' or '.'\n\n");
                               j=en;
                               s=0;
                            }
                            break;

                        case ',':
                            new_b[i][j]=s;
                            j=0;
                            if (i<em)
                            {
                                i++;
                                s=0;
                            }
                            else
                            {
                                printf("End of column!!! Enter '.'\n\n");
                                s=0;
                                i=em;

                            }
                            break;
                        case '.':
                            new_b[i][j]=s;
                            ed=1;
                            break;
                   }
                }
                   printf("\n\n");
                   for (i = 0; i<em; i++)
                        {
                            for (j = 0; j<en; j++)
                                {
                                    printf ("%d\t", new_b[i][j]);
                                }
                            printf("\n\n");
                        }

            /* End creating*/

            /* Start Multiplication */


            printf("\n\nMultiplication of matrixes\n\n");
            int end_b[en][en], c;

            for (i = 0; i<en; i++)
                {
                    for (j = 0; j<en; j++)
                    {
                        end_b[i][j]= 0;  /* FILLING A NEW MASSIVE OF ZERO*/

                    }
                }

            for (i=0; i<m;i++)
                {
                    for(j=0;j<en;j++)
                    {
                        for(c=0;c<n;c++)
                        end_b[i][j]+=new_a[i][c] * new_b[c][j];

                    }

                }

             for (i = 0; i<en; i++)
                        {
                            for (j = 0; j<en; j++)
                                {
                                    printf ("%d\t", end_b[i][j]);
                                }
                            printf("\n\n");
                        }
            /* End Multiplication*/
   free(a);
   free(new_a);
   free(new_b);
   free(end_b);
return 0;
}
