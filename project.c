#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <string.h>
struct customer
{
    char name[50];
    long long int mobile;
    char email[100];
    char pan[20];
    int age;
}a;

void interface()//Displays the name of the hotel
{
    printf(" *----------------------------------------------------------------------------*\n");
	printf(" | *------------------------------------------------------------------------* |\n");
	printf(" | |                                 WELCOME                                | |\n");
	printf(" | |                                   TO                                   | |\n");
	printf(" | |                                  HOTEL                                 | |\n");
	printf(" | |                                   IVY                                  | |\n");
	printf(" | *------------------------------------------------------------------------* |\n");
	printf(" *----------------------------------------------------------------------------*\n");
	printf("\n\n");
	printf("                               Table of Contents                               \n");
	printf("\n");
	printf("                                1. Availability                                \n\n");
	printf("                                2. Room Amenities                              \n\n");
	printf("                                3. Room Allocation                             \n\n");
	printf("                                4. Room Cancellation                           \n\n");
	printf("                                5. About Us                                    \n\n");
	printf("                                6. Exit                                        \n\n");
    printf("\t\t\t\t");
}

int displayrooms(void *NotUsed, int argc, char **argv, char **azColName)
{   //Following printf statements correctly format the table Rooms 
    printf("%s     ", argv[0] ? argv[0] : "NULL");
    printf("%s\t", argv[1] ? argv[1] : "NULL");
    printf("%s\t", argv[2] ? argv[2] : "NULL");
    if(atoi(argv[3])>0)
        printf("Y\t\t");
    else
        printf("N\t\t");
    printf("%s\n", argv[4] ? argv[4] : "NULL");
        
    return 0;
}

int getavailability(sqlite3 *db, char *err_msg)//Gives the availability of each room
{
    printf("\nAvailability:\n\n");
    printf("No.   Type      Price   Availability\tDeposit\n");
    printf("---------------------------------------------\n");
    char *sql = "SELECT * FROM Rooms";
    int rc = sqlite3_exec(db, sql, displayrooms, 0, &err_msg);
    if(rc!=SQLITE_OK)
    {
        fprintf(stderr, "Failed to select data\n");
        fprintf(stderr, "SQL error: %s\n", err_msg);

        sqlite3_free(err_msg);
        sqlite3_close(db);
        
        return 1;
    }
    printf("\n");//For better visibility
    return 0;
}

