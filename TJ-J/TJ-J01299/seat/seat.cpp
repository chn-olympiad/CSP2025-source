#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in",'r',srdin);
    freopen("seat.out",'w',stdout);
    int n,m;
    cin>>n>>m;
    int r;
    cin>>r;
    int sum=1;

    for(int i=1;i<n*m;i++){
        int x;
        cin>>x;
        if(x>r)sum++;
    }
    int x=1,y=1;
    if(sum<n){
        x=1;y=sum;
    }
    else if(sum%n==0){
        int h=sum/n;
        x=h;
        if(h%2)y=n;
        else y=1;
    }
    else if((sum-1)%n==0){
        int h=(sum-1)/n;
        x=h+1;
        if(h%2)y=n;
        else y=1;
    }
    else{
        int h=(sum-(sum%n))/n;
        x=h+1;
        if(x%2)y=sum%n;
        else y=n-(sum%n)+1;
    }
    cout<<x<<' '<<y;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
