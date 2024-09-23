#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_USERS 10
#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4
#define MAX_SUBJECTS 5

//login-section
#define MAX_USERS 10
// User struct to hold user data

int user_count=0;
int i;
int user_index;

typedef struct{
char username[30];
char password[6];	
}User;

void takeTest(int subjectIndex); // user define function 
void selectOpration();
void generate_marksheet();
int register_user();
int login_user();//Return User index
void input_password(char*);
void Instructions();
 

User users[MAX_USERS];//max
//login-function-return-variable
;


// Question struct to hold question data
struct Question {
    char question[500];
    char options[MAX_OPTIONS][50];
    char correctOption;
};
// 2D Array for the holding subject
char subjects[MAX_SUBJECTS][50] = {
    "Mathematics",
    "Physics",
    "Chemistry",
    "Biology",
    "Computer Science"
};



// Array of questions for each subject (25 questions for each subject)
struct Question questions[MAX_SUBJECTS][MAX_QUESTIONS] = {
    { // Mathematics
        {"What is 2 + 3?", {"A) 5", "B) 6", "C) 7", "D) 8"}, 'A'},
        {"What is 4 * 5?", {"A) 10", "B) 20", "C) 25", "D) 15"}, 'B'},
        {"What is the square root of 144?", {"A) 12", "B) 14", "C) 13", "D) 15"}, 'A'},
        {"What is 10 divided by 2?", {"A) 2", "B) 5", "C) 8", "D) 4"}, 'B'},
        {"What is 15 + 6?", {"A) 20", "B) 21", "C) 22", "D) 23"}, 'B'},
        {"Solve for x: 2x = 10", {"A) x = 3", "B) x = 5", "C) x = 6", "D) x = 7"}, 'B'},
        {"What is the value of pi (π)?", {"A) 3.14", "B) 2.71", "C) 1.41", "D) 9.81"}, 'A'},
        {"What is 7 squared?", {"A) 49", "B) 56", "C) 36", "D) 64"}, 'A'},
        {"What is the derivative of x^2?", {"A) 2x", "B) x", "C) x^2", "D) 1"}, 'A'},
        {"What is the integral of 2x?", {"A) x^2 + C", "B) 2x^2", "C) x^2 - C", "D) 2x + C"}, 'A'},
    
    },
    { // Physics
        {"What is the formula for force?", {"A) F=ma", "B) E=mc^2", "C) V=IR", "D) P=IV"}, 'A'},
        {"What is the speed of light?", {"A) 3x10^8 m/s", "B) 2x10^8 m/s", "C) 1x10^6 m/s", "D) 5x10^8 m/s"}, 'A'},
        {"What is the acceleration due to gravity?", {"A) 9.8 m/s^2", "B) 8.9 m/s^2", "C) 10.1 m/s^2", "D) 9.2 m/s^2"}, 'A'},
        {"What is the formula for kinetic energy?", {"A) 1/2 mv^2", "B) mv", "C) F = ma", "D) mgh"}, 'A'},
        {"Who formulated the laws of motion?", {"A) Newton", "B) Einstein", "C) Galileo", "D) Tesla"}, 'A'},
        {"What is Ohm's Law?", {"A) V = IR", "B) P = IV", "C) E = mc^2", "D) F = ma"}, 'A'},
        {"What is the SI unit of power?", {"A) Watt", "B) Joule", "C) Newton", "D) Volt"}, 'A'},
        {"What is the charge of an electron?", {"A) -1.6x10^-19 C", "B) 1.6x10^-19 C", "C) 1.6x10^-18 C", "D) -1.6x10^-18 C"}, 'A'},
        {"What is the symbol for resistance?", {"A) R", "B) P", "C) V", "D) I"}, 'A'},
        {"What is the escape velocity from Earth?", {"A) 11.2 km/s", "B) 9.8 km/s", "C) 5 km/s", "D) 15 km/s"}, 'A'},
    
    },
    { // Chemistry
        {"What is the symbol for Oxygen?", {"A) O", "B) Ox", "C) O2", "D) O3"}, 'A'},
        {"What is H2O?", {"A) Water", "B) Oxygen", "C) Carbon Dioxide", "D) Hydrogen"}, 'A'},
        {"What is the atomic number of Carbon?", {"A) 6", "B) 8", "C) 12", "D) 14"}, 'A'},
        {"What is the chemical formula for salt?", {"A) NaCl", "B) HCl", "C) KCl", "D) NH3"}, 'A'},
        {"What is the pH value of water?", {"A) 7", "B) 1", "C) 14", "D) 0"}, 'A'},
        {"What is the valency of Carbon?", {"A) 4", "B) 2", "C) 6", "D) 3"}, 'A'},
        {"Who is known as the father of modern chemistry?", {"A) Antoine Lavoisier", "B) Dmitri Mendeleev", "C) Marie Curie", "D) Louis Pasteur"}, 'A'},
        {"What is the most abundant element in the Earth's crust?", {"A) Oxygen", "B) Hydrogen", "C) Carbon", "D) Silicon"}, 'A'},
        {"What is the charge on a proton?", {"A) +1", "B) -1", "C) 0", "D) +2"}, 'A'},
        {"What is the molar mass of H2O?", {"A) 18 g/mol", "B) 16 g/mol", "C) 10 g/mol", "D) 14 g/mol"}, 'A'},
    
    },
    { // Biology
        {"What is the powerhouse of the cell?", {"A) Nucleus", "B) Mitochondria", "C) Ribosome", "D) Golgi Apparatus"}, 'B'},
        {"What is photosynthesis?", {"A) Conversion of light to chemical energy", "B) Cell division", "C) Reproduction", "D) Breathing"}, 'A'},
        {"What is the basic unit of life?", {"A) Cell", "B) Atom", "C) Molecule", "D) Tissue"}, 'A'},
        {"What is the largest organ in the human body?", {"A) Skin", "B) Heart", "C) Brain", "D) Lungs"}, 'A'},
        {"What is the primary function of red blood cells?", {"A) Transport oxygen", "B) Fight infections", "C) Digest food", "D) Produce hormones"}, 'A'},
        {"What is DNA?", {"A) Genetic material", "B) Protein", "C) Lipid", "D) Carbohydrate"}, 'A'},
        {"What is the process of cell division?", {"A) Mitosis", "B) Meiosis", "C) Cytokinesis", "D) Fertilization"}, 'A'},
        {"What is the function of the liver?", {"A) Detoxification", "B) Pumping blood", "C) Breathing", "D) Digestion"}, 'A'},
        {"What is the human body's largest bone?", {"A) Femur", "B) Tibia", "C) Humerus", "D) Radius"}, 'A'},
        {"What is the normal pH of blood?", {"A) 7.4", "B) 6.5", "C) 8.0", "D) 9.0"}, 'A'},
        
    },
    { // Computer Science
        {"What does RAM stand for?", {"A) Read Access Memory", "B) Random Access Memory", "C) Rapid Access Memory", "D) Run Access Memory"}, 'B'},
        {"What is the time complexity of binary search?", {"A) O(n)", "B) O(n^2)", "C) O(log n)", "D) O(1)"}, 'C'},
        {"What is a data structure?", {"A) A way to store and organize data", "B) A type of database", "C) An algorithm", "D) A programming language"}, 'A'},
        {"What is a recursive function?", {"A) A function that calls itself", "B) A function that loops", "C) A function with multiple returns", "D) A function with conditions"}, 'A'},
        {"What does HTML stand for?", {"A) HyperText Markup Language", "B) HyperTerminal Machine Language", "C) HighText Markup Language", "D) HyperTransfer Markup Language"}, 'A'},
        {"What does CSS stand for?", {"A) Cascading Style Sheets", "B) Central Style Sheets", "C) Cascading Script Sheets", "D) Computer Style Sheets"}, 'A'},
        {"What is the purpose of an operating system?", {"A) To manage hardware and software resources", "B) To create software", "C) To store files", "D) To process data"}, 'A'},
        {"What is the full form of SQL?", {"A) Structured Query Language", "B) Sequential Query Language", "C) Simple Query Language", "D) Syntax Query Language"}, 'A'},
        {"What is the smallest unit of data in a computer?", {"A) Bit", "B) Byte", "C) Nibble", "D) Word"}, 'A'},
        {"What does RAM stand for?", {"A) Read Access Memory", "B) Random Access Memory", "C) Rapid Access Memory", "D) Run Access Memory"}, 'B'},

    
    }
};