void features()//Displays features of each room
{
    char o,j;
    while(1)
    {
        printf("Select Room:\n");
        printf("1.Economy\n");
        printf("2.Deluxe\n");
        printf("3.Suite\n");
        printf("4.Return to main menu\n\n");
        scanf(" %c",&o);
        system("cls");
        switch(o)
        {
            case '1': printf("                                    ECONOMY                                    \n");
					  printf(" ------------------------------------------------------------------------------\n");
					  printf("                                 WHAT IT OFFERS                                \n");
					  printf(" ------------------------------------------------------------------------------\n");
					  printf(" Accomodates 2\n");
					  printf(" 1 rooms with Queen-sized bed\n");
					  printf(" 1 bathroom\n");
					  printf(" Air-conditioned\n");
					  printf(" ------------------------------------------------------------------------------\n");
					  printf("                                    ADD-ONS                                    \n");
					  printf(" ------------------------------------------------------------------------------\n");
					  printf(" 32-Inch LED TV\n\n");
					  printf(" Price: Rs. 4000/- per night\n");
                      j='4';
                      while(j>'3')
                      {
                          printf(" Do you want to view another room(1), return to main menu (2) or exit (3)?\n ");
                    	  scanf(" %c",&j);
                    	  switch(j)
            			  {
            			      case '1': break;
            				  case '2': system("cls");
            				  		    return;
            			      case '3': exit(0);
            					        break;
           				      default: printf("Enter a valid number!\n");
           			      }
                      }
                      system("cls");
                      break;
        
            case '2': printf("                                     DELUXE                                    \n");
					  printf(" ------------------------------------------------------------------------------\n");
					  printf("                                 WHAT IT OFFERS                                \n");
		  			  printf(" ------------------------------------------------------------------------------\n");
					  printf(" Accomodates 4\n");
					  printf(" 2 rooms with Queen-sized beds\n");
					  printf(" 2 bathrooms\n");
					  printf(" Air-conditioned\n");
					  printf(" Grand balcony\n");
					  printf(" ------------------------------------------------------------------------------\n");
					  printf("                                    ADD-ONS                                    \n");
					  printf(" ------------------------------------------------------------------------------\n");
					  printf(" 46-Inch LED TV\n\n");
					  printf(" Price: Rs. 9000/- per night\n");
                      j='4';
                      while(j>'3')
                      {
                          printf(" Do you want to view another room(1), return to main menu (2) or exit (3)?\n ");
                    	  scanf(" %c",&j);
                    	  switch(j)
            			  {
            				  case '1': break;
            				  case '2': system("cls");
            						    return;
            			      case '3': exit(0);
            					        break;
           				      default: printf("Enter a valid number!\n");
           			      }
                      }
                      system("cls");
                      break;
    
            case '3': printf("                                     SUITE                                     \n");
					  printf(" ------------------------------------------------------------------------------\n");
					  printf("                                 WHAT IT OFFERS                                \n");
					  printf(" ------------------------------------------------------------------------------\n");
					  printf(" Accomodates 6\n");
					  printf(" 3 rooms with King-sized beds\n");
					  printf(" Fully-equipped open kitchen\n");
					  printf(" 2 bathrooms\n");
					  printf(" Air-conditioned\n");
					  printf(" Grand balcony facing the sea\n");
					  printf(" Hot tub\n");
					  printf(" ------------------------------------------------------------------------------\n");
					  printf("                                    ADD-ONS                                    \n");
					  printf(" ------------------------------------------------------------------------------\n");
					  printf(" Free pick-up and drop services\n");
					  printf(" Complimentary breakfast-in-bed\n");
					  printf(" 52-Inch LED TV\n\n");
					  printf(" Price: Rs. 15000/- per night\n");
                      j='4';
                      while(j>'3')
                      {
                          printf(" Do you want to view another room(1), return to main menu (2) or exit (3)?\n ");
                    	  scanf(" %c",&j);
                    	  switch(j)
            			  {
            				  case '1': break;
            				  case '2': system("cls");
            						    return;
            			      case '3': exit(0);
            					        break;
           				      default: printf("Enter a valid number!\n");
           			      }
                      }
                      system("cls");
                      break;

            case '4': return;
            default: printf("Enter a valid choice!");
                     scanf(" %c",&o); 
        }
    }
}

int arr[3];//To store the number of rooms

int availability(void *NotUsed, int argc, char **argv, char **azColName)//Store the number of rooms in arr
{    
    NotUsed = 0;
    static int x=0;
    if(x==3)
    {
        x=0;
    }
    arr[x] = atoi(argv[3]);
    x++;   
    return 0;
}

