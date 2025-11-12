#include<bits/stdc++.h>
using namespace std;
long long n,m,k,v[15][10005],f[1100005],ans=9e18,sxt,t,g;
int find(int i){
	if(i==f[i])return i;
	else return f[i]=find(f[i]);
}
struct p{
	int x,y,v;
};
vector<p> a;
bool com(p a,p b){
	return a.v<b.v;
}
void K(long long s,int t,int g){
	for(int i=1;i<=n+k;i++)f[i]=i;
	long long sum=s;
	stable_sort(a.begin(),a.end(),com);
	int i=0,j=0;
	while(j<g-1&&i<t){
		int x=find(a[i].x);
		int y=find(a[i].y);
		if(x!=y){
			f[x]=y;
			j++;
			sum+=a[i].v;
		}
		i++;
	}
	if(j==g-1)ans=min(ans,sum);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a.push_back({x,y,z});
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>v[i][j];
			if(v[i][j]>0)sxt=1;
		}
	}
	if(sxt==0){
		cout<<"0";
		return 0;
	}
	for(int i=0;i<(1<<k);i++){
		int x=i,j=0,s=0;
		g=n;
		t=m;
		while(x>0){
			j++;
			if(x&1){
				for(int q=1;q<=n;q++){
					a.push_back({q,j+m,v[j][q]});
				}
				g++;
				t+=n;
				s+=v[j][0];
			}
			x>>=1;
		}
		K(s,t,g);
	}
	cout<<ans;
	return 0;
}
