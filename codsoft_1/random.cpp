#include<bits/stdc++.h>
using namespace std;
int main(){
    int secret=rand()%100+1;
    int guess;
    int attempts;
    cout<<"guess number between 1-100!"<<endl;
    do{
        cin>>guess;
        if(guess<secret){
            cout<<"Guessed number is too low!!"<<endl;
        }
        else if(guess>secret){
            cout<<"Guessed number is too high!!"<<endl;
        }
        else{
            cout<<"Congratulations!! You guessed the right number!!"<<endl;
        }
    } while(guess!=secret);
    return 0;
}
