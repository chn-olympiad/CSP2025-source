#include<bits/stdc++.h>
using namespace std;
int n,m,id,rscore;
int sco[105];
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>sco[i];
    }
    rscore=sco[1];
    //cout<<rscore<<endl;
    sort(sco+1,sco+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(sco[i]==rscore){
            id=i;
        }
    }
    //cout<<id<<endl;
    int h,l;
    if(id%n==0){
        l=id/n;
    }else{
        l=id/n+1;
    }

    if(l%2==1&&id%n==0){
        h=n;
    }
    else if(l%2==1&&id%n!=0){
        h=id%n;
    }else{
        h=n+1-id%n;
    }
    cout<<l<<" "<<h;
    fclose(stdin);
    fclose(stdout);
    return 0;
}