//
//  main.c
//  Summer_Vacation_Al_0727
//
//  Created by ChoiJimin on 2016/07/27.
//  Copyright © 2016年 ChoiJimin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define EOS '@'
#define NL '\n'
#define SP ' '
#define ERR -1
#define FF 0x0c


void GetPosition(char Str[], int StartP, int MaxC, int* EndP);
void PutLine(char Line[]);
void PrintOut(char Str[], int Margin, int MaxC, int MaxL);

int main(int argc, char** argv){
    FILE *fp = NULL;
    char Str[101];
    
    if((fp = fopen("Header","r")) == NULL){
        printf("File not Found\n");
        exit(ERR);
    }
    while (1) {
        if (fread(Str, sizeof(Str), 1, fp)==NULL) {
            break;
        }
    }
    printf("%s\n\n", Str);
    PrintOut(Str, 10, 5, 10);
    
    fclose(fp);
    return (EXIT_SUCCESS);
}
void PrintOut(char Str[], int Margin, int MaxC, int MaxL){
    char Line[101];
    int StartP, LineC, MarginP, CurrentP, EndP;
    
    StartP = 0;
    LineC = 0;
    for(MarginP = 0 ; MarginP < Margin ; MarginP++){
        Line[MarginP] = SP;
    }
    //EOS??
    while(Str[StartP] != EOS){
        GetPosition(Str, StartP, MaxC, &EndP);
        
        for(CurrentP = Margin ; StartP < EndP ; CurrentP++){
            Line[CurrentP] = Str[StartP];
            StartP++;
        }
        Line[CurrentP] = EOS;
        PutLine(Line);
        LineC++;
        while(LineC >= MaxL){
            printf("%c", FF);
            LineC = 0;
        }
        while(Str[StartP] == NL){
            StartP++;
        }
    }

}
void GetPosition(char Str[], int StartP, int MaxC, int* EndP){
    *EndP = StartP;
    while((Str[*EndP] != EOS) && (Str[*EndP] != NL) && (*EndP < (StartP + MaxC))){
        *EndP = *EndP + 1;
    }
}
void PutLine(char Line[]){
    int CurrentP;
    for(CurrentP = 0 ; Line[CurrentP] != EOS ; CurrentP++){
        putchar(Line[CurrentP]);
    }
    putchar('\n');
}
