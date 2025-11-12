//杨昕然  西安高新第一中学   SN-S00399
#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x1,x2,x3,Len[15],Sum[15],dad[10015],ans;
vector<vector<pair<long long,long long>>> v;
vector<vector<long long>> V;
long long Find(long long x){
	if(dad[x]!=-1)return dad[x]=Find(dad[x]);
	return x;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(dad,-1,sizeof(dad));
	cin>>n>>m>>k;
	v=vector<vector<pair<long long,long long>>>(n+k+5);
	for(long long i=1; i<=m; i++){
		cin>>x1>>x2>>x3;
		v[x1].push_back({x2,x3});
		v[x2].push_back({x1,x3});
		V.push_back({x3,x1,x2});
	}
	for(long long i=1; i<=k; i++){
		cin>>x1;
		for(long long j=1; j<=n; j++){
			cin>>x1;
			V.push_back({x1,i+n,j});
		}
	}
	stable_sort(V.begin(),V.end());
	for(long long i=0; i<V.size(); i++){
		x1=Find(V[i][1]);
		x2=Find(V[i][2]);
		if(x1!=x2){
			dad[x1]=x2;
			ans+=V[i][0];
			if(V[i][1]>n)Len[V[i][1]-n]++,Sum[V[i][1]-n]+=V[i][0];
			if(V[i][2]>n)Len[V[i][2]-n]++,Sum[V[i][2]-n]+=V[i][0];
		}
	}
	for(long long i=1; i<=k; i++){
		if(Len[i]==1){
			ans-=Sum[i];
		}
	}
	cout<<ans;
	return 0;
}
/*
1.
5 6 3
1 2 3
2 3 4
3 4 5
4 5 6
1 3 4
3 5 2
0 1 2 3 4 9
0 100 100 100 100 100
0 10 10 10 10 10
ans:12


longlong

1.最小生成树 
*/
