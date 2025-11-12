#include<bits/stdc++.h>
#define push push_back
#define a first
#define b second
//rp++
using namespace std;
int n,m,k,x,y,z;
struct s{
	int x,y,z;
};
vector<s> v;
bool cmp(s a,s b){
	a.z<b.z;
}
int f[2000005];
int t[2000005];
bool p[2000005];
bool find(int x){
	if(f[x]==x)return x;
	else return f[x]=find(f[x]) ;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		v.push({x,y,z});
	}
	for(int i=1;i<=k;i++){
		cin>>t[i+m];
		for(int j=1;j<=n;j++){
			cin>>z;
			v.push({i+m,j,z});
		}
	}
	sort(v.begin(),v.end(),cmp);
	int h=0;
	for(int i=0;i<m+n*k;i++){
		int tx=find(v[i].x),ty=find(v[i].y);
		cout<<v[i].x<<' '<<v[i].y<<' '<<v[i].z<<'\n';
		if(tx!=ty){
			f[tx]=ty;
			h+=v[i].z;
			if(p[tx]!=1){
				p[tx]=1;
				h+=t[tx];
			}
			if(p[ty]!=1){
				p[ty]=1;
				h+=t[ty];
			}
		}
	}
	cout<<h;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
