#include<bits/stdc++.h>
using namespace std;
int i,j,l,ans,n,k,now,p;
//int yh[500005],a[500005];
map<int,int>yh,a;
struct z{
	int h,t;
} d[500005];
bool cmp(z x,z y){
	if(x.t==y.t) return x.h>y.h;
	else return x.t<y.t;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		yh[i]=yh[i-1] xor a[i];
	}for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			now=yh[j] xor yh[i-1];
			if(!(now xor k)){
				p++;
				d[p].h=i;
				d[p].t=j;
			}
		}
	}
	sort(d+1,d+p+1,cmp);
	l=d[1].t;
	ans=1;
	for(i=2;i<=p;i++){
		if(l<d[i].h){
			ans++;
			l=d[i].t;
		}
	}printf("%d",ans);
	return 0;
}


