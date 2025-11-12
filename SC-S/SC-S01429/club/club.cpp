#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
//#define int long long
using namespace std;
struct node{
	int nv,nid,nj;	//a:v,b:id
	node(int x,int y,int z):nv(x),nid(y),nj(z){}
};
struct cmp{
	bool operator()(node x,node y){
		return x.nv>y.nv;
	}
};
int t,n,a[100010][4],dp[100010];
priority_queue<node,vector<node>,cmp>pq[4];
int maxa(int i){
	int an=0,maxx=0;
	for(int j=1;j<=3;j++)
		if(a[i][j]>maxx)
			maxx=a[i][j],an=j;
	return an;
}
int lasa(int i){
	int an=0,minx=0x3f3f3f3f;
	for(int j=1;j<=3;j++)
		if(a[i][j]<minx)
			minx=a[i][j],an=j;
	return an;
}
int seca(int i){
	return 6-maxa(i)-lasa(i);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		for(int i=1;i<=3;i++)
			while(!pq[i].empty())
				pq[i].pop();
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=n;i++){
			int fi=maxa(i),se=seca(i),la=lasa(i);
			if(pq[fi].size()<n/2){
				pq[fi].push(node(a[i][fi],i,fi));
				dp[i]=dp[i-1]+a[i][fi];
			}
			else{
				node cha=pq[fi].top();
//				cout<<"----"<<endl;
//				cout<<cha.nid<<" "<<maxa(cha.nid)<<" "<<lasa(cha.nid)<<" "<<seca(cha.nid)<<endl;
//				cout<<a[1][1]<<" "<<lasa(1)<<endl;
//				cout<<dp[i-1]<<" "<<cha.nv<<" "<<a[i][fi]<<" "<<a[cha.nid][seca(cha.nid)]<<" "<<dp[i-1]+a[i][se]<<endl;
//				cout<<"----"<<endl;
				if(cha.nv<a[i][fi]||dp[i-1]-cha.nv+a[i][fi]+a[cha.nid][seca(cha.nid)]>dp[i-1]+a[i][se]){
					pq[fi].pop();
					pq[fi].push(node(a[i][fi],i,fi));
					dp[i]=dp[i-1]-cha.nv+a[i][fi]+a[cha.nid][seca(cha.nid)];
					pq[seca(cha.nid)].push(node(a[cha.nid][seca(cha.nid)],cha.nid,seca(cha.nid)));
				}
				else{
					pq[se].push(node(a[i][se],i,se));
					dp[i]=dp[i-1]+a[i][se];
				}
			}
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}

/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/