#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,s=0;
	long long u[10000],v[100000],w[1000000000],c[1000000000],a[1000000][10000000];
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
        scanf("%lld %lld %lld",&u[i],&v[i],&w[i]);
	}
	for(int j=1;j<=k;j++){
        scanf("%lld",&c[j]);
		for(int i=1;i<=m;i++){
			scanf("%lld",&a[j][i]);
		}
	}
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		if(w[j]<w[i]){
    			int t=w[j];
    			w[j]=w[i];
    			w[i]=t;
                t=v[j];
    			v[j]=v[i];
    			v[i]=t;
                t=u[j];
    			u[j]=u[i];
    			u[i]=t;	}}}
	long long q=INT_MAX;
	for(int i=1;i<=k;i++){
		q=min(c[i],q);
	}
	for(int i=1;i<=k;i++){
		if(c[i]==q)	q=i;
	}
	printf("%d\n",s);
	return 0;
}