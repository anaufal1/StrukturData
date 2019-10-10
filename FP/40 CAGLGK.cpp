#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> _pair;
typedef pair<int,_pair> _pair2;

typedef struct box{

    _pair move1 = make_pair(2,1);
    _pair move2 = make_pair(2,-1);
    _pair move3 = make_pair(-2,1);
    _pair move4 = make_pair(-2,-1);
    _pair move5 = make_pair(1,2);
    _pair move6 = make_pair(-1,2);
    _pair move7 = make_pair(1,-2);
    _pair move8 = make_pair(-1,-2);

}movement;

_pair sumPair(_pair a,_pair b){
    _pair results;
    int newPosX = a.first + b.first;
    int newPosY = a.second + b.second;

    results = make_pair(newPosX,newPosY);

    return results;
}

int main(){

    movement walk;

    int boardSize;
    cin>>boardSize;
    int xPos, yPos;
    cin>>xPos>>yPos;
    _pair origin = make_pair(xPos,yPos);
    cin>>xPos>>yPos;
    _pair destination = make_pair(xPos,yPos);

    queue<_pair2> movementHistory;
    movementHistory.push(make_pair(0,origin));

   // int ways=1;
    _pair2 temp;
    while(1){

        if(origin==destination){
            cout <<"0"<<endl;
            break;
        }

        if(sumPair(movementHistory.front().second,walk.move1) == destination || sumPair(movementHistory.front().second,walk.move2) == destination ||sumPair(movementHistory.front().second,walk.move3) == destination||sumPair(movementHistory.front().second,walk.move4) == destination||sumPair(movementHistory.front().second,walk.move5) == destination||sumPair(movementHistory.front().second,walk.move6) == destination || sumPair(movementHistory.front().second,walk.move7) == destination||sumPair(movementHistory.front().second,walk.move8) == destination)
        {
            cout<<movementHistory.front().first+1<<endl;
            break;
        }
       \
        _pair currentPath = movementHistory.front().second;
        currentPath = sumPair(currentPath,walk.move1);
        if(currentPath.first >= 1 && currentPath.second <=boardSize){
            temp = make_pair(movementHistory.front().first+1,currentPath);
            movementHistory.push(temp);
        }

        currentPath = movementHistory.front().second;
        currentPath = sumPair(currentPath,walk.move2);
        if(currentPath.first >= 1 && currentPath.second <=boardSize){
            temp = make_pair(movementHistory.front().first+1,currentPath);
            movementHistory.push(temp);
        }

        currentPath = movementHistory.front().second;
        currentPath = sumPair(currentPath,walk.move3);
        if(currentPath.first >= 1 && currentPath.second <=boardSize){
            temp = make_pair(movementHistory.front().first+1,currentPath);
            movementHistory.push(temp);
        }

         currentPath = movementHistory.front().second;
        currentPath = sumPair(currentPath,walk.move4);
        if(currentPath.first >= 1 && currentPath.second <=boardSize){
           temp = make_pair(movementHistory.front().first+1,currentPath);
            movementHistory.push(temp);
        }

         currentPath = movementHistory.front().second;
        currentPath = sumPair(currentPath,walk.move5);
        if(currentPath.first >= 1 && currentPath.second <=boardSize){
           temp = make_pair(movementHistory.front().first+1,currentPath);
            movementHistory.push(temp);
        }

         currentPath = movementHistory.front().second;
        currentPath = sumPair(currentPath,walk.move6);
        if(currentPath.first >= 1 && currentPath.second <=boardSize){
          temp = make_pair(movementHistory.front().first+1,currentPath);
            movementHistory.push(temp);
        }

         currentPath = movementHistory.front().second;
        currentPath = sumPair(currentPath,walk.move7);
        if(currentPath.first >= 1 && currentPath.second <=boardSize){
            temp = make_pair(movementHistory.front().first+1,currentPath);
            movementHistory.push(temp);
        }

         currentPath = movementHistory.front().second;
        currentPath = sumPair(currentPath,walk.move8);
        if(currentPath.first >= 1 && currentPath.second <=boardSize){
            temp = make_pair(movementHistory.front().first+1,currentPath);
            movementHistory.push(temp);
        }

        movementHistory.pop();

    }

}
