#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;

int ans,t,n,a[maxn],b[maxn],c[maxn],d[maxn];
int aa,bb,cc;

int cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			aa=max(aa,a[i]),bb=max(bb,b[i]),cc=max(cc,c[i]);
		}
		if((aa==0&&bb==0)||(cc==0&&bb==0)||(aa==0&&cc==0)){
			for(int i=1;i<=n;++i){
				d[i]=max({a[i],b[i],c[i]});
			}
			sort(d+1,d+n+1,cmp);
			for(int i=1;i<=n/2;++i){
				ans+=d[i];
			}
		}else{
			for(int i=1;i<=n;++i){
				ans+=max({a[i],b[i],c[i]});
			}
		}
		cout<<ans<<"\n";
		ans=aa=bb=cc=0;
	}
	return 0;
}