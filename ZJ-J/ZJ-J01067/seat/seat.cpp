#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;int a[n*m+1],g[n+1][m+1];
	for(int i=1;i<=n*m;++i) cin>>a[i];
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int pos=0;
	bool flag=1;
	for(int j=1;j<=m&&flag;++j){
		for(int i=1;i<=n;++i){
			++pos;
			if(a[pos]==r){
				cout<<j<<' '<<i;
				flag=0;
				break;
			}
		}
		++j;
		for(int i=n;i>=1&&flag;--i){
			++pos;
			if(a[pos]==r){
				cout<<j<<' '<<i;
				flag=0;
				break;
			}
		}
	}
	/*cout<<m<<' '<<n<<'\n';
	cout<<pos<<' '<<r<<'\n';
	for(int i=1;i<=n*m;++i) cout<<a[i]<<' ';*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
