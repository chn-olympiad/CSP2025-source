#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
long long n,m,k,a[10010],sum=0,t[10010],t1=0;
int main(){
	fast;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	long long u[m+10],v[m+10],w[m+10];
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		sum+=w[i];
	}
	if(k==0){
		long long c[n*m+10];
		for(long long i=1;i<=m*n;i++){
			cin>>c[i];
		}
		sort(c+1,c+1+n*m);
		for(long long i=1;i<=n;i++){
			sum-=c[i];
		}
		cout<<sum;
	}
	else{
		for(int i=1;i<=m;i++){
			a[u[i]]++;
			a[v[i]]++;
		}
		for(int i=2;i<n;i++){
			if(a[i]>2){
				long long mx=-1,x,y;
				for(int j=1;j<=m;j++){
					if(u[j]==i){
						if(w[i]>mx){
							mx=w[i];
							x=u[j];
							y=v[j];
						}
					}
				}
				sum-=mx;
				a[x]--;
				a[y]--;
			}
		}
		cout<<sum;
	}
	return 0;
}

