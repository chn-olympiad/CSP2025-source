#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,sum=0;
	cin>>n>>m>>k;
	int u[m],v[m],w[m],a[n],b[n],j=0,c1[k],minn=2147483647,cnt[n]={0};
	for(int i=0;i<m;i++) {
		cin>>u[i]>>v[i]>>w[i];
		cnt[u[i]-1]++,cnt[v[i]-1]++; 	
	}
	sort(w,w+m);
	for(int i=0;i<m/2;i++) sum+=w[i];
	for(int i=0;i<k;i++) {
		cin>>c1[i];
		for(int i=0;i<n;i++) cin>>a[i];
	}
	for(int i=0;i<n;i++)
		if(cnt[i]==0) b[j]=i,j++;
	for(int i=0;i<j;i++) cout<<b[i]<<" ";
	for(int i=0;i<k;i++) {
		for(int i=0;i<j;i++) sum+=a[b[j]];	
		minn=min(minn,sum+c1[i]);
	}
	cout<<minn+sum;
	return 0;
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4*/
