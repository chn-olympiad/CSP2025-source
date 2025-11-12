#include<bits/stdc++.h> 
using namespace std;
int a[200005],b[200005],c[200005],d[200005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k,cnt=0,ans=0 ;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=c[i-1]^a[i];
		d[i]=c[i]^k;
	}
	for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) if(c[i]==d[j]) a[++cnt]=i,b[cnt]=j,ans++;
	for(int i=2;i<=cnt;i++){
		if(a[i]<=b[i-1]) ans--,i++;
	}
	cout<<ans+1;
	return 0;
} 
