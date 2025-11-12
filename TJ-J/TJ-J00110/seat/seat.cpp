#include<bits/stdc++.h>
#define ll long long;
using namespace std;
int n,m,r,b=1;
int a[15][15],maxn[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){

	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>maxn[i];
	}
	r=maxn[1];
	sort(maxn+1,maxn+1+(m*n),cmp);
	for(int i=1;i<=n;i++){
		if(i%2!=0){
			for(int j=1;j<=m;j++){
				a[j][i]=maxn[b];
				b++;
			}
		}
		else if(i%2==0){
			for(int j=m;j>=1;j--){
				a[j][i]=maxn[b];
				b++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==r){
				cout<<i<<' '<<j<<endl;
				return 0;
			}
		}
	}
}
