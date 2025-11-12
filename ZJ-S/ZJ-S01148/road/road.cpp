#include<bits/stdc++.h>
using namespace std;
int n,m,k,l,c[100005],w[15][100005],ans;
vector<pair<int,int> > G[100005];
int f[100005];
int father(int x){
//	cout<<u<<endl;
	if(x!=f[x]) father(f[x]);
	else return f[x];
}
struct wzh{
	int u,g,z;
}a[100005];
int cmp(wzh h,wzh q){
	return h.z<q.z;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,g,z;i<=m;i++){
		cin>>a[i].u>>a[i].g>>a[i].z;
	}
	l=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) l=1;
		for(int j=1;j<=n;j++){
			cin>>w[i][j];
			if(w[i][j]!=0) l=1;
		}
	}
	if(l==0&&k!=0){
		cout<<0;
		return 0;
	}
	sort(a+1,a+1+m,cmp);
	if(k==0){
		for(int i=1;i<=n;i++) f[i]=i;
		for(int i=1;i<=m;i++){
			if(father(a[i].u)!=father(a[i].g)){
				ans+=a[i].z;
				int l=father(a[i].u);
				int r=father(a[i].g);
				f[r]=l;
			}
		}
		cout<<ans;
		return 0;
	}
}
