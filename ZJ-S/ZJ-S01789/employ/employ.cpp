#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,a[N],c[N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;
		scanf("%c",&x);
		a[i]=x-'0';	
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	if(m==n)cout<<0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	solve();
}