// Function to select the subject for the test
void selectSubject() {

	int i;
    int subjectChoice;
    printf("\nSelect the subject for the test:\n\n");
    for (i = 0; i < MAX_SUBJECTS; i++) {
        printf("%d) %s\n", i + 1, subjects[i]);
    }
    printf("\nEnter your choice: ");
    scanf("%d", &subjectChoice);

    if (subjectChoice >= 1 && subjectChoice <= MAX_SUBJECTS) {
        takeTest(subjectChoice - 1);

    } else {
    	system("cls");
        printf("\n\t\t\ Invalid choice!\n");
    }
}




// This is main function

int main() {

    printf("\t\t\t\t...Welcome to the CBT system!\n\n");
    printf("********Instruction:****\n");
    printf("1 Examinee can only select one subject at a time\n");
    printf("2 There are total ten question and each question carries equal marks of 1\n");
    printf("3 There are no negative marking\n");
    printf("4 Each questions are compulsory for final submission\n");
    printf("5 Examinee need to register first and then login for the required test\n");
    
    selectOpration();
    return 0;
}


int register_user()
 {
 	if(user_count==MAX_USERS)
	 {//total number of user
	 system("cls");
 		printf("\n\t\tMaxxium %d users supported!\n\t\tno more registration Allowed!!!\n ",user_count);
            return 0;
	 }

	int new_index=user_count;
 	printf("\n\t\t\t\tRegister a new user");
 	printf("\n\t\t_______________________________________________\n");
 	fflush(stdin);
    printf("\n\t\tEnter UserName ");
    gets(users[new_index].username);//max user
    input_password(users[new_index].password);//password input
    
 	user_count ++;
 	system("cls");
	printf("\n\t\tRegistration successful!\n");		
 }


