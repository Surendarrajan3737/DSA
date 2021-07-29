#include <iostream>
#include <vector>

using namespace std;

void Display(int n,int m,vector<int>& arr){
    for(int i=0;i<4;i++){
        if(arr[i] == n){
            cout << "The missing ele is " << m << '\n';
            cout << "The duplicate ele is " << n << '\n';
            return ;
        }
        else if(arr[i] == m){
            cout << "The missing ele is " << n << '\n';
            cout << "The duplicate ele is " << m << '\n';
        }
    }
}

int main()
{
    vector<int> arr;
    int num = 0;
    for(int i=0;i<4;i++){
        cin >> num;
        arr.push_back(num);
    }
    int sum = (arr.size()*(arr.size()+1))/2;
    long int sum_squ = (arr.size()*(arr.size()+1)*(2*arr.size()+1))/6;

    int sum_arr = 0;
    int sum_arr_squ = 0;        
    for(int i=0;i<4;i++){
        sum_arr += arr[i];
    }
    for(int i=0;i<4;i++){
        sum_arr_squ += (arr[i]*arr[i]);
    }

    //sum == sum_arr;
    // sum_squ == sum_arr_squ;

    int x = sum - sum_arr;          //n-m = x;
    long long int y = sum_squ - sum_arr_squ;  // n2 - m2 = y;

    cout << x << '\n';
    cout << y << '\n';
    /* 
    explanaton:
        (n-m) = x
        (n+m)(n-m) = y

        after sb=ubstituting 

        (n+m)x = y
        n+m = y/x;

        (n-m) + (n+m)= x + (y/x);

        2n = x + y/x;
        n = (x + (y/x))/2;
        m = (y/x) - ((x + (y/x))/2)
     */

    // Now by travessing through the arr we can say that the ele found is should be repeated and the other is missing

    int n = (x + (y/x))/2;
    int m = (y/x) - ((x + (y/x))/2);
    Display(n,m,arr);

    return 0;
}