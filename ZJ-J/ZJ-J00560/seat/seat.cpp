#include<bits/stdc++.h>
using namespace std;
const int N=1e2+7;
int n,m;
int a[N];
int cmp(int x,int y){return x>y;}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int t=a[1];
    int nx=1,ny=1,f=0;
    sort(a+1,a+n*m+1,cmp);
    for(int i=2;i<=n*m;i++){
    	if(!f){
    		if(ny==n)nx++,f^=1;
    		else ny++;
		}
		else{
			if(ny==1)nx++,f^=1;
			else ny--;
		}
		if(a[i]==t)break;
	}
	cout<<nx<<" "<<ny<<'\n';
}