#include<bits/stdc++.h>
using namespace std;
#define LL long long
int T,n,a[100005],b[100005],c[100005];
LL ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		a[0]=b[0]=c[0]=1;
		ans=0;
		for(int i=1;i<=n;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			if(u>=max(v,w)){
				ans+=u;
				a[a[0]]=u-max(w,v);
				a[0]++;
			}else if(v>=w){
				ans+=v;
			    b[b[0]]=v-max(u,w);
				b[0]++;
			}else{
				ans+=w;
				c[c[0]]=w-max(u,v);
				c[0]++;
			}
		}
		if(a[0]>n/2+1){
			sort(a+1,a+a[0]);
			int sum=a[0]-n/2-1;
			for(int i=1;i<=sum;i++){
				ans-=a[i];
			}
		}else if(b[0]>n/2+1){
			sort(b+1,b+b[0]);
			int sum=b[0]-n/2-1;
			for(int i=1;i<=sum;i++){
				ans-=b[i];
			}
		}else if(c[0]>n/2+1){
			sort(c+1,c+c[0]);
			int sum=c[0]-n/2-1;
			for(int i=1;i<=sum;i++){
				ans-=c[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
