#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ID[30];
int n;
float grade[10];
void inputInformation()
{
	int i=0;
	int j;
	do 
	{
		printf("-Enter student's ID %d:", i+1);
			scanf("%d",&ID[i]);
		for(j=0;j<i;j++)
		{
			if (ID[i]==ID[j])
			{
				printf("ID is duplicated, please re-enter ID\n");
				printf("-Enter student's ID %d: ", i+1);
				scanf("%d",&ID[i]);
			}
		} 
	do
	{
		printf("-Enter student's grade %d: ", i+1);
			scanf("%f",&grade[i]);
		if (grade[i]<0 || grade[i]>10)
		{
			printf("Enter the wrong grade for the student, please enter again \n");
		}
	}while (grade[i]<0 || grade[i]>10);
	i++;
	}while (i<n);
}
void outputInformation()
{
	int i=0;
	do
	{
		printf("Student ID: %d\n| Grades: %.2f\n", ID[i],grade[i]);
		i++;
	}
	while (i<n);
}
int mingrade()
	{
				int minID = ID[0];
	int i;
	float min = grade[0];
		for(i=0;i<n;i++)
		{
			if(grade[i]<= min)
			{
				min = grade[i];
				minID = ID[i];
			}
		}
		for(i=0;i<n;i++)
		{
			if(grade[i] == min)
			{
				printf("Student with ID: %d has highest grade are: %.2f\n", ID[i], min);
				i++;
			}
		}
}
int maxgrade()
{
	int maxID = ID[0];
	int i;
	float max = grade[0];
		for(i=0;i<n;i++)
		{
			if(max <= grade[i])
			{
				max = grade[i];
				maxID = ID[i];
			}
		}
		for(i=0;i<n;i++)
		{
			if(grade[i] == max)
			{
				printf("Student with ID : %d has  highest grade: %.2f\n",ID[i], max);
				i++;
			}
		}		
}	
int main(){
	printf("Welcome to student management program!!!\n");
	int choice;
	do{
		printf("\n0. Exit program.\n");
		printf("1. Input number of students.\n");
		printf("2. Input information of student (ID and grade). \n");
		printf("3. Output information of student (ID and grade).\n");
		printf("4. Display ID has highest grade.\n");
		printf("5. Display ID has lowest grade.\n");
		printf("\n Your choice is: ");
		scanf("%d", &choice);
		switch (choice){
			case 0:{
				printf("Exiting...\nPress enter a second time to exit the program.");
				break;
				}
			case 1:{
			do
				{
					printf("Please enter the number of students in the class first(3-30): ");
					scanf("%d",&n);
					if(n<3 || n>30)
					{
						printf("Enter wrong, re-enter: \n");
					}
				}while (n<3 || n>30);
				break;
				}
			case 2:{
				inputInformation();
				break;
			}
			case 3:{
				outputInformation();
				break;
				}
			case 4:{
				maxgrade();
				break;
			}
			case 5:{
				mingrade();
				break;
			}
			default:
				printf("---------------------------\n");
				printf("Invalid input, re-enter:\n");
		}
	}while ( choice != 0);
	return 0;
}
