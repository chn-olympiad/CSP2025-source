#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m,s,f[1000005],a[20][1000005],c[1000005],t[1000005];
struct node{
	int u,v,w;
}e[100005];
int cha(int x){
	if(f[x]==x)return x;
	return f[x]=cha(f[x]);
}
vector<int>g[100005],len[100005];
bool cmp(const node &A,const node &B){
	return A.w<B.w;
}
int cnt,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=s;i++){
		cin>>c[i];
		t[i]=2147483647;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			t[i]=min(t[i],a[i][j]);
		}
	}
	sort(e+1,e+n+1,cmp);
	for(int i=1;i<=n;i++){
		int x=cha(e[i].u);
		int y=cha(e[i].v);
		if(x!=y){
			cnt++;
			f[x]=y;
			ans+=e[i].w;
			g[e[i].u].push_back(e[i].v);
			g[e[i].v].push_back(e[i].u);
			len[e[i].u].push_back(e[i].w);
			len[e[i].v].push_back(e[i].w);
		}
		if(cnt==n-1){
			break;
		}
	}
	if(s>0){
		int sum,sum2,f;
		for(int k=1;k<=s;k++){
			for(int i=1;i<=n;i++){
				sum=sum2=0;
				for(int j=0;j<g[i].size();j++){
					int v=g[i][j];
					if(i>v)continue;
					sum=sum+len[i][j];
					sum2=sum2+a[k][v];
				}
				if(c[k]+sum2+t[k]<sum){
					ans=ans+sum2+t[k]+c[k]-sum;
					c[k]=0;
				}
			}	
		}
	}
	cout<<ans; 
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
