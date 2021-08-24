#include <stdio.h> //Provides the core of the typing capabilities in C.
#include <stdlib.h> //Used to perform a variety of operations, including transformations, pseudo-random numbers, memory allocation, process control, environment, signaling, search, and sequencing.
#include <string.h>//To adjust a variety of character ranges.
int id[100];
float gradeofStudent[100];
int thenumberofStudent;
int inputInformation(){
	int b=0,c;
	do 
	{
		printf("-Enter student's ID %d:", b+1);
			scanf("%d",&id[b]);
		for(c=0;c<b;c++)
		{
			while (id[b]==id[c])
			{
				printf("***ID is duplicated, please re-enter ID\n");
				printf("-Enter student's ID %d: ", b+1);
				scanf("%d",&id[b]);
			}// This is the code used to enter the ID
		}	
		
		do
		{	
			printf("-Enter student's grade %d: ", b+1);
			scanf("%f",&gradeofStudent[b]);
			while (gradeofStudent[b]<0 || gradeofStudent[b]>10){
				printf("***Enter the wrong grade for the student, please enter again: ");
				scanf("%f",&gradeofStudent[b]);
			}
		}while (gradeofStudent[b]<0 || gradeofStudent[b]>10);// This is the code used to enter the grade of students
	b++;
	}while (b<thenumberofStudent);
}
int outputInformation(){
	int b=0;
	for(b=0;b<=thenumberofStudent-1;b++){
		printf("Student ID: %d\n- Grade: %.2f\n", id[b],gradeofStudent[b]);//Output information of student
	}
}
int main(){
	printf("Welcome to student management program!!!\n");
	do	{
					printf("Please enter the number of students in the class first(3-50): ");// here will ask to enter the number of students from 3 to 50 students
					scanf("%d",&thenumberofStudent);
					if(thenumberofStudent>=3 && thenumberofStudent<=50){
						printf("''''''''''''''''''''''''''''''''''''''''''''\n");
						printf("The number of students you entered is: %d",thenumberofStudent);
						printf("\n''''''''''''''''''''''''''''''''''''''''''''\n");
					}
					if(thenumberofStudent<3 || thenumberofStudent>50){
						printf("Enter wrong, re-enter: \n");
					}
		}while (thenumberofStudent<3 || thenumberofStudent>50);
		//Input the number of student in the class.
	int choice;
	do{
		printf("\n0. Exit program.\n");
		printf("1. Input information of student (ID and grade). \n");
		printf("2. Output information of student (ID and grade).\n");
		printf("3. Display IDs have highest grade.\n");
		printf("4. Display IDs have lowest grade.\n");
		printf("5. Re-enter the number of students if you enter wrong number.\n");
		printf("\n Your choice is: ");
		scanf("%d", &choice);
		switch (choice){
			case 0:{
				printf("Exiting...\nPress enter a second time to exit the program.");
				break;
			}
			case 1:{
				inputInformation();
				break;
			}
			case 2:{
				outputInformation();
				break;
			}
			case 3:{
				int idofMax = id[0];
				int b;
				float max = gradeofStudent[0];
				for(b=0;b<thenumberofStudent;b++){
					if(max <= gradeofStudent[b]){
						max = gradeofStudent[b];
						idofMax = id[b];
					}
				}	
				for(b=0;b<thenumberofStudent;b++){
					if(gradeofStudent[b] == max)
					{
						printf("Student with ID : %d has  highest grade: %.2f\n",id[b], max);
					}
				}
				break;
			}// Find the highest grades
			case 4:{
				int idofMin = id[0];
				int b; 
				float min = gradeofStudent[0];
				for(b=0;b<thenumberofStudent;b++)
				{
					if(gradeofStudent[b]<= min)
					{
						min = gradeofStudent[b];
						idofMin = id[b];
					}
				}
				for(b=0;b<thenumberofStudent;b++)
				{
					if(gradeofStudent[b] == min)
					{
						printf("Student with ID: %d has lowest grade are: %.2f\n", id[b], min);
					}
				}
				break;
				}//Find the lowest grades
			case 5: {
				do
				{
					printf("Please enter the number of students in the class first(3-50): ");// here will ask to enter the number of students from 3 to 50 students
					scanf("%d",&thenumberofStudent);
					if(thenumberofStudent>=3 && thenumberofStudent<=50)
					{
						printf("''''''''''''''''''''''''''''''''''''''''''''\n");
						printf("The number of students you entered is: %d",thenumberofStudent);
						printf("\n''''''''''''''''''''''''''''''''''''''''''''\n");
					}
					if(thenumberofStudent<3 || thenumberofStudent>50)
					{
						printf("Enter wrong, re-enter: ");//The program will force the user to re-enter if the required condition is entered incorrectly
						scanf("%d",&thenumberofStudent);
					}
				}while (thenumberofStudent<3 || thenumberofStudent>50);
				break;//Re-enter the number of student in the class
			}
			default:
				printf("---------------------------\n");
				printf("Invalid input, re-enter:\n");
		}
	}while ( choice != 0);
	return 0;
}