int days()//this function stores the check-in and check-out date and returns no. of days
{
	int days=0, temp=0, count=1, count2=1, count3=1, stay[2][3];
	while(count==1)
	{
		count=0;
		while(count2==1)
		{
			count2=0;
			printf("Enter check-in date in dd mm yyyy format:\n");
			scanf("%d %d %d", &stay[0][0], &stay[0][1], &stay[0][2]);
			if(stay[0][1]==1||stay[0][1]==3||stay[0][1]==5||stay[0][1]==7||stay[0][1]==8||stay[0][1]==10||stay[0][1]==12)
			{
				if(stay[0][0]<1||stay[0][0]>31)
				{
					printf("Enter a valid date\n");
					count2=1;
				}
			}
			else if(stay[0][1]==4||stay[0][1]==6||stay[0][1]==9||stay[0][1]==11)
			{
				if(stay[0][0]<1||stay[0][0]>30)
				{
					printf("Enter a valid date\n");
					count2=1;
				}
			}
			else if(stay[0][1]==2)
			{
				if(stay[0][2]%400==0)
				{
					if(stay[0][0]<1||stay[0][0]>29)
					{
						printf("Enter a valid date\n");
						count2=1;
					}
				}
				else if(stay[0][2]%100==0)
				{
					if(stay[0][0]<1||stay[0][0]>28)
					{
						printf("Enter a valid date\n");
						count2=1;
					}
				}
				else if(stay[0][2]%4==0)
				{
					if(stay[0][0]<1||stay[0][0]>29)
					{
						printf("Enter a valid date\n");
						count2=1;
					}
				}
				else if(stay[0][0]<1||stay[0][0]>28)
				{
					printf("Enter a valid date\n");
					count2=1;
				}
			}
			else
			{
				printf("Enter a valid date\n");
				count2=1;
			}
		}
		while(count3==1)
		{
			count3=0;
			printf("Enter check-out date in dd mm yyyy format:\n");
			scanf("%d %d %d", &stay[1][0], &stay[1][1], &stay[1][2]);
			if(stay[1][1]==1||stay[1][1]==3||stay[1][1]==5||stay[1][1]==7||stay[1][1]==8||stay[1][1]==10||stay[1][1]==12)
			{
				if(stay[1][0]<1||stay[1][0]>31)
				{
					printf("Enter a valid date\n");
					count3=1;
				}
			}
			else if(stay[1][1]==4||stay[1][1]==6||stay[1][1]==9||stay[1][1]==11)
			{
				if(stay[1][0]<1||stay[1][0]>30)
				{
					printf("Enter a valid date\n");
					count3=1;
				}
			}
			else if(stay[1][1]==2)
			{
				if(stay[1][2]%400==0)
				{
					if(stay[1][0]<1||stay[1][0]>29)
					{
						printf("Enter a valid date\n");
						count3=1;
					}
				}
				else if(stay[1][2]%100==0)
				{
					if(stay[1][0]<1||stay[1][0]>28)
					{
						printf("Enter a valid date\n");
						count3=1;
					}
				}
				else if(stay[1][2]%4==0)
				{
					if(stay[1][0]<1||stay[1][0]>29)
					{
						printf("Enter a valid date\n");
						count3=1;
					}
				}
				else if(stay[1][0]<1||stay[1][0]>28)
				{
					printf("Enter a valid date\n");
					count3=1;
				}
			}
			else
			{
				printf("Enter a valid date\n");
				count3=1;
			}
		}
		if(stay[0][2]==stay[1][2])
		{
			if(stay[0][1]==stay[1][1])
			{
				temp=stay[1][0]-stay[0][0];
				if(temp<=30)
				{
					days=temp;
				}
				else
				{
					printf("Maximum length of stay should be 30 days\n\n");
					count=1;
					count2=1;
					count3=1;
				}
			}
			else if(stay[1][1]-stay[0][1]==1)
			{
				if(stay[0][1]==1||stay[0][1]==3||stay[0][1]==5||stay[0][1]==7||stay[0][1]==8||stay[0][1]==10)
				{
					temp=stay[1][0]+31-stay[0][0];
					if(temp<=30)
					{
						days=temp;
					}
					else
					{
						printf("Maximum length of stay should be 30 days\n\n");
						count=1;
						count2=1;
						count3=1;
					}
				}
				else if(stay[0][1]==4||stay[0][1]==6||stay[0][1]==9||stay[0][1]==11)
				{
					temp=stay[1][0]+30-stay[0][0];
					if(temp<=30)
					{
						days=temp;
					}
					else
					{
						printf("Maximum length of stay should be 30 days\n\n");
						count=1;
						count2=1;
						count3=1;
					}
				}
				else
				{
					if(stay[0][2]%400==0)
					{
						temp=stay[1][0]+29-stay[0][0];
						if(temp<=30)
						{
							days=temp;
						}
						else
						{
							printf("Maximum length of stay should be 30 days\n\n");
							count=1;
							count2=1;
							count3=1;
						}
					}
					else if(stay[0][2]%100==0)
					{
						temp=stay[1][0]+28-stay[0][0];
						if(temp<=30)
						{
							days=temp;
						}
						else
						{
							printf("Maximum length of stay should be 30 days\n\n");
							count=1;
							count2=1;
							count3=1;
						}
					}
					else if(stay[0][2]%4==0)
					{
						temp=stay[1][0]+29-stay[0][0];
						if(temp<=30)
						{
							days=temp;
						}
						else
						{
							printf("Maximum length of stay should be 30 days\n\n");
							count=1;
							count2=1;
							count3=1;
						}
					}
					else
					{
						temp=stay[1][0]+28-stay[0][0];
						if(temp<=30)
						{
							days=temp;
						}
						else
						{
							printf("Maximum length of stay should be 30 days\n\n");
							count=1;
							count2=1;
							count3=1;
						}
					}
				}
			}
			else if(stay[1][1]-stay[0][1]==2)
			{
				if(stay[1][1]==3&&stay[0][1]==1)
				{
					if(stay[0][2]%400==0)
					{
						if(stay[0][0]==31&&stay[1][0]==1)
						{
							days=30;
						}
						else
						{
							printf("Maximum length of stay should be 30 days\n\n");
							count=1;
							count2=1;
							count3=1;
						}
					}
					else if(stay[0][2]%100==0)
					{
						if(stay[0][0]==31&&stay[1][0]==1)
						{
							days=29;
						}
						else if((stay[0][0]==30&&stay[1][0]==1)||(stay[0][0]==31&&stay[1][0]==2))
						{
							days=30;
						}
						else
						{
							printf("Maximum length of stay should be 30 days\n\n");
							count=1;
							count2=1;
							count3=1;
						}
					}
					else if(stay[0][2]%4==0)
					{
						if(stay[0][0]==31&&stay[1][0]==1)
						{
							days=30;
						}
						else
						{
							printf("Maximum length of stay should be 30 days\n\n");
							count=1;
							count2=1;
							count3=1;
						}
					}
					else
					{
						if(stay[0][0]==31&&stay[1][0]==1)
						{
							days=29;
						}
						else if((stay[0][0]==30&&stay[1][0]==1)||(stay[0][0]==31&&stay[1][0]==2))
						{
							days=30;
						}
						else
						{
							printf("Maximum length of stay should be 30 days\n\n");
							count=1;
							count2=1;
							count3=1;
						}
					}
				}
				else
				{
					printf("Maximum length of stay should be 30 days\n\n");
					count=1;
					count2=1;
					count3=1;
				}
			}
			else
			{
				printf("Maximum length of stay should be 30 days\n\n");
				count=1;
				count2=1;
				count3=1;
			}
		}
		else if(stay[1][2]-stay[0][2]==1)
		{
			if(stay[0][1]==12&&stay[1][1]==1)
			{
				temp=stay[1][0]+31-stay[0][0];
				if(temp<=30)
				{
					days=temp;
				}
				else
				{
					printf("Maximum length of stay should be 30 days\n\n");
					count=1;
					count2=1;
					count3=1;
				}
			}
			else
			{
				printf("Maximum length of stay should be 30 days\n\n");
				count=1;
				count2=1;
				count3=1;
			}
		}
		else
		{
			printf("Maximum length of stay should be 30 days\n");
			count=1;
			count2=1;
			count3=1;
		}
	}
	return days;
}

