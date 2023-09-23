#include<bits/stdc++.h>
#include<fstream>
using namespace std;
//structure to store the list item
struct todolist{
    int id;
    string task;
};
int Id;
/* this function is the header for this application
   which shows the heading as "MY TODO LIST" 
*/
void banner(){
    cout<<"____________________________________"<<endl;
    cout<<"\t      MY TODO LIST!"<<endl;
    cout<<"____________________________________"<<endl;
}

/* this function adds a task to the list by prompting 
   a message to add the required task
*/
void addTask(){
    system("cls");
    cout<<"Enter the new task:"<<endl;
    todolist todo;
    cin.get();
    getline(cin,todo.task);
    char save;
    cout<<"Save? (y/n):";
    cin>>save;
    if(save=='y'){
        Id++;
        ofstream fout;
        fout.open("todo.txt",ios::app);
        fout<<"\n "<<Id;
        fout<<"\n"<<todo.task;
        fout.close();
        char more;
        cout<<"Do you want to add more? (y/n):";
        cin>>more;
        if(more=='y'){
            addTask();
        }
        else{
            system("cls");
            cout<<"Tasks added succesfully!"<<endl;
            return;
        }
    }
    system("cls");
}

/* this funcion displays all the tasks present in the list*/
void showTask(){
    system("cls");
    banner();
    todolist todo;
    ifstream fin;
    fin.open("todo.txt",ios::app);
    cout<<"Tasks:"<<endl;
    while(!fin.eof()){
        fin>>todo.id;
        fin.ignore();
        getline(fin,todo.task);
        if(todo.task!=""){
            cout<<todo.id<<": "<<todo.task<<endl;
        }
        else{
            cout<<"List Empty!"<<endl;
            break;
        }
    }
        fin.close();
        char exit;
        cout<<"Exit? (y/n):";
        cin>>exit;
        if(exit!='y'){
            showTask();
        }
        system("cls");
} 

/* this function deletes the required task by copying all the tasks
   to another file and neglecting the item to be deleted
*/
void deleteTask(){
    system("cls");
    int id;
    cout<<"Enter the task id to delete: ";
    cin>>id; 
    char del;
    cout<<"Delete? (y/n):";
    cin>>del;
    if(del=='y'){
        todolist todo;
        ofstream tempFile;
        tempFile.open("temp.txt",ios::app);
        ifstream fin;
        fin.open("todo.txt");
        int index=1;
        while(!fin.eof()){
            fin>>todo.id;
            fin.ignore();
            getline(fin,todo.task);
            if(todo.id!=id){
                tempFile<<"\n"<<index;
                tempFile<<"\n"<<todo.task;
                index++;
                Id--;
            }
        }
        fin.close();
        tempFile.close();
        remove("todo.txt");
        rename("temp.txt","todo.txt");
        system("cls");
        cout<<"Deleted successfully!"<<endl;
    }
    else{
        system("cls");
        cout<<"Deletion unsuccess!!"<<endl;
    }
    
}
/* main function*/
int main(){
    int choice;
    system("cls");
    while(true){
        banner();
        cout<<"1.Add Task"<<endl;
        cout<<"2.Show Task"<<endl;
        cout<<"3.Delete Task"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch(choice){
            case 1:addTask();
                    break;
            case 2:showTask();
                    break;
            case 3: deleteTask();
                    break;
            default:cout<<"invalid choice!!"<<endl;
        }

    }
    return 0;
}
