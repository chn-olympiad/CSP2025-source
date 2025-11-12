#include<bits/stdc++.h>
using namespace std;
const int N=20;
int n,m,a[N][N],soe[110],sr,x=1,y=1,flag;
int dir[]={1,-1};
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>soe[i];
	}
	sr=soe[1];
	sort(soe+1,soe+n*m+1,greater<int>());
	for(int cnt=1;cnt<=n*m;cnt++){
		a[x][y]=soe[cnt];
		if(soe[cnt]==sr){
			cout<<y<<' '<<x;
			break;
		}
		x+=dir[flag];
		if(x>n){
			x=n,y++,flag=!flag;
		}
		if(x<1){
			x=1,y++,flag=!flag;
		}
	}
	return 0;
}
