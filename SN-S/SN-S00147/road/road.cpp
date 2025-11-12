#include<bits/stdc++.h>
using namespace std;
long long cnt1;
long long n,m,k,mi;
long long u[1000005],v[1000005],w[1000005];
long long c[1000005],a[1000005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		
	}
	sort(w+1,w+1+m);
	mi += w[1]+w[2];
	long long minn;
	for(int i = 1;i<=k;i++){
		cin>>c[i];
		 
		for(int j = 1;j<=n;j++){
			cin>>a[j]; 
			sort(a+1,a+1+n);
			cnt1+=a[1]+a[2]+a[3];
		}
		minn += min(minn,cnt1);
		cnt1 = 0;
	}
	cout<<minn + mi;
}

