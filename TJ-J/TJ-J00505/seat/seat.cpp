#include<bits/stdc++.h>
using namespace std;
int n,m;
struct student{
    int num,id=0;
}seat[105];
bool cmp(student a,student b){
    return a.num>b.num;
}
int main(){
    freopen ("seat.in","r",stdin);
    freopen ("seat.out","w",stdout);
    cin>>n>>m;
    seat[1].id=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>seat[(i-1)*m+j].num;
        }
    }
    sort(seat+1,seat+1+n*m,cmp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i%2!=0){
                if(seat[(i-1)*m+j].id==1){
                        cout<<i<<' '<<j;
                        return 0;
                }
            }else{
                if(seat[i*m-j+1].id==1){
                        cout<<i<<' '<<j;
                        return 0;
                }
            }
        }
    }
    return 0;
}
