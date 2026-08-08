#include <iostream>
using namespace std;
void showMenu(){
    cout<<"Menu"<<endl;
    cout<<"\n"<<endl;
    cout<<"1. Start Game"<<endl;
    cout<<"2. Exit"<<endl;
    cout<<"Choose an option: "; 
}

int main(){
    bool running(true);
    while(running){
        showMenu();
    


    int choice;
    cin>> choice;
    cout<<"you chose:"<<choice<<endl;
    
    switch(choice){
        case 1:
            //startgame();
            break;
        case 2:
            running = false;
            break;
        default:
            cout<<"Invalid choice"<<endl;
            break;
    }

return 0;

}

}
