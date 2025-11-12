#include<bits/stdc++.h>
using namespace std;
int lj[10011][10011];
bool yl[10011][10011];
int cty[11][10011];
struct lu{
	int x;
	int y;
	int v;
};
bool cmp(lu a,lu b){
	return a.v<b.v;
}
int f[10011];
int fid(int x){
	return (f[x]==x?x:f[x]=fid(f[x]));
}
lu l[1000011];
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,w;
		cin>>a>>b>>w;
		int f=min(a,b);
		int s=max(a,b);
		l[i].x=f;l[i].y=s;l[i].v=w;
		yl[f][s]=1;yl[s][f]=1;
		lj[f][s]=w;lj[s][f]=w;
	}int mi1=INT_MAX,mi2=INT_MAX;
	for(int i=1;i<=k;i++){
		cin>>cty[i][0];
		for(int j=1;j<=n;j++){
			cin>>cty[i][j];
		}
	}for(int i=1;i<=n;i++){
		f[i]=i;
	}
	sort(l+1,l+m+1,cmp);
	int c=1;
	long long ans=0;
	for(int i=1;i<=m;i++){
		if(c==n-1){
			break;
		}
		int bx=l[i].x,by=l[i].y;
		while(fid(bx)==fid(by)&&i+1<=m){
			i++;
		}
		ans+=l[i].v;
		f[fid(bx)]=f[fid(by)];
		c++;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==i){
			for(int j=1;j<=k;j++){
				for(int q=1;q<=n;q++){
					if(cty[j][q]<mi1&&q!=i){
						mi1=cty[j][q];
					}
				}
				if(mi1+cty[j][i]+cty[j][0]<mi2){
					mi2=mi1+cty[j][i]+cty[j][0];
				}
			} 
			ans+=mi2;
			break;
		}
	}
	cout<<ans;
	return 0;
}
