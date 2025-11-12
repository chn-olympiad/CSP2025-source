#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int maxn=10020;
constexpr int maxm=1e5;

int fa[maxn+5];
int sze[maxn+5];
ll ans=0;

int fnd(int& x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=fnd(fa[x]);
}

bool merge(int x,int y){
	x=fnd(x),y=fnd(y);
	if(x==y){
		return 0;
	}
	if(sze[x]<sze[y]){
		sze[y]+=sze[x];
		fa[x]=y;
	}
	else{
		sze[x]+=sze[y];
		fa[y]=x;
	}	
	return 1;
}

struct edge{
	int u,v;
	ll w;
};

bool operator < (edge& a,edge& b){
	return a.w<b.w;
}

int n,m,k;

edge base_mst[maxn+5];
int bcnt=0;

edge Tmp[maxm+5];

ll c[15];
ll a[15][maxn+5];

edge ebase[1000005];

ll chk(edge& e){
	int tmp=merge(e.u,e.v);
	//if(tmp)
	//	cout<<"Check "<<e.second.first<<" "<<e.second.second<<":"<<e.first<<"\n";
	return tmp*e.w;
}

ll calc(int S){
//	cout<<S<<"\n";
	for(int i=1;i<=n+k;i++){
		sze[i]=1;
		fa[i]=i;
	}
	ll ret=0;
	int e1=1,e2=1;
	while(e1!=n||e2!=n*k+1){
	//	cout<<e1<<" "<<e2<<" "<<n<<" "<<k<<"\n";
		while(e2!=n*k+1&&(S&(1<<(Tmp[e2].u-n-1)))==0){
			e2++;
		}
		if(e1==n&&e2==n*k+1){
			break;
		}
		if(e2==n*k+1){
			ret+=chk(base_mst[e1]);
			e1++;
		}
		else if(e1==n){
			ret+=chk(Tmp[e2]);
			e2++;
		}
		else{
			if(base_mst[e1]<Tmp[e2]){
				ret+=chk(base_mst[e1]);
				e1++;
			}
			else{
				ret+=chk(Tmp[e2]);
				e2++;
			}
		}
	}
//	cout<<ret<<"\n";
	for(int j=1;j<=k;j++){
		ret+=c[j]*((S&(1<<(j-1)))!=0);
	}
//	cout<<ret<<"\n";
	return ret;
}

constexpr int B=65536;

int cnt[B+5];
edge Tmpsort[1000005];

void Sort(){
	for(int i=1;i<=m;i++){
		cnt[ebase[i].w%B]++;
	}
	for(int i=1;i<B;i++){
		cnt[i]+=cnt[i-1];
	}
	for(int i=m;i>=1;i--){
		Tmpsort[cnt[ebase[i].w%B]--]=ebase[i];
	}
	for(int i=0;i<=B;i++){
		cnt[i]=0;
	}
	for(int i=1;i<=m;i++){
		cnt[(ebase[i].w/B)%B]++;
	}
	for(int i=1;i<=B;i++){
		cnt[i]+=cnt[i-1];
	}
	for(int i=m;i>=1;i--){
		ebase[cnt[(Tmpsort[i].w/B)%B]--]=Tmpsort[i];
	}
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>ebase[i].u>>ebase[i].v>>ebase[i].w;
	}
	Sort();
	for(int i=1;i<=n;i++){
		fa[i]=i;
		sze[i]=1;
	}
	for(int i=1;i<=m;i++){
		if(merge(ebase[i].u,ebase[i].v)){
			base_mst[++bcnt]=ebase[i];
			ans+=ebase[i].w;
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			Tmp[(i-1)*n+j]=edge({i+n,j,a[i][j]});
		}
	}
	sort(Tmp+1,Tmp+n*k+1);
	for(int i=0;i<(1<<k);i++){
		ans=min(ans,calc(i));
	}
	cout<<ans;
}

