#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],b[500010],vis[500010];
int yh(int a,int b){
	if(a>b){
		int t=a;
		a=b;
		b=t;
	}
	int hou=0,x=1;
	while(a>0){
		int xian=(a%2+b%2)%2;
		a/=2;
		b/=2;
		hou+=x*xian;
		x*=2;
	}
	return hou+b*x;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) cnt++;
		b[i]=yh(b[i-1],a[i]);
	}
	if(k==0){
		if(cnt==n){
			cout<<n/2;
			return 0;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(yh(b[i],b[j-1])!=k) continue;
			int flag=0;
			for(int k=j;k<=i;k++){
				if(vis[k]==1){
					flag=1;
					break;
				}
			}
			if(flag==1){
				continue;
			}
			ans++;
			for(int k=j;k<=i;k++){
				vis[k]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
