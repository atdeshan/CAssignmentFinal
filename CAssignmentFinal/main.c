#include <stdio.h>
#include <string.h>

struct Quiz {
    char question[1000];
    char answer[50]; // Increased the size to 50 to allow longer answers
};

void initialize(struct Quiz quiz[], int* numberOfQuestions);
void tosaveFile(struct Quiz quiz[], int* numberOfQuestions);
void loadFile(struct Quiz quiz[], int* numberOfQuestions);

int main() {
    int numberOfQuestions = 0;
    struct Quiz quiz[100];
    int userNumber;
//
    printf("01 - Change max count of quizes\n02 - Face for the questoins\n03 - Rearrange the quizes\n");
    printf("Enter a number - ");
    scanf("%d",&userNumber);
    printf("\n\n------------------------------------------------\n\n");
    
    
    char isZpressed[2];
    int n=0;
    switch(userNumber){
        case 1 :
            printf("Enter tha maximum number of quizes number that may ask\nEnter the number - ");
            scanf("%d",&numberOfQuestions);
            break;
        case 2:
            printf("for each answers use YES or NO\n");
            loadFile(quiz, &numberOfQuestions);
            char answerFormUser[50];
            do{
                printf("%s\n",quiz[n].question);
                scanf("%s",answerFormUser);
                if(strcmp(answerFormUser,quiz[n].answer) ==0 ){
                    printf("/nYour answer is correct\n");
                }else{
                    printf("\nyour answer is wrong");
                }
                printf("\nEnter do you willing end the quiz therwise enter a any number to next question\n");
                scanf("%s",isZpressed);
                n++;
            }while((strcmp(isZpressed,"Z")!=0) && (n<numberOfQuestions));
            n=0;
            break;
        case 3:
            initialize(quiz, &numberOfQuestions);
            tosaveFile(quiz, &numberOfQuestions);
            loadFile(quiz, &numberOfQuestions);
            break;
            
    }

//    initialize(quiz, &numberOfQuestions);
//    tosaveFile(quiz, &numberOfQuestions);
    
    

    return 0;
}

void initialize(struct Quiz quiz[], int* numberOfQuestions) {
    printf("Enter the number of Quiz that you want to assign: ");
    scanf("%d", numberOfQuestions);
    char inputBuffer[100];
    fgets(inputBuffer, sizeof(inputBuffer), stdin);

   

    printf("\nEnter Problems and Answers\n\n");
    for (int x = 0; x < (*numberOfQuestions); x++) {
        printf("Enter A Question: ");
//        scanf("%[^\n]", quiz[x].question);
        fgets(quiz[x].question, sizeof(quiz[x].question), stdin);
       

        printf("Enter the Answer: ");
//        scanf("%[^\n]", quiz[x].answer);
        fgets(quiz[x].answer, sizeof(quiz[x].answer), stdin);

    }
}
void tosaveFile(struct Quiz quiz[], int* numberOfQuestions){
    FILE* file = fopen("text.txt", "w");
    if(file == NULL ){
        printf("thre is an erro with the file");
    }else{
        for (int i = 0; i < *numberOfQuestions; i++) {
            fprintf(file, "%s\n%s\n", quiz[i].question, quiz[i].answer);
            
            
           }
        

           fclose(file);
    }
    
}
void loadFile(struct Quiz quiz[], int* numberOfQuestions) {
    FILE* file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("No data file found. Initializing the quiz.\n");
        return;
    }

    int i = 0;
    while (fscanf(file, "%99[^\n]\n%49[^\n]\n", quiz[i].question, quiz[i].answer) == 2) {
        i++;
    }

    *numberOfQuestions = i;
    fclose(file);
}




