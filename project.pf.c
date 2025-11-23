#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>

char *generatereply(char *input);
void programming(void (*savechat)(char **,char **));
void math(void (*savechat)(char **,char **));
void savechat(char **user,char **bot);
void read();

struct chat{
	char *user;
	char *bot;
};

struct reply {
    char *keyword;
    char *response;
};

void toLower(char *input){
	for(int i=0;input[i]!='\0';i++){
		input[i]=tolower(input[i]);
	}
}

void read(){
	
FILE *fp=fopen("chat_history.txt","r");
	if(fp==NULL){
		printf("No chat history found.\n");
	}
	else{
		char line[200];
		printf("--chat history--\n");
		while(fgets(line,sizeof(line),fp)){
			printf("%s", line);
		}
		printf("exiting chat history.\n");
		fclose(fp);
	}
	
}

void savechat(char **user,char **bot){
	struct chat *data=malloc(sizeof(struct chat));
	 
	data->user=*user;
	data->bot=*bot;
	FILE *fp=fopen("chat_history.txt","a");
	
	if(fp!=NULL){
	    fprintf(fp, "User: %s\n", data->user);
        fprintf(fp, "Bot: %s\n\n", data->bot);
		fclose(fp);
	}
	
	else{
		printf("Error opening the file.");
	}
	free(data);
}

char *generatereply(char *input){
char *reply=(char*)malloc(200);
toLower(input);

struct reply replies[]={
    {"hi", "Hello! How can I help you?"},
    {"hello", "Hello! How can I help you?"},
    {"hey", "Hello! How can I help you?"},
    {"how are you", "I am fine. Thank you for asking!"},
    {"whats up", "I am fine. Thank you for asking!"},
    {"your name", "I am your C language chatbot."},
    {"thank you", "You're welcome!"},
    {"thanks", "Happy to help!"},
    {"ok", "Great! What else do you want to ask?"},
    {"what can you do", "I can help with programming and maths basics."},
    {"tell me a joke", "Why did the C programmer get stuck? Because he couldn't find the 'break'!"},
    {"good morning", "Good morning! Hope your day is great!"},
    {"good night", "Good night! Take rest."},
    {"who are you", "I am your C language chatbot."},
    {"i am sad", "I'm here for you. You're doing great. Keep going."},
    {"stupid","it's okay to feel that way.Remember i am always here to help"},
    {"dumb","it's okay to feel that way.Remember i am always here to help"},
    {"geek","it's okay to feel that way.Remember i am always here to help"},
    {"i hate myself","Remember i am always here to help,please take care of yourself."},
    {"what is your favorite language", "I like C because it’s simple and powerful."},
    {"what is c", "C is a programming language that is fast and widely used."},
    {"can you help me", "Of course! Ask me about maths or programming."},
    {"i am tired", "Take a short break and relax!"},
    {"i am happy", "That's great! Keep smiling."},
    {"i am bored", "Let's chat or try programming exercises!"},
    {"what is ai", "AI stands for Artificial Intelligence. It makes computers smart."},
    {"tell me a fact", "Did you know? The first computer programmer was Ada Lovelace."},
    {"how old are you", "I am timeless! I live in your computer."},
    {"favorite food", "I don’t eat, but I love learning about food!"},
    {"sing a song", "I can’t sing, but I can tell you about songs."},
    {"do you have friends", "I have users like you as my friends!"},
    {"i am sad", "It's okay to feel sad sometimes. Take a deep breath and keep going."},
    {"i feel stressed", "Take one step at a time. You can handle this."},
    {"i am worried", "Worrying won't solve anything. Focus on what you can control."},
    {"i am tired", "Rest is important. Take a short break or a nap if you can."},
    {"i am lost", "Don't worry. Every step forward, no matter how small, counts."},
    {"failed", "Failure is a step toward success. Keep learning and trying."},
    {"i am scared", "Courage is not the absence of fear, it's moving forward despite it."},
    {"i am frustrated", "Take a deep breath and try again. Frustration is temporary."},
    {"give me advice", "Believe in yourself and take small steps every day."},
    {"i feel lonely", "You are never truly alone. Reach out or focus on something you love."},
    {"i am nervous", "Confidence grows with practice. You've got this."},
    {"motivate me", "You are capable of amazing things. Keep pushing forward!"},
    {"tell me something", "Did you know? The first C compiler was written in C itself!"},
    {"help", "I can answer basic questions of programming and maths. Please select the right mode."},
    {"bye", "Goodbye! Take care!"},
    {"exit","you are exiting for chat mode"}
};	

int n = sizeof(replies) / sizeof(replies[0]);
    for(int i=0; i<n; i++)
        if(strstr(input, replies[i].keyword)) {
            strcpy(reply, replies[i].response);
            return reply;
        }
    strcpy(reply, "Sorry, I do not understand this.");
    return reply;
}

