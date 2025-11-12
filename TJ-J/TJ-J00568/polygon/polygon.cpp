#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    long long b[5000];
    b[0] = 9;
    int c = 3;
    long long ans = 0;
    for(int i = 1;i<=n-5;i++){
        ans  = b[i-1] + c*c;
        c+=2;
    }
    return 0;
}