void customerdetails()
{
	int k;
	printf("Name      : ");
    scanf(" %[^\n]%*c",a.name);
    for(k=0;k<strlen(a.name);k++)
    {
        if(a.name[k]==32 || a.name[k]==45 || a.name[k]==39 || (a.name[k]>=65 && a.name[k]<=90) || (a.name[k]>=97 && a.name[k]<=122))
        {
        }
        else
        {
            printf("Wrong input,please enter name again\n");
            scanf(" %[^\n]%*c",a.name);
            k=0;
        }
    }
    printf("Mobile No.: ");
    scanf("%lld",&a.mobile);
    while(a.mobile<=1000000000 || a.mobile>=9999999999)
    {
        printf("Wrong input,please enter mobile number again\n");
        scanf("%lld",&a.mobile);
    }
    printf("Email Id  : ");
    scanf(" %[^\n]%*c",a.email);
    printf("Age       : ");
    scanf("%d",&a.age);
    while(a.age>=120)
    {
        printf("Wrong input,please enter age again\n");
        scanf("%d",&a.age);
    }
    printf("\n");
}

int q=0;
char room2[10];

int callback2(void *NotUsed, int argc, char **argv, char **azColName)
{
    
    char *p="NULL";
    NotUsed = 0;
    q=1;
    if(argv[5])
    	strcpy(room2, argv[5]);
    else
    	strcpy(room2, p);
    return 0;
}

