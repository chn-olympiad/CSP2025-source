#include<bits/stdc++.h>
using namespace std;
int c[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b;
    cin>>a>>b;
    for(int i=0;i<a*b;i++){
        cin>>c[i];
    }
    int d=c[0];
    sort(c,c+a*b);
    int e=1;
    for(int i=a*b-1;i>=0;i--){
        if(d!=c[i]){
            e++;
        }
        else{
            break;
        }
    }
    if(e%a==0){
        cout<<e/a<<" ";
        if((e/a+1)%2==1){
            cout<<e%a;
        }
        else{
            cout<<a-e%a;
        }
    }
    else{
        cout<<e/a+1<<" ";
        if((e/a+1)%2==1){
            cout<<e%a;
        }
        else{
            cout<<a+1-e%a;
        }
    }
    return 0;
}