// Login user function
int login_user(){
	
	char username[30];
	char password[30];
	fflush(stdin);
	printf("\n\t\tEnter UserName ");
    gets(username);//max user
	input_password(password);
	//password input
		
	for( i=0;i<user_count;i++)//campare
	{
		if(strcmp(username,users[i].username)==0 && strcmp(password,users[i].password)==0){
            
            return i;	
        }
				
	}
	return -1;//return---switch-case
}

// This is password input function to take the password

void input_password(char* password)//password input
{
	char chpass;
	int i=0;
	printf("\n\t\tEnter password ");
	while((chpass=getch())!=13)
	{
		password[i]=chpass;
		i++;
		printf("*");
	}
	password[7]='\0';
	
	

}

///


// Function to take the test 
void takeTest(int subjectIndex)
 {
    int totalScore = 0;
    char answer;
    int i,j;
    int wrongAnswers[MAX_QUESTIONS];

    for(int i=0;i<MAX_QUESTIONS;i++){
        wrongAnswers[i]=-1;
    }


     // To store wrong answers
    // memset(wrongAnswers, -1, sizeof(wrongAnswers)); // Initialize wrong answers with -1 chrc
     

    printf("\nSubject: %s\n", subjects[subjectIndex]);
    for ( i = 0; i < MAX_QUESTIONS; i++) {
    	
        printf("\t\nQ%d: %s\n", i + 1, questions[subjectIndex][i].question);
        
        for ( j = 0; j < MAX_OPTIONS; j++) {
            printf("%s\n", questions[subjectIndex][i].options[j]);
        }
        printf("Enter your answer (A, B, C, or D): ");
        scanf(" %c", &answer);

        char capans=toupper(answer);


        
        if (capans== questions[subjectIndex][i].correctOption)
		 {
          totalScore++;
        } else {
            wrongAnswers[i] = 1; // Mark as wrong
        }

    }





    char yesNo;
    printf("\n             *Congratulation! For completion of sectional CBT *               \n\n");
    printf("If you want to generate your marsheet ");
    printf("then press 'Y' otherwise 'N': ");
    fflush(stdin);
    scanf("%c", &yesNo);
    fflush(stdin);
    if (yesNo == 'y' || yesNo == 'Y')
    {
        generate_marksheet(totalScore);
    }
    else
    {
        exit(0);
    }



 // Display score
//    system("cls");
//     printf("\n\t\t\tTest completed. You scored %d out of %d\n", totalScore, MAX_QUESTIONS);
    
//  	printf("\n\t\t_____________________________________________________________________\n\n");
//  	if(totalScore==MAX_QUESTIONS){
//  		printf("\t\t\t. Congratulation  Cleared the test\n");
// 	 }else if(totalScore>=7 && totalScore<MAX_QUESTIONS){
// 	 	printf("\t\t\t Very Well\n ");
// 	 }else{
// 	 	printf("\t\t\t Need to improvement\n");
// 	 }
	 
// 	 printf("\n\t\t_____________________________________________________________________\n\n");
char cm;
printf("Do you want to see your wrong question\n");

scanf("%c",&cm);
if(cm=='y' || cm=='Y'){


    // Show wrong answers
    printf("\n\t\t\tReview of wrong answers:\n");
 	printf("\n\t\t______________________________________________________________________\n\n");

    for (i = 0; i < MAX_QUESTIONS; i++) {
        if (wrongAnswers[i] == 1) {
            printf("\nQ%d: %s\n", i + 1, questions[subjectIndex][i].question);
            printf("Correct answer: %c\n", questions[subjectIndex][i].correctOption);
        }
    }
}else{

}





}




