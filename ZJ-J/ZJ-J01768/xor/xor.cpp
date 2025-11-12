#include<bits/stdc++.h>
using namespace std;
long long n, k;
long long a[500100],sum[500100];
long long t=0;
struct node{
	int l,r;	
}f[500005];
bool cmp(node x,node y){
	return x.r<y.r;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=(sum[i-1]^a[i]);
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				//cout<<i<<" "<<j<<endl;
				f[++t].l=i;
				f[t].r=j;
				break;
			}
		}
	}
	sort(f+1,f+t+1,cmp);
	long long ans=1;
	long long lar=f[1].r;
	for(int i=1;i<=t;i++){
		if(f[i].l>lar){
			lar=f[i].r;
			ans++;
		}
	}
	
	cout<<ans<<endl;
    return 0;
}
