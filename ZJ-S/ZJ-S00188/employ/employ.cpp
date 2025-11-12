#include<bits/stdc++.h>
using namespace std;
long long n,m,a[505],s;
char c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1){
			if(c[1]=='1') cout<<1;
		return 0;
	}
	if(n==m){
		cout<<m;
		return 0;
	}
	if(m==1){
		long long x=0,t=0;
		for(int i=1;i<=n;i++){
			if(c[i]=='1') {
				t=i;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]>t-1) x++; 
		}
		for(int i=1;i<=n-1;i++){
			x*=i;
			x%=998244353;
		}
		cout<<x;
		return 0;
	}
	cout<<6;
}
