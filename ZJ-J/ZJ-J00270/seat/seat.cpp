#include<bits/stdc++.h>
#define int long long
using namespace std;
int seat[101][101],a[1005];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)	seat[i][1]=i;
	for(int i=1;i<=n;i++){
		int l1=2*(n-i)+1,l2=2*n-l1;
		for(int j=2;j<=m;j++){
			if(j%2==0){
				seat[i][j]=seat[i][j-1]+l1;
			}
			else{
				seat[i][j]=seat[i][j-1]+l2;
			}
		}
	}
	for(int i=1;i<=n*m;i++)		cin>>a[i];
	int t=a[1],ans;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			ans=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seat[i][j]==ans){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
