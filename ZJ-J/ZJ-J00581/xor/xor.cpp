#include<bits/stdc++.h>

using namespace std;

const int N=2e6+5;

int n,k,a[N],pre[N],f[N],ans;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int s=0;
	memset(pre,-1,sizeof(pre));f[0]=0;pre[0]=0;
	for(int i=1;i<=n;i++){
		s^=a[i];f[i]=f[i-1];
		if(pre[s^k]!=-1)f[i]=max(f[i],f[pre[s^k]]+1);
		pre[s]=i;ans=max(ans,f[i]);
	}
	cout<<ans<<"\n";
	return 0;
}
