#include<bits/stdc++.h>
using namespace std;

// pattern_type = 0 , 1 (O,X)
string name;
int random_number() {
    srand(time(0));
    int computer_input = rand() % 3;
    return computer_input;
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
            cout<<arr[i][j]<<" ";
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
            int computer_input_row = random_number();
            int computer_input_col = random_number();

            matrix[computer_input_row][computer_input_col] = 0;
            // cout<<computer_input_row<<" "<<computer_input_col<<endl;

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