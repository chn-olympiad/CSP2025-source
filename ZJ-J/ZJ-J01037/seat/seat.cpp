#include<bits/stdc++.h>
using namespace std;
const int N=20;
int n,m,r,cs,p,cnt;
int a[400],ans[20][20];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cs=n*m;
	for(int i=1;i<=cs;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+cs,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				ans[j][i]=a[++cnt];
			}
		}
		else {
			for(int j=n;j>=1;j--)ans[j][i]=a[++cnt];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==r){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
