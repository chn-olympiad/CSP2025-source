#include<bits/stdc++.h>
using namespace std;
int t,n,f[5],k,ps,pf;
long long ans;
template<typename T> void read(T &x){
	x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
}
struct pl{
	int v,p;
	bool operator<(pl x){
		return v>x.v;
	}
}d[100005][5],l[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(t);
	while(t--){
		read(n);
		k=ans=0;
		f[1]=f[2]=f[3]=0;
		for(int i=1;i<=n;i++){
			read(d[i][1].v),read(d[i][2].v),read(d[i][3].v);
			d[i][1].p=1,d[i][2].p=2,d[i][3].p=3;
			sort(d[i]+1,d[i]+1+3);
			l[i].v=d[i][1].v-d[i][2].v;
			l[i].p=i;
		}
		sort(l+1,l+1+n);
		for(int i=1;i<=n;i++){
			ps=l[i].p;
			pf=d[ps][1].p;
			if(f[pf]<n/2){
				f[pf]++;
				ans+=d[ps][1].v;
			}else{
				l[++k].v=d[ps][2].v-d[ps][3].v;
				l[k].p=ps;
			}
		}
		sort(l+1,l+1+k);
		for(int i=1;i<=k;i++){
			ps=l[i].p;
			pf=d[ps][2].p;
			if(f[pf]<n/2){
				f[pf]++;
				ans+=d[ps][2].v;
			}else{
				ans+=d[ps][3].v;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}