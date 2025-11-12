#include<bits/stdc++.h>
using namespace std;
const int N=209;
int a[N*N];
unordered_map<int,pair<int,int>>mp;
int r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];    
    }
    r=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    bool flag=false;
    int x=1,y=1;
    for(int i=1;i<=(n*m);i++){
        
        mp[a[i]]={x,y};
        if(y==n&&x%2==1){
            x++;
        }else if(y==1&&x%2==0){
            x++;
        }else if(x%2==1&&y>0&&y<=m){
            y++;
        }
        else if(x%2==0&&y>0&&y<=m){
            y--;
        }


    }
    cout<<mp[r].first<<" "<<mp[r].second<<endl;
}