//login-section
void selectOpration() {
	int option;
	     printf("\n\t\t_______________________________________________\n\n");
            printf("\t\t\t\tCBT-EXAM-LOGIN");
     printf("\n\t\t_______________________________________________\n\n");
     
    while(1)
    {
    

     printf("\n\t\t1.Register");
     printf("\n\t\t2.Login");
     printf("\n\t\t3.Exit");
     printf("\n\t\tSelect An option ");
     scanf("%d",&option);
    switch(option)
    	{
    		case 1:
    			 register_user();	 
    			break;
    			case 2:
    				printf("\n\t\t\t\tLogin here");
 	                printf("\n\t\t_______________________________________________\n");
    				 user_index=login_user();
    				if(user_index>=0){
    				
    			    
    			    printf("\t\t\t\t\tLogin successfuly welcome %s",users[user_index].username);
    			    
				printf("\n\t\t_____________________________________________________________________________________________\n\n\n");
				                    selectSubject();

					}
					else
					{
						system("cls");
						printf("\n\t\tLogin failed! Incorrect username or password.\n");
					}
    			break;
    			case 3:
    			return 0;
    			break;
    			default:
    				    system("cls");
    				printf("\n\n\t\tInvalid Option. pleas try again.\n\n");
    				break;		
		}//switch-case
	}//while-loop
	
}





