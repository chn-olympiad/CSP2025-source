#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100001];
int k[12][12];
int ans,in;
int c,r;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ans=a[1];
	int p=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--){
				k[i][j]=a[++p];
				if(k[i][j]==ans){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j=1;j<=m;j++){
				k[i][j]=a[++p];
				if(k[i][j]==ans){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}