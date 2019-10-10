
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

typedef struct teamStat{
    char teamName[50];
    int winScore=0;
}status;

int main(){
    int i;
    status teamStatus[9];
    for(i=0; i<8; i++){

        cin >> teamStatus[i].teamName;

    }

            int scoreTeamLeft,scoreTeamRight;
            char teamNameLeft[50],teamNameRight[50];
        int j;

    for(i=0; i<28; i++){
        scanf("%s %d - %d %s",&teamNameLeft,&scoreTeamLeft,&scoreTeamRight,&teamNameRight);

        for(j=0; j<8; j++){

            if(strcmp(teamNameLeft,teamStatus[j].teamName)==0){
                if(scoreTeamLeft > scoreTeamRight)teamStatus[j].winScore++;
            }else if(strcmp(teamNameRight,teamStatus[j].teamName)==0){
                if(scoreTeamRight > scoreTeamLeft)teamStatus[j].winScore++;
            }

        }
    }

    int flag=1;
    while(flag){
        flag=0;

        for(i=0; i<7; i++){
            if(teamStatus[i].winScore < teamStatus[i+1].winScore){
                status temp = teamStatus[i+1];
                teamStatus[i+1]=teamStatus[i];
                teamStatus[i]=temp;
                flag=1;
            }
        }

    }

    flag=1;
    while(flag){
        flag=0;

        for(i=0; i<7; i++){
            if(strcmp(teamStatus[i].teamName,teamStatus[i+1].teamName)>0 && teamStatus[i].winScore == teamStatus[i+1].winScore){
                status temp = teamStatus[i+1];
                teamStatus[i+1]=teamStatus[i];
                teamStatus[i]=temp;
                flag=1;
            }
        }

    }

    for(i=0; i<8; i++){
        cout<<teamStatus[i].teamName<<" "<<teamStatus[i].winScore<<endl;
    }



}
