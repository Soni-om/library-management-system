#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Book {
private:
    string Title;
    string Author;
    int ID;

public:
    Book() {
        Title = "add";
        Author = "add";
        ID = 0;
    }

    void showbook() {
       // cout << "-------------------------------------------------\n";
        cout << "Title :- " << Title << endl;
        cout << "Author name :- " << Author << endl;
        cout << "Book ID :- " << ID << endl;
     //   cout << "-------------------------------------------------\n";
    }

    void storbook(string t, string n, int I) {
        Title = t;
        Author = n;
        ID = I;
    }
    
    int getid(){
        return ID;
    }
    
    string getauthor(){
        return Author;
    }

    string gettitale(){
        return Title;
    }
};

    bool login() {
    string username, password;
    string uname = "Soni"; 
    string upaas = "1234";  
    int limit = 0;

    while (limit < 3) {
        cout << "\n--------- LOGIN SYSTEM ---------\n";
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;

        if (username == uname && password == upaas) {
            cout << "\nLogin Successful! Welcome Om Soni.\n";
            return true;
        } else {
            limit++;
            cout << /*"Invalid Credentials"*/"! Attempts left: " << 3 - limit << endl;
        }
    }
    return false;
}

//Data ko file me write karane ke liye 
void writeFile(Book books[] , int count){
    ofstream fileout;
    fileout.open("data.txt");
    if(fileout.is_open()){
        for(int i=0; i<count; i++){            
            fileout<<books[i].gettitale()<<endl;
            fileout<<books[i].getauthor()<<endl;
            fileout<<books[i].getid()<<endl;
            
        }
        fileout.close();
        cout<<"Data save \n";
    }
}
//Data ko file se reed karane ke liye 
int storfile(Book books[]){
    int i, count = 0;
    string t,a;
    ifstream filein;
    filein.open("data.txt");
    if(filein.is_open()){
         while(getline(filein,t) && getline(filein,a) ){
            if(filein>>i){
                filein.ignore();
                books[count].storbook(t, a, i);
                count++;
            }
    }
    filein.close();
    }
    return count;
}

int main() {
   
     
    if (login() == false) {
        cout << "Too many failed attempts." << endl;
        return 0; 
    }

    int choice;
    string t, n;
    int I;
    Book b1[100];
    int Tobooks = storfile(b1);


    cout << endl << "-----Welcome to library-----\n" << endl;

    while (true) {
        cout << "1. Add Book\n";
        cout << "2. Show Book\n";
        cout << "3. Search book\n";
        cout << "4. Exit\n";
        cout << "Enter no. to select row : ";
        while(!(cin>>choice)){
                cout <<  "Invalid input! Please enter a NUMBER : ";
                cin.clear();
                cin.ignore(1000,'\n');
                  }
      //  cin >> choice;
        cout << endl;

        if (choice == 1) {
            cout << "-----Add new Book-----" << endl;
            cout << "Enter title : ";
            cin.ignore();
            getline(cin, t);
            cout << "Enter Author name : ";
            getline(cin, n);
            cout << "Enter book ID in number: ";
            while(!(cin>>I)){
                cout <<  "Invalid input! Please enter a NUMBER for Book ID: ";
                cin.clear();
                cin.ignore(1000,'\n');
                  }
           // cin >> I;

            b1[Tobooks].storbook(t, n, I);
            Tobooks++;
            writeFile(b1,Tobooks);

            cout << "\n-----Book added successfully-----" << endl << endl;
        } 
        else if (choice == 2) {
            if (Tobooks == 0) {
                cout <<"|----------------------------------------|\n";
                cout <<"|  Library is empty. please aad a book   |\n" ;
                cout <<"|----------------------------------------|\n\n";
            } else {
                for (int i = 0; i < Tobooks; i++) {
                    cout << "-------------------------------" << endl;
                    cout << "Book :- " << i + 1 << endl;
                    b1[i].showbook();
                    cout << "-------------------------------" << endl;
                }
            }
        } 
        else if (choice == 3) {
                int searchid;
                string authorNmae;
                cout << "Enter book id to search : ";
                cin >> searchid;
                
                cout << "Enter Author name : ";
                cin.ignore();
                getline(cin,authorNmae);
                cout<<endl;
                
                bool found = false;
                for(int i=0; i<Tobooks; i++){
                   
                   if(b1[i].getid()==searchid && b1[i].getauthor() == authorNmae){
                   cout << "•••••Find book••••••\n";
                     b1[i].showbook();
                     found = true;
                   cout << "•••••***••••••\n";
                   cout<<endl<<endl;
                     
                   }
                }   
                    if(found == false){
                      cout << "--Not found-- \n\n"; 
                    }
                
           // cout << "Search functionality not yet implemented." <<endl<< endl;
        } 
        else if (choice == 4) {
                writeFile(b1,Tobooks);
                cout <<endl;
                cout <<"Thankyou for visiting "<<endl;
            break;
        } 
        else {
            cout << "-----Enter valid option-----" << endl;
        }
    }

    return 0;
}