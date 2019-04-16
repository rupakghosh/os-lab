
#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()
{
    int request[50],move=0,current_pos,upper_bound,finish, lower[100], upper[100];
	int temp ,a1[100], i1, n1, j1=0, k1=0, x1=0, l1, cylinders;
    // request is for taking request
    //temp is for having temporary variable that helps in sorting
    
    printf("\n ----------------------------------LOOK DISC ALGORITHM--------------------------------------\n");
    printf("\n Please enter the following details : - ");
    
    printf("\n \tHow Many Cylinder The Disc Drive Has :  ");
    scanf("%d",&cylinders);
    
    printf("\n \t The Numbering of the disc drive lies between 0 and %d",cylinders-1);
    
    printf("\n \t  Enter  the Current Position where the drive is serving the request  : ");
    scanf("%d",&current_pos);
    
    printf("\n \t Enter the Total Number of Requests That Are In FIFO(First In First Out )  Order : ");
    scanf("%d",&n1);
    printf("\n \t Provide  the Correct Request order: ");
    for(i1=0;i1<n1;i1++)
    {
        scanf("\n%d",&request[i1]);  // take all the request from user one by one
    }
    printf("\n \t Enter the Upper Bound of The Disc Drive : ");
    scanf("%d",&upper_bound);
    	

    for(i1=0;i1<n1;i1++)  // Break The requests into arrays
    {
        if(request[i1]<current_pos)  // Checking of requests lower than the current Position 
        {
            lower[j1]=request[i1];
            j1++;
        }
        if(request[i1]>current_pos) // Checking of the request Greater than the Current Position
        {
            upper[k1]=request[i1];
            k1++;
        }
    }
    
    
    for(i1=0;i1<j1;i1++)   //Lower Array Has Been Sorted In the reverse Order
    {
        for(l1=0;l1<j1-1;l1++)
        {
            if(lower[l1]<lower[l1+1])
            {
                temp=lower[l1];
                lower[l1]=lower[l1+1];  // Swapping takes place That is required for sorting
                lower[l1+1]=temp;
            }
        }
    } // End of First for Loop
    
    for(i1=0;i1<=k1;i1++)
    {
        for(l1=0;l1<k1-1;l1++)
        {
            if(upper[l1]>upper[l1+1])
            {
                temp=upper[l1];
                upper[l1]=upper[l1+1];  // Swapping takes place That is required for sorting
                upper[l1+1]=temp;
            }
        }
    } // End of First For Loop
        
    printf(" \n \t Enter the end the head to which extent the head is moving:");
    printf("\n \t Press '0' for Lower End & '1' Ffor Upper End....");
    scanf("%d",&finish);
    switch(finish)
    {
        case 0:        //Case for iterating (Traversing) to the lower first and then go to the upper end
            for(i1=0;i1<j1;i1++)
            {        
                a1[x1]=lower[i1];    
                x1++;            
            }
            
            for(i1=0;i1<k1;i1++)
            {        
                a1[x1]=upper[i1];
                x1++;                
    }
	break;
        case 1:         //Case for iterating (Traversing) to the Upper End  first and then go to the lower end        
            for(i1=0;i1<k1;i1++)
            {        
                a1[x1]=upper[i1];    
                x1++;            
            }
            
            for(i1=0;i1<j1;i1++)
            {        
                a1[x1]=lower[i1];
                x1++;                
    }
    break;
    }
    
    move=move+abs(current_pos-a1[0]);  //a[]- array to store final order of processing requests, mov - to calculate total head movement */
    printf("%d - %d",current_pos,a1[0]); // get abs - absolute as header file math.h has been already specified
    for(i1=1;i1<x1;i1++)
    {
        move=move+abs(a1[i1]-a1[i1-1]);  // Check Total Head Movement 
        printf(" - %d",a1[i1]);
    }
    printf("\n");
    printf("\n \tTotal distance (in cylinders) that the disk arm moves to satisfy all the pending requests for each of the LOOK disk-scheduling algorithms = %d\n",move);
}

