#include<bits/stdc++.h>
using namespace std;
struct edge{
	long long fro,to,len,cl;
};
bool operator<(edge x,edge y){
	return x.len<y.len;
}
long long n,m,k,num=1e18,cinx,ciny,cinz,c[15],f[11000];
bool b[15];
vector<edge>E;
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	b[0]=true;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>cinx>>ciny>>cinz;
		E.push_back(edge{cinx,ciny,cinz,0});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>cinx;
			E.push_back(edge{n+i,j,cinx,i});
		}
	}
	sort(E.begin(),E.end());
	for(int i=0;i<(1<<k);i++){
		long long Ans=0,cnt=0;
		for(int j=1;j<=k;j++){
		    b[j]=(1<<j-1)&i;
		    if(b[j])Ans+=c[j],cnt++;
		}
		for(int j=1;j<=n+k;j++)
		    f[j]=j;
		for(int j=1,k=0;j<n+cnt;k++){
			if(find(E[k].fro)==find(E[k].to)||!b[E[k].cl])
			    continue;
			f[find(E[k].fro)]=find(E[k].to);
			Ans+=E[k].len;j++;
		}
		num=min(num,Ans);
	}
	cout<<num;
	return 0;
}