int addcustomer(sqlite3 *db, char *err_msg)
{
    int j,f=1;
    char l,*m="NULL";
    char *sql3 = "SELECT * FROM Rooms";
                    
    int rc = sqlite3_exec(db, sql3,availability, 0, &err_msg);    
    if (rc != SQLITE_OK ) {
        
    fprintf(stderr, "Failed to select data\n");
    fprintf(stderr, "SQL error: %s\n", err_msg);

    sqlite3_free(err_msg);
    sqlite3_close(db);
        
    return 1;
    }
    if(arr[0]==0 && arr[1]==0 && arr[2]==0)
    {
    	printf("No rooms available. Sorry for the inconvenience. Please try again later.\n");
    	return 0;
    }
    printf("Enter your details:\n");
    printf("PAN       : ");
    scanf(" %[^\n]%*c",a.pan);
    char sqla[300];
    sprintf(sqla,"SELECT * FROM CustomerData WHERE PAN = '%s';",a.pan);
    rc = sqlite3_exec(db, sqla, callback2, 0, &err_msg);
    if (rc != SQLITE_OK ) {
        
    fprintf(stderr, "SQL error: %s\n", err_msg);
        
    sqlite3_free(err_msg);        
    sqlite3_close(db);
    }
    if(q==1)
    {
    	if(strcmp(room2,m)==0)
    	{
    		printf("As you have stayed with us, we offer 5%% discount\n");
    	}
    	else 
    	{
			printf("We do not currently offer multiple bookings on the same PAN.\n");
			printf("Sorry for the inconvenience.\n");
			printf("Please refer to our terms and conditions for further details.\n");
			return 0;
    	}
    }
    customerdetails();
    int day = days();
    printf("\n");
    printf("Select Room:\n");
    printf("1.Economy\n");
    printf("2.Deluxe\n");
    printf("3.Suite\n");
    scanf("%d",&j);
    printf("\n");
    char sql1[300];
    if(q==1)
    {
    	sprintf(sql1,"DELETE FROM CustomerData where PAN = '%s'",a.pan);
    	rc = sqlite3_exec(db, sql1, 0, 0, &err_msg);
    
    	if (rc != SQLITE_OK )
    	{    
    	fprintf(stderr, "SQL error: %s\n", err_msg);
        
    	sqlite3_free(err_msg);        
    	sqlite3_close(db);
        
    	return 1;
   		}

    }
    sprintf(sql1,"INSERT INTO CustomerData VALUES ('%s',%lld,'%s','%s',%d,'",a.name,a.mobile,a.email,a.pan,a.age);
    char *r,*s;
    while(f==1)
    {    
        switch(j)
        {
            case 1: r="ECONOMY');";
                    s="ECONOMY";
                    strcat(sql1,r);
                    if(arr[0]==0)
                    {
                        printf("Room currently unavailable. Select another room.\n");
                        f=1;
                        scanf("%d",&j);
                    }
                    else
                    {    
                        if(q==1)
                        {
                        	printf("You pay %d/-\n",3800*day);
                        }
                        else
                        {
                        	printf("You pay %d/-\n",4000*day);
                        }
                        printf("Confirm Booking?(Y/N)\n");
                        scanf(" %c",&l);
                        if (l=='Y')
                        {
                            arr[0]--;
                            f=0;
                        }
                        else if(l=='N')
                        {
                            return 0;
                        }
                    }
                    break;
            
            case 2: r="DELUXE');";
                    s="DELUXE";
                    strcat(sql1,r);
                    if(arr[1]==0)
                    {
                        printf("Room currently unavailable. Select another room.\n");
                        f=1;
                        scanf("%d",&j);
                    }
                    else
                    {
                        
                        if(q==1)
                        {
                        	printf("You pay %d/-\n",8550*day);
                        }
                        else
                        {
                        	printf("You pay %d/-\n",9000*day);
                        }
                        printf("Confirm Booking?(Y/N)\n");
                        scanf(" %c",&l);
                        if (l=='Y')
                        {
                            arr[1]--;
                            f=0;
                        }
                        else if(l=='N')
                        {
                            return 0;
                        }
                    }
                    break;
            
            case 3: r="SUITE');";
                    s="SUITE";
                    strcat(sql1,r);
                    if(arr[2]==0)
                    {
                        printf("Room currently unavailable. Select another room.\n");
                        f=1;
                        scanf("%d",&j);
                    }
                    else
                    {
                        if(q==1)
                        {
                        	printf("You pay %d/-\n",14250*day);
                        }
                        else
                        {
                        	printf("You pay %d/-\n",15000*day);
                        }
                        printf("Confirm Booking?(Y/N)\n");
                        scanf(" %c",&l);
                        if (l=='Y')
                        {
                            arr[2]--;
                            f=0;
                        }
                        else if(l=='N')
                        {
                            return 0;
                        }
                    }
                    break;
            
            default:printf("Enter a valid choice!\n");
                    f=1;
                    scanf("%d",&j);
        }
    }
    
    rc = sqlite3_exec(db, sql1, 0, 0, &err_msg);
    
    if (rc != SQLITE_OK )
    {    
    fprintf(stderr, "SQL error: %s\n", err_msg);
        
    sqlite3_free(err_msg);        
    sqlite3_close(db);
        
    return 1;
    }

    char sql2[300];
    sprintf(sql2,"UPDATE Rooms SET Num = Num - 1 WHERE RoomType = '%s';",s);
    rc = sqlite3_exec(db, sql2, 0, 0, &err_msg);
    
    if (rc != SQLITE_OK )
    {    
    fprintf(stderr, "SQL error: %s\n", err_msg);
        
    sqlite3_free(err_msg);        
    sqlite3_close(db);
        
    return 1;
    }
    
    printf("\nYour room has been successfully booked!\n");
    return 0;
}

