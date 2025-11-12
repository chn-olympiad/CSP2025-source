#include <bits/stdc++.h>
int n,m,h;
int a[111];
int s[11][11];
int c,r;
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)cin>>a[i];
	int k=a[1];
	sort(a+1,a+n*m+1);
	int x=n*m;
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			int d=a[x--];
			if(i%2==1){
				s[j][i]=d;
			}else{
				s[n+1-j][i]=d;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(s[i][j]==k){
				c=j;
				r=i;
			}
		}
	}
	cout<<c<<' '<<r;
	return 0;
}//#Shang4Shan3Ruo6Shui4
