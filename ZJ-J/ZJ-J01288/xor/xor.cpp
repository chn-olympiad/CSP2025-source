#include<bits/stdc++.h>
using namespace std;
long long n,k,x,ans,l,r,a[500001];
struct node{
	int t,w;
}f[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)cin>>a[i];
	for(long long i=1;i<=n;i++){
		x=a[i];
		if(x==k)f[i].t=i,f[i].w=i;
		else{
			for(long long j=i+1;j<=n;j++){
				x=x xor a[j];
				if(x==k){
					f[i].t=i;
					f[i].w=j;
					break;
				}
			}
			if(x!=k)f[i].t=i,f[i].w=-1;
		}
	}
	for(long long i=1;i<=n;i++)
		if(f[i].w!=-1){
			l=i,r=f[i].w;
			break;
		}
	for(long long i=l+1;i<=n;i++)
		if(f[i].w==-1)continue;
		else if(l<=f[i].t&&f[i].t<=r&&r<=f[i].w)f[i].w=-1;
		else if(l<=f[i].t&&f[i].w<=r)f[l].w=-1,l=f[i].t,r=f[i].w;
		else l=f[i].t,r=f[i].w;
	for(long long i=1;i<=n;i++)
		if(f[i].w!=-1)ans++;
	cout<<ans;
	return 0;
}
