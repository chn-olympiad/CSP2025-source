#include<bits/stdc++.h>
#define int long long 
#define O1145 ios::sync_with_stdio(false);
#define O1919 cin.tie(0),cout.tie(0);
#define mid ((l+r)>>1)
using namespace std;
const int N=10+5;
int n,m,a[N][N],v[N*N];
signed main(){
//	O1145 O1919     
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>v[i];
	int now=v[1];
	sort(v+1,v+n*m+1);
	int x=1,y=1;bool op=false;
	for(int i=n*m;i>=1;i--){
//		cout<<x<<" "<<y<<endl;
		if(v[i]==now){cout<<x<<" "<<y<<endl;return 0;}
		if(!op){
			y++;
			if(y==n+1)op=true,x++,y--;
		}
		else{
			y--;
			if(y==0)op=false,x++,y=1;
		}
	}
	return 0;
}
