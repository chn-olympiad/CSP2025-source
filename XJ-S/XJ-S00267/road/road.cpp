#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int M=1e4+5;
long long int a[15][M],c[M];
int cvis[M];
int n,m,k;
int vis[N];
struct no{
	long long int u,v,w;
}s[N];
bool cmp(no x,no y){
	if(x.w<y.w)return true;
	return false;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>s[i].u>>s[i].v>>s[i].w;
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	int ans=0,num=0;
	sort(s+0,s+m,cmp);
	for(int i=0;i<m;i++){
		if(vis[s[i].v]<1||vis[s[i].u]<1){
			for(int j=0,o=0;j<k;j++){
				if(c[j]<s[i].w){
					o=a[j][s[i].v]+a[j][s[i].u];
					if(cvis[j]==0){
						o+=c[j];
					}
					if(o<=s[i].w){
						ans+=o;
						num++;
						cvis[j]=1;
						vis[s[i].v]++;
						vis[s[i].u]++;
					}else{
						ans+=s[i].w;
						num++;
						vis[s[i].v]++;
						vis[s[i].u]++;
					}
					o=0;
				}
			}
		}
	}
	int f=0,fv=0;
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			f++;
		}
		fv+=vis[i];
	}
	cout<<abs(ans);
	return 0;
}

