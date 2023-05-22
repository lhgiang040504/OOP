#include <iostream>
using namespace std;

void swap(int &a, int b){
    a = b;
}

void input(int arr[500][500], int shape){
    // input values into the array
    for (int i = 0; i < shape; i++)
        for (int j = 0; j < shape; j++)
            cin >> arr[i][j];
}

void COPY(int arr[500][500], int copy[500][500],int sub[500][500], int shape){
    for(int i = 0; i < shape; i++)
        for(int j = 0; j < shape; j ++){
            copy[i][j] = arr[i][j];
            sub[i][j]=arr[i][j];}
}

bool compare(int arr[500][500], int sub[500][500],int shape){
    for (int i = 0; i < shape; i++)
        for (int j = 0; j < shape; j++)
            if(arr[i][j] != sub[i][j])
                return true;
    return false;
}

bool special(int arr[500][500], int shape){
    for(int i=1; i < shape; i++)
        for(int j=1; j < shape; j++)
            if(arr[0][0] != arr[i][j])
                return false;
    return true;
}

int main(){
    int shape, k = 0;
    cin >> shape;
    int arr[500][500];
    int copy[500][500];
    int sub[500][500];
    input(arr, shape);
    COPY(arr, copy, sub, shape);
    
    do {
        if(special(arr, shape) == true)
            break;
        for (int i = 0; i < shape; i++)
            for (int j = 0; j < shape; j++){
                int x = (2*i + j) % shape;
                int y = (i + j) % shape;
                swap(arr[x][y], copy[i][j]);
            }
            for (int i = 0; i < shape; i++)
                for (int j = 0; j < shape; j++){
                    copy[i][j]=arr[i][j];
            }
        k ++;
    }
    while(compare(arr, sub, shape));
    cout << k;
    return 0;
}
