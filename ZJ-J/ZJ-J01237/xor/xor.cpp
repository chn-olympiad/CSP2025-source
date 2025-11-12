#include<bits/stdc++.h>
using namespace std;
long long a[500005],st[500005],ans;
long long cnt,sum;
struct YH{
	long long l;
	long long r;
}p[500005];
void found(long long x){
	if(x==cnt+1){
		ans=max(ans,sum);
		return ;
	}
	if(st[p[x].l]==0){
		sum++;
		for(long long i=p[x].l;i<=p[x].r;i++){
			st[i]=1;
		}
		found(x+1);
		sum--;
		for(long long i=p[x].l;i<=p[x].r;i++){
			st[i]=0;
		}
	}
	found(x+1);
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,k,m=0,h=1;
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) h=0;
		m+=a[i];
		a[i]=(a[i-1]^a[i]);
	}
	if(m==n&&h==1){
		cout<<n/2;
		return 0;
	}
	if(m<n&&h==1){
		if(k==1){
			cout<<m;
			return 0;
		}
		if(k==0){
			cout<<m/2;
			return 0;
		}
	}
	for(long long l=1;l<=n;l++){
		for(long long r=l;r<=n;r++){
			if((a[r]^a[l-1])==k){
				cnt++;
				p[cnt].l=l;
				p[cnt].r=r;
			}
		}
	}
	found(1);
	cout<<ans;
	return 0;
}
