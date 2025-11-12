#include<bits/stdc++.h>
using namespace std;
int n,m;
int mp[150];
int a[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>mp[1];
	int op=mp[1];
	for(int i=2;i<=n*m;i++)cin>>mp[i];
	sort(mp+1,mp+1+n*m,greater<int>());
	int cnt=0;
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			a[i][j]=mp[++cnt];
			if(a[i][j]==op){cout<<j<<' '<<i;return 0;}
		}
		if(++j>m)break;
		for(int i=n;i;i--){
			a[i][j]=mp[++cnt];
			if(a[i][j]==op){cout<<j<<' '<<i;return 0;}
		}
	}
	return 0;
}