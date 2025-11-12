#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=1e6+5;
struct node{
	ll x,y,z,ben;
}t[N];
ll n,m,k,x,y,z,s[15],ans,cnt,sum,f[N],vis[15],ind[N],bc[N];
bool cmp(node a,node b){
	if(a.z==b.z) return a.ben<b.ben;
	return a.z<b.z;
}
ll find(ll x){
	if(x!=f[x]) f[x]=find(f[x]);
	return f[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>t[i].x>>t[i].y>>t[i].z;
	for(int i=1;i<=k;i++){
		cin>>s[i];
		for(int j=1;j<=n;j++){
			cin>>z;
			t[m+(i-1)*n+j].x=n+1;
			t[m+(i-1)*n+j].y=j;
			t[m+(i-1)*n+j].z=z;
			t[m+(i-1)*n+j].ben=s[i];
		}
	}
	sort(t+1,t+m+k*n+1,cmp);
	for(int i=1;i<=n+k;i++)
		f[i]=i;
	for(int i=1;i<=m+n*k;i++){
		ll rx=find(t[i].x);
		ll ry=find(t[i].y);
		if(rx==ry) continue;
		if(t[i].x>n&&!vis[t[i].x-n]) sum+=s[t[i].x-n],vis[t[i].x-n]=1;
		sum+=t[i].z;
		bc[t[i].x]+=t[i].z;
		bc[t[i].y]+=t[i].z;
		cnt++;
		ind[t[i].x]++,ind[t[i].y]++;
		if(cnt==n+k-1)
			break;
		f[rx]=ry;
	}
	for(int i=n;i<=n+k;i++)
		if(ind[i]==1) 
			sum=sum-s[i-n]-bc[i];
	cout<<sum;
	return 0;
}