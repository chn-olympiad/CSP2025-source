#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=207;
int a[N];
int a1;
int n,m;
int num[N][N];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	int tot=0;
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			num[i][j]=a[++tot];
			if(a[tot]==a1){
				cout<<i<<" "<<j;
				return 0;
			}
		}
		++i;
		for(int j=n;j>=1;--j){
			num[i][j]=a[++tot];
			if(a[tot]==a1){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
