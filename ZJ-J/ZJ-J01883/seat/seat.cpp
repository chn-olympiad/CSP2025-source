#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+7,M=300,inf=1e18,mod=1e9+7;
int n,m,X,a[N];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	X=a[1];
	sort(a+1,a+n*m+1);
	int x=1,y=1;//x->ÐÐ,y->ÁÐ 
	for(int i=n*m;i>=1;i--){
		if(a[i]==X){
			cout<<y<<" "<<x;
			break;
		}
		if((x==n&&y%2==1)||(x==1&&y%2==0))y++;
		else if(y%2)x++;
		else x--;
	}
	return 0;
}
