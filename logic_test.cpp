#include<bits/stdc++.h>
using namespace std;

int main() {

    int matrix[3][3];
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            matrix[i][j] = -1;
        }
    }

    matrix[0][2] = 1;
    matrix[1][0] = 1;
    matrix[2][0] = 1;

    int horizontal_check = 0;
    int vertical_check = 0;
    bool ans = false;
    bool ans1 = false;
    bool ans3 = false;

    // horizontal check for pattern
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(matrix[i][j] == 1) {
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

    // vertical check for pattern
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(matrix[j][i] == 1) {
                vertical_check++;
            }
        }
        if(vertical_check == 3) {
            ans1 = true;
        }
        else {
            vertical_check = 0;
        }
    }


    // diagonal check for pattern
    int zero = 0;
    int one = 1;
    int two = 2;

    if(matrix[zero][zero] == matrix[one][one] == matrix[two][two] == 1) {
        ans3 = true;
    }
    else if(matrix[zero][two] == matrix[one][one] == matrix[two][zero] == 1) {
        ans3 = true;
    }
    else {
        ans3 = false;
    }



    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    // cout<<"Horizontal check: "<<ans<<endl;
    // cout<<"Vertical check: "<<ans1<<endl;
    // cout<<"Diagonal check: "<<ans3;

    srand(time(0));
    cout<<rand() % 3;

    return 0;
}