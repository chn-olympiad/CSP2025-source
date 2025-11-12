#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[1001];
ll b[101][101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	ll gd=a[1];
	sort(a+1,a+n*m+1);
	ll k=n*m;
	//for(int i=1;i<=n*m;i++)cout<<a[i]<<' ';cout<<'\n';
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++)
				b[j][i]=a[k--];
		}else{
			for(int j=n;j>=1;j--)
				b[j][i]=a[k--];
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++)
//			cout<<b[i][j]<<' ';
//		cout<<'\n';
//	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(b[i][j]==gd){
				cout<<j<<' '<<i;
				return 0; 
			}
		}
	return 0;
}

