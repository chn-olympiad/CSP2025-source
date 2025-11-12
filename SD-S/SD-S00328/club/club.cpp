#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define pr pair<int,int>
#define mk(a,b) make_pair(a,b)

const int N=1e5+5,M=3005,inf=1e18;

struct data{
	int w[4],id;
}a[N];
int n,tot[4],f1[N],f2[N];


struct dt{ int id,k; }b[4];
struct dtt{ int k1,k2,id; }c[4][N];

int cmp(dt q,dt h){ return q.k>h.k; }
int cmp2(dtt q,dtt h){
//	if(q.k1-q.k2==h.k1-h.k2) return q.k2>h.k2;
//	else return q.k1-q.k2<h.k1-h.k2;
	return q.k1-q.k2<h.k1-h.k2;
}

pr gmax(data x){
	int w1=x.w[1],w2=x.w[2],w3=x.w[3];
	b[1]={1,w1}; b[2]={2,w2}; b[3]={3,w3};
	sort(b+1,b+4,cmp);
	return mk(b[1].id,b[2].id);
}

void solve(){
	tot[1]=tot[2]=tot[3]=0;
	cin>>n;
	int m=n/2,fl=0,pos=0,ans=0;
	for(int i=1;i<=n;i++) cin>>a[i].w[1]>>a[i].w[2]>>a[i].w[3];
	for(int i=1;i<=n;i++){
		pr num=gmax(a[i]);
		f1[i]=num.first;
		f2[i]=num.second;
		c[f1[i]][++tot[f1[i]]]={a[i].w[f1[i]],a[i].w[f2[i]],i}; ans+=a[i].w[f1[i]];
		if(tot[f1[i]]>m) fl=1,pos=f1[i];
	}
	if(!fl){
		cout<<ans<<endl;
		return ;
	}
	sort(c[pos]+1,c[pos]+tot[pos]+1,cmp2);
	for(int i=1;i<=tot[pos]-m;i++){
		ans-=c[pos][i].k1; ans+=c[pos][i].k2;
	}cout<<ans<<endl;
	return ;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int _T; cin>>_T;
	while(_T--) solve();
	return 0;
}
