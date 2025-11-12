/*
5 7 0
1 2 1
1 4 3
2 4 1
2 3 5
2 5 10
4 5 9
3 5 3

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct{
	int next,to,v;
}e[3000006];
int n,m,cnt,h[10006],v[10006],k,t=1,s[10006],ans,c[66],a[66][10006],ss=-1;
int r[66],ne[300006],rr[300006],rrr;
void ad(int x,int y,int z){
	++cnt;
	e[cnt].to=y;
	e[cnt].v=z;
	e[cnt].next=h[x];
	h[x]=cnt;
}
int f(){
	v[1]=1,s[1]=1,ans=0,t=1;
	while(t!=n){
		int b=-1,q;
		for(int i=1;i<=t;++i){
			for(int j=h[s[i]];j;j=e[j].next){
				int p=e[j].to;
				if(!v[p]){
					if(b==-1||b>e[j].v){
						q=p;
						b=e[j].v;
					}
				}
			}
		}
		s[++t]=q;
		v[q]=1;
		ans+=b;
	}
	for(int i=1;i<=n;++i){
		v[i]=0;
	}
	return ans;
}
void dfs(int tmp){
	if(tmp==k){
		for(int i=1;i<=k;++i){
			if(r[i]){
				for(int j=1;j<=n;++j){
					ad(i,j,a[i][j]);
					ad(j,i,a[i][j]);
					int xx=f();
					if(xx<ss||ss==-1){
						ss=xx;
//						for(int i=1;i<=n;++i){
//			for(int j=h[i];j;j=e[j].next){
//				int p=e[j].to;
//				cout<<i<<' '<<p<<' '<<e[j].v<<endl;
//			}
//		}
//						for(int i=1;i<=n;++i)
//							cout<<r[i]<<' ';
//						cout<<endl;					
					}
					for(int ii=1;ii<=n;++ii){
						h[ii]=rr[ii];
					}
					for(int i=rrr;i<=cnt;++i){
						e[i].next=0;
						e[i].to=0;
						e[i].v=0;
					}
					cnt=rrr;

				}
			}
		}
		return;
	}
	r[tmp]=1;
	dfs(tmp+1);
	r[tmp]=0;
	dfs(tmp+1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int x,y,z;
		cin>>x>>y>>z;
		ad(x,y,z);
		ad(y,x,z);
	}
	rrr=cnt;
	if(k==0){
		cout<<f();
		return 0;
	}
	for(int i=1;i<=n;++i)
		rr[i]=h[i];
	int fl=1;
	for(int i=1;i<=k;++i){
		cin>>c[i];
		if(c[i]!=0)
			fl=0;
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
			if(a[i][j]!=0)
				fl=0;
		}
	}
	if(fl){
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ss;
	return 0;
}

