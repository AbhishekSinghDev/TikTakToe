#include<bits/stdc++.h>
using namespace std;

// pattern_type = 0 , 1 (O,X)
string name;
int random_number() {
    srand(time(0));
    int computer_input = rand() % 3;
    return computer_input;
}
int random_number_toss() {
    srand(time(0));
    return rand() %2 + 1;
}

bool horizontal_pattern_check(int arr[3][3], int pattern_type) {

    int horizontal_check = 0;
    bool ans = false;

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(arr[i][j] == pattern_type) {
                horizontal_check++;
            }
        }
        if(horizontal_check == 3) {
            ans = true;
        }
        else {
            horizontal_check = 0;
        }
    } 

    return ans;
}

bool vertical_pattern_check(int arr[3][3], int pattern_type) {

    int vertical_check = 0;
    bool ans = false;

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(arr[j][i] == pattern_type) {
                vertical_check++;
            }
        }
        if(vertical_check == 3) {
            ans = true;
        }
        else {
            vertical_check = 0;
        }
    }

    return ans;
}

bool diagonal_pattern_check(int arr[3][3], int pattern_type) {
    int zero = 0;
    int one = 1;
    int two = 2;

    bool ans = false;

    if(arr[zero][zero] == pattern_type and arr[one][one] == pattern_type and arr[two][two] == pattern_type) {
        ans = true;
    }
    else if(arr[zero][two] == pattern_type and arr[one][one] == pattern_type and arr[two][zero] == pattern_type) {
        ans = true;
    }
    
    return ans;
}

void print_message_user() {
    cout<<name<<" is winner";
}

void print_message_computer() {
    cout<<"Computer is winner";
}

void print_matrix(int arr[3][3]) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout<<arr[i][j]<<"   ";
        }
        cout<<endl;
    }
}

int main() {

    int matrix[3][3];
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            matrix[i][j] = -1;
        }
    }

    cout<<"Enter your name: ";
    getline(cin, name);


    int user_choice;
    int computer_choice;
    int result_toss;
    cout<<"Choose any one to decide the turn"<<endl;
    cout<<"1.Head"<<endl;
    cout<<"2.Tail"<<endl;

    cout<<"Your choice: ";
    cin>>user_choice;
    if(user_choice == 1) {
        computer_choice = 2;
    }
    else computer_choice = 1;
    
    cout<<"You choosen: "<<user_choice<<endl;
    cout<<"Computer choosen: "<<computer_choice<<endl;

    // srand(time(0));
    // result_toss = rand()%2+1;
    result_toss = random_number_toss();
    cout<<endl;
    if(result_toss == user_choice) {
        cout<<name<<" won the toss!"<<endl;
        goto user_input;
    }
    else {
        cout<<"Computer won the toss!"<<endl;
        goto think_again;
    }
    

    user_input: 

        cout<<"Play board"<<endl;
        print_matrix(matrix);

        int row, col;
        cout<<"Enter your move (row, col): ";
        cin>>row>>col;

        
        matrix[row][col] = 1;

        if(horizontal_pattern_check(matrix, 1)) {
            print_message_user();
            cout<<endl;
            print_matrix(matrix);
        }
        else if(vertical_pattern_check(matrix, 1)) {
            print_message_user();
            cout<<endl;
            print_matrix(matrix);
        }
        else if(diagonal_pattern_check(matrix, 1)) {
            print_message_user();
            cout<<endl;
            print_matrix(matrix);
        }
        else {
            
            think_again:
                int computer_input_row = random_number();
                int computer_input_col = random_number();

            if(matrix[computer_input_row][computer_input_col] == 0) {
                goto think_again;
            }
            else if(matrix[computer_input_row][computer_input_col] == 1) {
                goto think_again;
            }
            else {
                matrix[computer_input_row][computer_input_col] = 0;
            }

            if(horizontal_pattern_check(matrix, 0)) {
                print_message_computer();
                // cout<<"horizontal";
                cout<<endl;
                print_matrix(matrix);
                
            }
            else if(vertical_pattern_check(matrix, 0)) {
                print_message_computer();
                // cout<<"Vertical";
                cout<<endl;
                print_matrix(matrix);
            }
            else if(diagonal_pattern_check(matrix, 0)) {
                print_message_computer();
                // cout<<"Diagonal";
                cout<<endl;
                print_matrix(matrix);
            }
            else {
                goto user_input;
            }
        }

    return 0;
}
