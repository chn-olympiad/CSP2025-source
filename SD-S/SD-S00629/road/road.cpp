#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define up(i,j,k,l) for(int i=j;i<=k;i+=l)
#define down(i,j,k,l) for(int i=j;i>=k;i-=l)
using namespace std;
const int N=1e4+10,M=1e6+10,K=1e1+10;
const ll INF=1e18;
int n,m,k;
struct node{
	int u,v,w;
};
node a[10*N+M];
struct kc{
	int k,w[N];
};
kc xf[K];
struct dsu{
	int ft[N+K];
	void init(int num)
	{
		up(i,1,num,1){
			ft[i]=i;
		}
		return;
	}
	int fd(int x)
	{
		if(ft[x]==x){
			return x;
		}
		else{
			return ft[x]=fd(ft[x]);
		}
	}
	void mg(int x,int y)
	{
		ft[fd(x)]=fd(y);
		return;
	}
	bool check(int x,int y)
	{
		return fd(x)==fd(y);
	}
};
dsu b;
vector<int> lt;
ll ans;
bool cmp(node x1,node x2)
{
	return x1.w<x2.w;
}
void check()
{
	int g=n+(int)lt.size();
	b.init(g);
	int bs=m;
	ll res=0;
	up(i,0,(int)lt.size()-1,1){
		res+=xf[i+1].k;
		up(j,1,n,1){
			a[++bs]={i+1+n,j,xf[i+1].w[j]};
		}
	}
	if(res>=ans){
		return;
	}
	sort(a+1,a+bs+1,cmp);
	int ct=0;
	up(i,1,bs,1){
		//cout<<a[i].u<<' '<<a[i].v<<endl;
		if(b.check(a[i].u,a[i].v)==false){
			b.mg(a[i].u,a[i].v);
			res+=a[i].w;
			//cout<<"++"<<a[i].w<<endl;
			ct++;
			if(res>=ans){
				return;
			}
		}
		if(ct==g-1){
			break;
		}
	}
	//cout<<g<<' '<<bs<<' '<<res<<endl;
	ans=min(ans,res);
	return;
}
void solve()
{
	cin>>n>>m>>k;
	up(i,1,m,1){
		cin>>a[i].u>>a[i].v>>a[i].w;
	} 
	up(i,1,k,1){
		cin>>xf[i].k;
		up(j,1,n,1){
			cin>>xf[i].w[j];
		}
	}
	ans=INF;
	for(int i=0;i<(1<<k);i++){
		lt.clear();
		for(int j=0;j<k;j++){
			if(((i>>j)&1)==1){
				lt.push_back(j+1);
			}
		}
		check();
	}
	cout<<ans;
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int _=1;
	//cin>>_;
	up(i,1,_,1){
		solve();
	}
	return 0;
}

