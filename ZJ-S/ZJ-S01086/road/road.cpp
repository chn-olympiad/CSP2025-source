#include<bits/stdc++.h>
using namespace std;
int a[10010][10010];
bool F[10010][10010],FF;
vector<long long> v[10010];
long long b[20][10010],sum,n,m,k,x,y,z,c[20],mins,f[11010],t,T,bk[20];
void join(int i,int j){
	int h=1;
	while(h||f[i]!=i){
		h=0;
		int tt=f[i];
		f[i]=f[j];
		i=tt;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("road3.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(a,63,sizeof a);
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		if(!F[x][y]){
			v[x].push_back(y);
			v[y].push_back(x);
			F[x][y]=F[y][x]=1;
		}
		a[x][y]=min(a[x][y],(int)z);
		a[y][x]=min(a[x][y],(int)z);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>b[i][j];
		if(c[i]!=0) FF=1;
	}
//	if(!FF){
//		for(int i=1;i<=n;i++){
//			mins=INT_MAX;
//			for(int j=1;j<=k;j++) mins=min(mins,b[j][i]);
//			for(int j=0;j<v[i].size();j++) mins=min(mins,(long long)a[v[i][j]][i]);
//			sum+=mins;
//		}
//		cout<<sum;
//		return 0;
//	}
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=n;i++){
		mins=INT_MAX;
		t=0;T=0;
		for(int j=0;j<v[i].size();j++){
			t=v[i][j];
			if(f[i]==f[t]) continue;
			mins=min(mins,(long long)a[t][i]);
		}
		for(int j=1;j<=k;j++){
			if(f[j+n]==f[i]) continue;
			if(!bk[j]){
				if(mins>c[j]+b[j][i]){
					T=j;
					mins=c[j]+b[j][i];
				}
			}
			else mins=min(mins,b[j][i]);
		}
		for(int j=0;j<v[i].size();j++){
			t=v[i][j];
			if(f[i]==f[t]) continue;
			if(mins==a[t][i]) join(f[i],f[t]);
		}
		for(int j=1;j<=k;j++){
			if(f[j+n]==f[i]) continue;
			if(!bk[j]){
				if(mins==c[j]+b[j][i]){
					bk[T]=1;
					join(f[i],f[j+n]);
				}
			}
			else if(mins==b[j][i]) join(f[i],f[j+n]);
		}
		sum+=mins;
	}
	cout<<sum;
	return 0;
}