void math(void (*savechat)(char **,char **)){
	printf("---Maths Mode---\n");
	printf("Enter expressions in format: a + b (supports + - * /)\n");
	 printf("Type 0 0 0 to exit math mode\n");

    int a, b;
    char op;
    char input[50], output[50];
while(1){
	printf("Expression: ");
        scanf("%d %c %d", &a, &op, &b);
        sprintf(input, "%d %c %d", a, op, b);

        if(a==0 && b==0 && op=='0'){
		break;
		}
		switch(op) {
            case '+': 
			 sprintf(output, "%d", a+b);
			 break;
            case '-':
			 sprintf(output, "%d", a-b);
			  break;
            case '*':
			 sprintf(output, "%d", a*b);
			  break;
            case '/':
                if(b != 0){
           	 sprintf(output, "%.2f", (float)a/b);
				}
                else {
               	sprintf(output, "Division by zero!");
				}
                break;
            default:
			 sprintf(output, "Invalid operator!");
        }
         printf("Result: %s\n", output);

        char *user = input;
        char *bot = output;
        savechat(&user, &bot);
    }
    printf("--- Exiting Math Mode ---\n\n");
}

void programming(void (*savechat)(char **,char **)){
	printf("----Programming Mode----\n");
	printf("i can tell you about these topics:");
	printf(" variables, loops, functions, arrays, pointers, strings, structures, files, conditions, operators, switch, dma\n");
    printf("Type 'exit' to leave programming mode\n");

    char topic[50], reply[200];
    while(1){
    	printf("Enter the topic name: ");
    	scanf("%s",topic);
    	toLower(topic);
    	 if(strstr(topic,"exit")){
    	  break;	
		 } 
        else if(strstr(topic,"variables")){
    strcpy(reply,"Variables store data. Example: int x = 5;");
}
else if(strstr(topic,"loops")){
    strcpy(reply,"Loops repeat code. Example: for(int i=0;i<5;i++){}");
}
else if(strstr(topic,"functions")){
    strcpy(reply,"Functions perform tasks. Example: void greet(){ printf(\"Hi\"); }");
}
else if(strstr(topic,"arrays")){
    strcpy(reply,"Arrays store many values. Example: int arr[5];");
}
else if(strstr(topic,"pointers")){
    strcpy(reply,"Pointers store addresses. Example: int *p = &x;");
}
else if(strstr(topic,"strings")){
    strcpy(reply,"Strings are char arrays. Example: char name[20];");
}
else if(strstr(topic,"structures")){
    strcpy(reply,"Structures group different data types. Example: struct student{int age;};");
}
else if(strstr(topic,"files")){
    strcpy(reply,"File handling lets you read and write files. Example: fopen(\"data.txt\",\"r\");");
}
else if(strstr(topic,"conditions")){
    strcpy(reply,"Conditions check decisions. Example: if(x>0){ }");
}
else if(strstr(topic,"operators")){
    strcpy(reply,"Operators perform actions. Example: +  -  *  /");
}
else if(strstr(topic,"switch")){
    strcpy(reply,"Switch checks many cases. Example: switch(x){ case 1: break; }");
}
else if(strstr(topic,"dma")){
    strcpy(reply,"Dynamic Memory Allocation uses malloc, calloc, realloc.");
}
else{
    strcpy(reply,"Topic not found!");
}

      printf("%s\n", reply);
		}    
        char *user = topic;
        char *bot = reply;
        savechat(&user, &bot);
        
        printf("--- Exiting Programming Mode ---\n\n");
    }

void chat(void (*savechat)(char **,char **)){
	char input[200];
	
	 printf("You: ");
    scanf(" %[^\n]", input);
    
    char **message=(char**)malloc(2*sizeof(char*));
    message[0]=(char *)malloc(strlen(input)+1);
    strcpy(message[0],input);
    message[1]= generatereply(input);
    
    savechat(&message[0],&message[1]);
    printf("Chatbot: %s\n", message[1]);
    
    if(strstr(input,"bye") || strstr(input,"exit") ){
    	free(message[0]);
        free(message[1]);
        free(message);
        return;
	}
	chat(savechat);
		free(message[0]);
        free(message[1]);
        free(message);
}

void selectmode(void (*savechat)(char **,char**)){
	int mode;
	while(1){
	printf("\nhello!,Select a mode from available options: \n");
	printf("1)General chat.\n");
	printf("2)Maths Mode.\n");
	printf("3)Programming Mode.\n");
	printf("4)See saved files.\n");
	printf("5)EXIT.\n");
	printf("enter your choice: ");
	scanf("%d",&mode);
	
	switch(mode){
		case 1:
			chat(savechat);
			break;
		case 2:
			math(savechat);
			break;
		case 3:
			programming(savechat);
			break;
		case 4:
			read(savechat);
			break;
		case 5:
			printf("Exiting chatbot. Bye!\n");\
		    return;
		default :
		 printf("Invalid choice. Try again.\n");
	}
	}
}
int main(){
	printf("----Beginner friendly chat bot----\n");
	printf("NOTE: All chats are saved here\n");
	
	FILE *fp=fopen("chat_history.txt","w");
	if(fp!=NULL){
		fclose(fp);
	}
	selectmode(savechat);
	
	return 0;
}