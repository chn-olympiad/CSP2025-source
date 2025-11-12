#include<bits/stdc++.h>
#define II cout<<"------------\n";
using namespace std;
const int N=1e6+9;
int n,m,k,b[14][N],f[N],ok[14],qq[N],ans;
struct node{
	int u,v,w;
}a[N];
vector<node> q;
int root(int h){
	if(f[h]==h)return h;
	return f[h]=root(f[h]);
}

bool cmp(node a,node b){
	return a.w<b.w;
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=k;i++){
		cin>>b[i][0];
		for(int j=1;j<=n;j++)cin>>b[i][j];
	}
	for(int i=1;i<=m;i++){
		if(root(a[i].u)==root(a[i].v))continue;
		int u=a[i].u,v=a[i].v;
		int o=0;
		ans+=a[i].w;
		f[root(u)]=root(v);
		q.push_back(a[i]);
	}
	for(int i=0;i<q.size();i++){
		qq[q[i].u]++,qq[q[i].v]++;
	}
	for(int i=1;i<=1<<(k-1);i++){
		int o=0,sum=0,zz=i;
		
		while(zz){
			o++;
			if(zz&1){
				sum+=b[o][0];
				for(int j=0;j<q.size();j++){
						sum=sum-q[j].w+b[o][q[j].u]+b[o][q[j].v];	
					
				}
			}
			zz/=2;
		}
		cout<<sum<<" ";
		ans=min(ans,sum+ans);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

