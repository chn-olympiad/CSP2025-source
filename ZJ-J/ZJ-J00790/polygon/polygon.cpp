#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,a[N],q[N];
long long ans=0,mod=998244353;
struct node{
	int x,y,z;
}f[N*N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q[i]=q[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	f[0].x=1;
	for(int i=1;i<=n;i++){
		for(int j=q[i];j>=a[i];j--){
			if(i>=3&&j>a[i]*2){
				ans+=f[j-a[i]].z;
				ans%=mod;
			}
			f[j].y+=f[j-a[i]].x;
			f[j].y%=mod;
			f[j].z+=(f[j-a[i]].y+f[j-a[i]].z)%mod;
			f[j].z%=mod;
		}
	}
	cout<<ans;
	return 0;
}