#include<iostream>
#include<algorithm>
using namespace std;
struct p1{
	long long x,y,z;
}r[1000006];
long long s[15],t[15][1000006];
bool sel[15][1000006],ch[15];
bool cmp(p1 xx,p1 yy){
	return xx.z<yy.z;
}
int p[1000006];
int find(int x){
	if(x!=p[x]) p[x]=find(p[x]);
	return p[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		r[i].x=a;
		r[i].y=b;
		r[i].z=c;
	}
	for(int i=1;i<=k;i++){
		cin>>s[i];
		for(int j=1;j<=n;j++){
			cin>>t[i][j];
		}
	}
	sort(r+1,r+1+m,cmp);
	for(int i=1;i<=n;i++) p[i]=i;
	long long ans=0;
	for(int i=1;i<=m;i++){
		if(p[find(r[i].x)]!=p[find(r[i].y)]){
			long long mn=1e18,id=0;
			for(int j=1;j<=k;j++){
				long long sum=0;
				if(sel[j][r[i].x]==0) sum+=t[j][r[i].x];
				if(sel[j][r[i].y]==0) sum+=t[j][r[i].y];
				if(ch[j]==0) sum+=s[j];
				if(sum<mn) mn=sum,id=j;
			}
			if(mn<r[i].z){
				if(sel[id][r[i].x]==0) sel[id][r[i].x]=1,ans+=t[id][r[i].x];
				if(sel[id][r[i].y]==0) sel[id][r[i].y]=1,ans+=t[id][r[i].y];
				if(ch[id]==0) ans+=s[id],ch[id]=1;
			}else ans+=r[i].z;
			p[find(r[i].x)]=p[find(r[i].y)];
		}
	}
	cout<<ans;
	return 0;
}

/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
