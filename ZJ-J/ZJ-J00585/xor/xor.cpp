#include<bits/stdc++.h>
using namespace std;

struct qj{
	long long l,r;
}b[1111111];

bool cmp(qj x,qj y){
	return x.r<y.r;
}
long long n,m,k,a[511111];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		long long u;
		cin>>u;
		a[i]=a[i-1]^u;
		//cout<<a[i]<<"\n";
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if((a[j]^a[i-1])==k){
				b[++m]={i,j};
				//cout<<i<<" "<<j<<"\n";
			}
		}
	}
	if(!m){
		cout<<0;
		return 0;
	}
	sort(b+1,b+m+1,cmp);
	long long f=b[1].r,ans=1;
	//cout<<b[1].l<<" "<<f<<"\n";
	for(long long i=2;i<=m;i++){
		if(b[i].l>f){
			f=b[i].r;
			ans++;
			//cout<<b[i].l<<" "<<f<<"\n";
		}
	}
	cout<<ans;
	return 0;
}
