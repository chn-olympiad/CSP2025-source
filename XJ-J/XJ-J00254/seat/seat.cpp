#include<iostream>
using namespace std;
int n,m;
int a[150],t[150],xy[20][20];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
        t[a[i]]++;
    }
    int tmp=a[0],tmp2;
    for(int i=100;i>=tmp;i--){
        if(t[i]!=0){
            tmp2++;
        }
    }
    int top=100;
    for(int i=1;i<=n;){
        for(int j=1;j<=m;){
            if(top==tmp){
                cout<<j<<" "<<i;
                return 0;
            }
            if(t[top]==0){
                while(t[top]==0){
                    top--;
                }
            }else{
                xy[i][j]=t[top];
                top--;
            }
            if(j%2==1&&i==m)j++;
            else if(j%2==1)i++;
            else if(j%2==0&&i==1)j++;
            else if(j%2==0)i--;
        }
    }
    return 0;
}
