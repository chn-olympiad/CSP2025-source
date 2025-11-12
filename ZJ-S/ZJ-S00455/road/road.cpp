#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1066666;
int n,m,k,i,j,qi[N],zh[N],wi[N],fl,c[66],cs[66],a[26][16666],f[16666],mi=LONG_LONG_MAX;
struct no{
	int x,y,p;
}rd[N];
bool cmp(no q,no h){
	return q.p<h.p;
}
int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
int kl(){
	int i,j,ans=0,sum=0,cnt=0,t=0,w=n,sx,sy,fx,fy,jia;
	for(i=1;i<=n+k;i++) f[i]=i;
	for(i=1;i<=k;i++)
		if(cs[i]==1){
			ans+=c[i];w++;
			for(j=1;j<=n;j++)
				rd[++cnt].x=n+i,rd[cnt].y=j,rd[cnt].p=a[i][j];
		}
	for(i=1;i<=m;i++)
		rd[++cnt].x=qi[i],rd[cnt].y=zh[i],rd[cnt].p=wi[i];
	sort(rd+1,rd+1+cnt,cmp);
	while(t<=cnt){
		t++;
		sx=rd[t].x;sy=rd[t].y;jia=rd[t].p;
		fx=find(sx),fy=find(sy);
		if(fx!=fy){
			sum++;
			ans+=jia;
			f[fx]=fy;
		}
		if(sum==w) break;
	}
	return ans;
}
void sc(int t){
	if(t>k){
		mi=min(mi,kl());
		return ;
	}
	if(cs[t]==2){
		cs[t]=1;
		sc(t+1);
	}
	else{
		cs[t]=1;
		sc(t+1);
		cs[t]=0;
		sc(t+1);
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++) cin>>qi[i]>>zh[i]>>wi[i];
	for(i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]==0) cs[i]=2;
		for(j=1;j<=n;j++)
			cin>>a[i][j];
	}
	sc(1);
	cout<<mi;
	return 0;
}

