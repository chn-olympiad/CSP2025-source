//SN-S00518 王者淳 西安辅轮中学
#include<bits/stdc++.h>
using namespace std;
int n,mm,k;
long long L=2e9;
long long ans,a[10001],b[10001];
vector<int>v[10001];
map<long long,int>m;
void Find(){
	queue<int>q;
	for(int i=1;i<=n;i++)a[i]=1e18;
	a[1]=0;
	q.push(1);
	while(!q.empty()){
		int p=q.front();q.pop();
		for(int i=0;i<v[p].size();i++){
			if(b[p]==v[p][i]||p==v[p][i])continue;
			if(a[v[p][i]]>m[p*L+v[p][i]]){
				if(a[v[p][i]]==1e18)ans+=m[p*L+v[p][i]];
				else ans-=a[v[p][i]]-m[p*L+v[p][i]];
				a[v[p][i]]=m[p*L+v[p][i]];b[v[p][i]]=p;
				q.push(v[p][i]);				
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>mm>>k;
	for(int i=1;i<=mm;i++){
		int u,vv,w;cin>>u>>vv>>w;
		v[u].push_back(vv);v[vv].push_back(u);
		m[u*L+vv]=m[vv*L+u]=w;
	}
	for(int i=1;i<=k;i++){
		int cc;cin>>cc;
		for(int j=1;j<=n;j++){
			int u;cin>>u;
			if(m[i*L+j])m[j*L+i]=m[i*L+j]=min(u,m[j*L+i]);
			else {
				v[i].push_back(j);v[j].push_back(i);
				m[i*L+j]=m[j*L+i]=u;	
			}
		}
	}
	Find();
	cout<<ans;
	return 0;
}
