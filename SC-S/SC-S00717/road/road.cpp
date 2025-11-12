#include<bits/stdc++.h>
#define int long long int
using namespace std;
int a[1000010],b[1000010],c[1000010],d[20][10010],f[10010],k,l,m,n,s,x,y;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
inline int find(int z){
	if(f[z]==z) return z;
	return f[z]=find(f[z]);
}
signed main(){
	freopen("road3.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		l++;
		cin>>a[l]>>b[l]>>c[l];
		q.push({c[l],l});
	}
	for(int i=1;i<=k;i++){
		cin>>d[i][0];
		for(int j=1;j<=n;j++) cin>>d[i][j];
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				l++;
				a[l]=j;
				b[l]=k;
				c[l]=d[i][j]+d[i][k];
				q.push({c[l],l});
			}
		}
	}
	x=n;
	while(x>1&&!q.empty()){
		y=q.top().second;
		q.pop();
		if(find(a[y])==find(b[y])) continue;
		f[a[y]]=b[y];
		s+=c[y];
		x--;
	}
	cout<<s;
	return 0;
}