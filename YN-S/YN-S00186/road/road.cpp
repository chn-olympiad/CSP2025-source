#include<bits/stdc++.h>
#define NN 10010
#define NM 1000010
#define LL long long
using namespace std;
int fa[NN+10];
struct Rd{
	int u;int v;LL w;
}es[NM],ks[15][NN];
LL c[15],ans=0;
bool Ena[15];//是否启用
vector<Rd> ct,rt;
bool cmp(Rd r1,Rd r2){
	if(r1.w==r2.w){
		if(r1.u==r2.u)return r1.v<r2.v;
		return r1.u<r2.u;
	}
	return r1.w<r2.w;
}
void InitF(int n,int t){
	for(int i=1;i<=n+t;i++)fa[i]=i;
}
int find(int x){
	if(x==fa[x])return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
int n,m,k,ds=0;
void Kruskal(){//原汁原味MST
	InitF(n,0);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(find(es[i].u)!=find(es[i].v)){
			fa[find(es[i].u)]=find(es[i].v);
			ans+=es[i].w;
			cnt++;
			ct.push_back(es[i]);
		}
		if(cnt==n-1)break;
	}
}
int tn[15];
LL Kruskal_K(int t){
	memset(tn,0,sizeof(tn));
	InitF(n,t);
	ct.clear();
	LL ss=0;
	int cntk=0;
	for(int i=0,j=0;i<rt.size()&&j<n;){
		Rd e;
		if(ks[t][j].w <= rt[i].w){
			e=ks[t][j];
			j++;
		}
		else{
			e=rt[i];
			i++;
		}
		if(find(e.u)!=find(e.v)){
			fa[find(e.u)]=find(e.v);
			ss+=e.w;
			cntk++;
			ct.push_back(e);
			if(e.u>n){
				tn[e.u-n]=1;
			}
		}
		if(cntk==n+ds)break;
	}
	ss+=c[t];
	for(int i=1;i<=k;i++)if(Ena[i] && tn[i])ss+=c[i];
	return ss;
}
void copy(){
	rt.clear();rt.resize(ct.size());
	for(int i=0;i<ct.size();i++)rt[i]=ct[i];
}
LL Kruskal_T(int t){
	//cout<<t<<endl;
	int cn=__builtin_popcount(t);
	InitF(n,k);
	LL ss=0;
	int cntk=0,is=0;
	int ts[16]={};
	while(cntk!=n+cn-1){
		//cout<<cntk<<endl;
		Rd e;e.w=1e18;int ps=0;
		if(is<m)e=es[is];
		for(int i=1;i<=k;i++){
			if(t&(1<<(i-1))){
				if(ks[i][ts[i]].w<=e.w)e=ks[i][ts[i]],ps=i;
			}
		}
		if(ps==0)is++;
		else ts[ps]++;
		if(find(e.u)!=find(e.v)){
			fa[find(e.u)]=find(e.v);
			ss+=e.w;
			cntk++;
		}
	}
	for(int i=1;i<=k;i++)if(t&(1<<(i-1)))ss+=c[i];
	return ss;
}
void Work1(){
	for(int i=1;i<=k;i++)sort(ks[i],ks[i]+n,cmp);
	sort(es+1,es+m+1,cmp);
	LL anss=1e18;
	for(int i=0;i<(1<<k);i++)anss=min(anss,Kruskal_T(i));
	cout<<anss<<endl;	
}
void WorkFake(){
	for(int i=1;i<=k;i++)sort(ks[i],ks[i]+n,cmp);
	sort(es+1,es+m+1,cmp);
	Kruskal();copy();
	for(int i=1;i<=k;i++){//处理ki
		LL ans_n = Kruskal_K(i);
		if(ans_n<=ans){
			ans=ans_n;
			copy();
			Ena[i]=1;
			ds++;
			for(int i=1;i<=k;i++)if(Ena[i] && !tn[i])Ena[i]=0;
		}
	}
	cout<<ans<<endl;
}
void Work2(){
	for(int i=1;i<=k;i++)sort(ks[i],ks[i]+n,cmp);
	sort(es+1,es+m+1,cmp);
	cout<<Kruskal_T((1<<k)-1)<<endl;
}
int main(){
	LL cc=0;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>es[i].u>>es[i].v>>es[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];cc+=c[i];
		for(int j=1,x;j<=n;j++)cin>>x,ks[i][j-1] = {n+i,j,x};
	}
	if(k<=5){
		Work1();
	}
	else if(cc==0){
		Work2();
	}
	else if(n<=1000)Work1();
	else WorkFake();
	fclose(stdin);
	fclose(stdout);
}