void generate_marksheet(int totalScore)
{
    int percentage,incans;
    char persign='%';
    percentage=(totalScore*100)/MAX_QUESTIONS;
    incans=10-totalScore;
    
    printf("\n\n\n|************************************************************************************|\n");
    printf("|                                    RESULT                                          |\n");
    printf("|____________________________________________________________________________________|\n");
    printf("|                               COMPUTER BASED TEST                                  |\n");
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|                       SECTIONAL PRACTICE ZONE-WISE RESULT                          |\n");
    printf("|====================================================================================|\n");
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|                                Detailed - Report                                   |\n");
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|       Total Questions                                             10               |\n");
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|       Total Attempt                                               10               |\n");
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|       Correct Answers                                              %d               |\n",totalScore);
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|       Incorrect Answers                                            %d               |\n",incans);
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|       Marks obtained                                             %d/10              |\n",totalScore);
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|       Percentage                                                  %d%c              |\n",percentage,persign);
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|                                                                                    |\n");
    printf("|                                                                                    |\n");
    printf("|                                                                                    |\n");
    if (percentage >= 81 && percentage <= 100)
    {
        printf("|                   RESULT : PASS IN FIRST DIVISION                                  |\n");
        printf("|                   GRADE  : A+                                                      |\n");
    }
    if (percentage >= 60 && percentage <= 80)
    {
        printf("|                   RESULT : PASS IN FIRST DIVISION                                  |\n");
        printf("|                   GRADE  : A                                                       |\n");
    }
    else if (percentage >= 41 && percentage <= 59)
    {
        printf("|                   RESULT : PASS IN SECOND DIVISION                                 |\n");
        printf("|                   GRADE  : B                                                       |\n");
    }
    else if (percentage >= 31 && percentage <= 40)
    {
        printf("|                   RESULT : PASS IN THIRD DIVISION                                  |\n");
        printf("|                   GRADE  : C                                                       |\n");
    }
    else if (percentage >= 1 && percentage <= 30)
    {
        printf("|                   RESULT : Fail                                                    |\n");
        printf("|                   GRADE  : D                                                       |\n");
    }
    printf("|                                                                                    |\n");
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|                                                                                    |\n");
    printf("|                                                                                    |\n");
    printf("|                                                                                    |\n");
    printf("|                                                                                    |\n");
    printf("|                                                               (KSS AUTHORITY)      |\n");
    printf("|                                                              Er. Satyam Mishra     |\n");
    printf("|                                                                                    |\n");
    printf("|                                                                                    |\n");
    printf("|            This CBT result digitally Verified with dedicated server!               |\n");
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|    You can take your retest for same or another section!! Best Regards for future  |\n");
    printf("|____________________________________________________________________________________|\n\n\n");
}




void Instructions(){

    printf("\n**********************Instructions for the CBT Test**********************\n");
    printf(" ****** If you are the new user, Select Register to crete new account\n");
    printf("\tIf You have an account, select login and enter the credentials to access the test");
    printf("\tTest Subjects:\n");
    printf("\tAfter logging in, you will be able to select a subject for the test.\n");
    printf("\tThe test consists of 5 subjects, and each subject contains 10 questions.\n");
    printf("\tTest Format:\n");
    printf("\tAll questions are multiple-choice.\n");
    printf("\tEach question has 4 options, and you must select the correct one.\n");
    printf("\tNavigating the Test:\n");
    printf("\tRead each question carefully.\n");
    printf("\tChoose the answer by selecting the corresponding option number.\n");
    printf("\tScoring:\n");
    printf("\tRead each question carefully. \n Choose the answer by selecting the corresponding option number.\n Once you have selected an option, you will automatically move to the next question.\n Test Duration:\n There is no time limit for this test.\n You can take as long as you need to complete the test.\nSubmitting the Test:\n After answering all the questions, the test will automatically submit.\n Your score will be calculated immediately.\n Scoring:\n You will receive 1 point for each correct answer.\n There is no negative marking for incorrect answers.");
    printf("\tThe total score will be displayed once the test is completed.\n");
    printf("\tReviewing Results:\n");
    printf("\tAfter the test, you will see your score along with the total possible score.\n");
    printf("\tAfter the test, you will see your score along with the total possible score.\n");
    printf("\tThe test will also display which questions you answered incorrectly, so you can review your mistakes.\n");
    printf("\tTest Attempts:\n");
    printf("\tYou are allowed to take the test as many times as you like.\n");
    printf("\tEach time you take the test, the questions will be randomly selected.\n");

}












































// void loader(int progress)
//  {
//     int barWidth = 5; 
    
//     int pos = barWidth * progress / 0 ;
//     for (int i = 0; i < barWidth; i++) 
// 	{
//         if (i < pos)
//             printf("-");
//         else
//             printf(" ");
//     }
//     printf(" %d%%  Complete\r", progress);
//     fflush(stdout);
// }

//  loader1() {
//     printf("Loading, please wait...\n");

//     for (int i = 0; i <= 5; i++) 
// 	{ 
//         loader(i);
//         sleep(1);
//     }

//     printf("\nLoading complete!\n");

    
// }