int t=0;
char room[10];

int callback(void *NotUsed, int argc, char **argv, char **azColName) 
{
    
    char *s="NULL";
    NotUsed = 0;
    t=1;
	strcpy(room,argv[5] ? argv[5] : s);
    return 0;
}

int cancellation(sqlite3 *db, char *err_msg)
{
    char pan[10],*s="NULL";
    printf("Enter the PAN number: ");
    scanf(" %[^\n]%*c",pan);
    char sqla[300];
    sprintf(sqla,"SELECT * FROM CustomerData WHERE PAN = '%s';",pan);
    int rc = sqlite3_exec(db, sqla, callback, 0, &err_msg);
    if (rc != SQLITE_OK ) {
        
    fprintf(stderr, "SQL error: %s\n", err_msg);
        
    sqlite3_free(err_msg);        
    sqlite3_close(db);
    }
    if(t==0)
    {
        printf("Enter valid pan number!\n");
		return 0;
    }
    else if(strcmp(room,s)==0)
    {
    	printf("No room assigned to this pan number! Please try again\n");
		return 0;
    }
    else
    {
        char sqlb[300];
        sprintf(sqlb,"UPDATE Customerdata SET Room = NULL WHERE PAN = '%s'",pan);

        rc = sqlite3_exec(db, sqlb, 0, 0, &err_msg);
    
        if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "SQL error: %s\n", err_msg);
        
        sqlite3_free(err_msg);        
        sqlite3_close(db);
        }

        char sqlc[300];
        sprintf(sqlc,"UPDATE Rooms SET Num = Num + 1 WHERE RoomType = '%s';",room);
        rc = sqlite3_exec(db, sqlc, 0, 0, &err_msg);
    
        if (rc != SQLITE_OK )
        {    
        fprintf(stderr, "SQL error: %s\n", err_msg);
        
        sqlite3_free(err_msg);        
        sqlite3_close(db);
        
        return 1;
        }
		printf("Your room has been successfully cancelled. Your deposit has been deducted\n");
    }    
}

