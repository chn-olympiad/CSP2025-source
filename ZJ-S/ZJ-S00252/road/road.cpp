#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,v,w,c[101],mp[200001],ans,u,cnt=1,out,z[101],num;
bool b[200001],ff=0;
int book[101];
struct node{
	int v,w,fa;
	operator < (const node&r)const{
		return w>r.w;
	}
}x;
vector<node>a[200001];
priority_queue<node>q;
inline int kru(int ii){
	for(;!q.empty();){
		x=q.top();
		q.pop();
		if(b[x.v]==1)continue;
		b[x.v]=1;
		ans+=x.w;
		if(x.v<=n)cnt++;
		if(cnt==n)break;
		for(int j=0;j<(int)a[x.v].size();j++){
			num++;
			node i=a[x.v][j];
			if(b[i.v]==1)continue;
			if(i.v>n){
				if(book[i.v-n]==0)continue;
			}
			q.push({i.v,i.w,x.v});
		}
	}
	return 0;
}
inline int ksm(int a,int b){
	int ans=1;
	for(;b;){
		if(b&1)ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(NULL),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int kk=ksm(2,k);
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u].push_back({v,w,0});
		a[v].push_back({u,w,0});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		mp[n+i]=i;
		for(int j=1;j<=n;j++){
			cin>>w;
			a[j].push_back({n+i,w,i});
			a[n+i].push_back({j,w,i});
		}
	}
	out=1e18;
	srand(time(NULL));
	for(int ii=0;ii<kk;ii++){
		for(int i=1;i<=n+k;i++){
			b[i]=0;
		}
		ans=0;
		//int num=0;
		bool fl=0;
		for(int i=1;i<=k;i++){
			book[i]=0;
			if(((1<<(i-1))&ii)){
				ans+=c[i];
				book[i]=1;
				num++;
			}
			else{
				if(c[i]==0){
					fl=1;
					break;
				}
				book[i]=0;
			}
		}
		if(fl){
			ff=1;
			continue;
		}
		b[1]=1;
		cnt=1;
		for(;!q.empty();)q.pop();
		for(int j=0;j<(int)a[1].size();j++){
			node i=a[1][j];
			if(i.v>n){
				if((book[i.v-n])==0)continue;
			}
			q.push({i.v,i.w,1});
		}
		kru(ii);
		out=min(out,ans);
		if(num>2001740&&ff==0)break;
	}
	cout<<out;
	return 0;
} 
