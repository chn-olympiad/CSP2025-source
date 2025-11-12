#include<bits/stdc++.h>
using namespace std;
//#define int long long
int fl=1;
int f[200100],c[100100],K[1010][1010],mi,sc[100100];
int n,m,k,i,j,t;
struct no{
	int x,y,z;
}a[2000100];
bool cmp(no q,no h){
	return q.z<h.z;
}
int find(int x){
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
int st(no a[1000100]){
	int ans=0;
	for(int i=1;i<=n;i++) f[i]=i;
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++){
		int fx=find(a[i].x),fy=find(a[i].y);
		if(fx!=fy) f[fx]=fy,ans+=a[i].z;
	}
	return ans;
}
void dfs(int sum,int kkk){
	if(sum==kkk){
		int qwe=0;
		t=m;
		for(int i=1;i<=sum;i++){
			for(int j=1;j<=n;j++){
				a[++t].x=sc[i];
				a[t].y=j;
				a[t].z=K[sc[i]][j];
			}
			qwe+=c[sc[i]];
		}
		mi=min(mi,qwe+st(a));
	}
	else{
		for(int ss=n+1;ss<=n+k;ss++){
			sc[sum+1]=i;
			for(int i=1;i<=sum+1;i++)
				for(int j=i+1;j<=sum;j++)
					if(sc[i]==sc[j])
						return ;
			dfs(sum+1,kkk);
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[i].x=u;
		a[i].y=v;
		a[i].z=w;
	}
	for(i=n+1;i<=n+k;i++){
		cin>>c[i];
		if(c[i]) fl=0;
		int fl2=0;
		for(j=1;j<=n;j++){
			cin>>K[i][j];
			if(!K[i][j]) fl2=1;
		}
		if(!fl2) fl=0;
	}
	if(fl){
		for(i=n+1;i<=n+k;i++){
			for(int j=1;j<=n;j++){
				a[++t].x=i;
				a[t].y=j;
				a[t].z=K[i][j];
			}
		}
		mi=st(a);
		cout<<mi;
		return 0;
	}
	t=m;
	mi=st(a);
	for(i=1;i<=k;i++){
		dfs(0,i);
	}
	cout<<mi;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
