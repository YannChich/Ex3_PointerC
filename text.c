#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30
#define FALSE 0
#define TRUE 1

 
int Mygetline(char s[]){  // the size of the line is maximum 256 bytes , i need to count every char and stop when i got : '\n' or 256 bytes
    char *p_line = s;   // pointer to the first char of the line
    int counter = 0;    // counter to know how many char i have on the line
    char Cget;
    while(counter < LINE && *p_line != '\n'){
        Cget = getchar(); // Read a char from the Terminal
        *p_line++ = Cget;   // put the char in p and augment 
        counter++;
    }
    return counter;
}

int Mygetword(char w[]){ // same logic of Mygetline()
    char *p_word = w;
    int counter = 0;
    char Cget;
    while(counter < WORD && *p_word != ' ' && *p_word != '\t' && *p_word != '\n'){
        Cget = getchar();
        *p_word++ = Cget;
        counter++;
    }
    return counter;
}

int Mysubstring(char *str1 , char *str2){ // i need to compare every char of str1 with char of str2 , 
    char *p_str1 = str1;
    int N_str1 = 0;
    // i have a pointer to run on the word and a Int to check the position of the pointer 
    char *p_str2 = str2;
    int N_str2 = 0;
    // i have a pointer to run on the word and a Int to check the position of the pointer 
    while(N_str1 != strlen(str1)+1){ // i gonna run on every char of str1

        if(N_str2 == strlen(str2) && N_str1 == strlen(str1)){
            return TRUE;
        }
        else if(*p_str2 == *p_str1){ // same char , i need to augment the pointer p_str1 and p_str2 and the Int position
            p_str1++;
            p_str2++;
            N_str1++;
            N_str2++;
        }
    
        else{ // i need to augmenter the pointer p_str1 and the Int position because the char of str1 is not equal to the char of str2
            p_str1++;
            N_str1++;
        }
        
    } return FALSE;

}

int similar (char *s,char *t, int n){
    if (n==0 && strcmp(s,t)==0){ // if n=0 and also s=t return True
        return TRUE;
    }
    if(Mysubstring(s,t)==0){ // if t is not a substring of s we can return False
        return FALSE;
    }
    char *p_s = s; // pointer to the word S
    int N_s = 0; // positon of the pointer

    char *p_t = t;
    int N_t = 0;
    int counter = 0; // gonna count how many char i deleted 

    while(N_s != strlen(s)+1){
        if(counter > n){ // i delete the max number of char i need to return False
            return FALSE;
        }
        else if(*p_t == *p_s){ // char of s equal to char of t
            p_s++;
            p_t++;
            N_s++;
            N_t++;
        }
        else{     // char of s is not equal to char of t , augment pointer and his int pos and the counter
            p_s++;
            N_s++;
            counter++;
        }
    }
    return TRUE;

}

int main(){

char s[] = "yaoynn";
char s2[] = "yann";
int d = similar(s,s2,2);
printf("%d\n",d);


    return 0;
}