void aboutus()
{
	printf("\n");
	printf("...............................................................................\n");
	printf("                                   ABOUT US                                    \n");
	printf("...............................................................................\n");
	printf("\n");
	printf("                                   LOCATION:                                   \n");
	printf("                     Set at the edge of the forest against                     \n");
	printf("                the backdrop of snow-clad mountains, the hotel,                \n");
	printf("     sprawled across 20 acres, offers unparalleled views at any time of the    \n");
	printf("              year. The pristine location of the hotel makes for               \n");
	printf("                 amazing wallpapers wherever the tripod is set.                \n");
	printf("\n");
	printf("                                  FACILITIES:                                  \n");
	printf("   Fully-equipped gymnasium                        World-class swimming pool   \n");
	printf("   Jacuzzi and steam room                  Professional spa and massage room   \n");
	printf("   6-Hole Golf Course                                       Indoor Game Room   \n");
	printf("   Lawn Tennis court                                             Pub and Bar   \n");
	printf("\n");
	printf("                                 CONTACT US:                                   \n");
	printf("            Call us: 9022280471, 9920937571, 9969119020, 9987263054            \n");
	printf("                        Write to us: hotelivy@gmail.com                        \n");
	printf("\n");
	printf("                             TERMS AND CONDITIONS:                             \n");
	printf("Hotel Ivy is registered under Government Act 1908-5A:Hotels, Resorts, and Inns.\n");
	printf("Hotel Ivy is a registered trademark under Government Act 1933-2H. Hotel booking\n");
	printf("can be done online or offline. The hotel reserves the full right to cancel any \n");
	printf("booking without priorly informing the concerned party. Cancellation of booking \n");
	printf("will be done in accordance with the Government Rule 32-2. Deposit for one night\n");
	printf("will be deducted as charge for cancellation of booking. We currently do not    \n");
	printf("                   offer multiple bookings on the same PAN.                    \n");
	printf("\n");
	printf("\n");
	printf("                                   CREDITS:                                    \n");
	printf("   Harsh Sandesara                                                Karan Shah   \n");
	printf("   Rohit Pai                                                  Shashank Patel   \n");
	printf("                        Special Mention: Ashutosh Naik                         \n\n");
}

int main(void)
{
    char i,j;

    sqlite3 *db;
    char *err_msg = 0;
    
    int rc = sqlite3_open("testDB.db", &db);//Database opened
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", 
                sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }
    
    while(1)
    {
        interface();
        scanf(" %c",&i);
        system("cls");
        switch(i)
        {
            case '1': getavailability(db,err_msg);
            		  j='0';
            		  while(j!='1')
            		  {
            			  printf("Do you want to return to main menu (1) or exit (2)?\n");
            			  scanf(" %c",&j);
            			  switch(j)
            			  {
            				  case '1': break;
            				  case '2': exit(0);
            						    break;
            				  default: printf("Invalid input. Enter a valid number!\n");
            			  }
            		  }
            		  system("cls");
                      break;
            case '2': features();
                      break;
            case '3': addcustomer(db,err_msg);
            		  j='0';
            		  while(j!='1')
            		  {
            			  printf("Do you want to return to main menu (1) or exit (2)?\n");
            			  scanf(" %c",&j);
            			  switch(j)
            			  {
            				  case '1': break;
            				  case '2': exit(0);
            						    break;
            				  default: printf("Invalid input. Enter a valid number!\n");
            			  }
            		  }
            		  system("cls");
                      break;
            case '4': cancellation(db,err_msg);
            		  j='0';
            		  while(j!='1')
            		  {
            			  printf("Do you want to return to main menu (1) or exit (2)?\n");
            			  scanf(" %c",&j);
            			  switch(j)
            			  {
            				  case '1': break;
            				  case '2': exit(0);
            						    break;
            				  default: printf("Invalid input. Enter a valid number!\n");
            			  }
            		  }
            		  system("cls");
                      break;           
            case '5': aboutus();
            		  j='0';
            		  while(j!='1')
            		  {
            			  printf("Do you want to return to main menu (1) or exit (2)?\n");
            			  scanf(" %c",&j);
            			  switch(j)
            			  {
            				  case '1': break;
            				  case '2': exit(0);
            						    break;
            				  default: printf("Invalid input. Enter a valid number!\n");
            			  }
            		  }
            		  system("cls");
            		  break;
            case '6': sqlite3_close(db);
                      return 0; 
            default: printf("Enter a valid number!");      
        }
    }
    return 0;
}