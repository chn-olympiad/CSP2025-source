#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int n,m,k;
int a[maxn];
int mp[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	int num=0;
	for(int j=1;j<=m;j++){
		if(j%2==0){
			for(int i=n;i>=1;i--){
				mp[i][j]=a[++num];
			}
		}else{
			for(int i=1;i<=n;i++){
				mp[i][j]=a[++num];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==k){
				cout<<j<<" "<<i<<"\n";
				return 0;
			}
		}
	}
}
