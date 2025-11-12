#include<bits/stdc++.h>
using namespace std;
struct edge{
	int l,r;
}a[1000005];
int n,k,cnt,maxl;
long long ans;
int v[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int z=0;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		z=0;
		for(int j=i;j<=n;j++){
			z=z^v[j];
			if(z==k){
				a[++cnt].l=i;
				a[cnt].r=j;
				break;
			}
		}
	}
	
	a[0].l=0;
	a[0].r=0;
	int nx=0;
	while(nx<cnt){
		int minr=0x3f3f3f3f,minid=-1;
		for(int i=nx;i<=cnt;i++){
			if(minr>a[i].r&&a[nx].r<a[i].l){
				minr=a[i].r;
				minid=i;
			}
		}
		if(minid==-1)break;
		nx=minid;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}