#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,seat[1210]={0};
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>seat[i];
    }
    int Rsum=seat[1];
    sort(seat+1,seat+n*m+1,cmp);
    int x=1,y=1,mode=1,sum=0;
    while(true){
        sum++;
        if(seat[sum]==Rsum){
            cout<<y<<" "<<x;
            return 0;
        }
        if(x+mode<=n&&x+mode>0){
            x+=mode;
        }
        else{
            y++;
            if(mode==1)mode=-1;
            else mode=1;
        }
    }
    return 0;
}
