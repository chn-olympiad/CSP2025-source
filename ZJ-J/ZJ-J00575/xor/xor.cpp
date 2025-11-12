#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=4e6+5;
int n,k,a[MAXN],pre[MAXN],f[MAXN],pos[MAXN];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=(1<<20);i++){
		pos[i]=f[i]=-1;
	}
	pos[0]=f[0]=0;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]^a[i];
		//cout<<pre[i]<<"\n";
		f[i]=f[i-1];
		if(a[i]==k) f[i]=max(f[i],f[i-1]+1);
		if(pos[pre[i]^k]!=-1) f[i]=max(f[i],f[pos[pre[i]^k]]+1);
		pos[pre[i]]=i;
	}
	cout<<f[n];
	return 0;
}
