#include<bits/stdc++.h>
#define int long long
using namespace std;
bool isc[10005];
struct road{
	int x,y,c;
}r[50000000];
bool compare(const road& a,const road&b){
	return a.c < b.c;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int i,cm=0;
	for(i=0;i<m;i++){
		int u,v,c1;
		cin>>u>>v>>c1;
		r[i].x=u;
		r[i].y=v;
		r[i].c=c1;
		if(c1>cm) cm=c1;
	}
	for(int j=1;j<=k;j++){
		int C,a[10001];
		cin>>C;
		for(int l=1;l<=n;l++){
			cin>>a[l];
			if(cm<C||l==1) continue;
			for(int f=1;f<l;f++){
				if((a[f]+C+a[l])>cm) continue;//?
				i++;
				r[i].x=f;
				r[i].y=l;
				r[i].c=a[f]+C+a[l];
			}
		}
	}
	sort(r,r+i,compare);
	int res=0,cc=0;
	for(int j=1;j<=i;j++){
		if((!isc[r[j].x])||(!isc[r[j].y])){
			res+=r[j].c;
			cc++;
			isc[r[j].x]=isc[r[j].y]=true;
		}
		if(cc==n-1) break;
	}
	cout<<res;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
