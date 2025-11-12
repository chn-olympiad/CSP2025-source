#include<bits/stdc++.h>
using namespace std;
long long p[500005],a[500005];
long long k;
int n;
struct point{
	int l,r;
};
vector<point>v;
bool cmp(point aa,point bb){
	if(aa.r==bb.r)return aa.l>bb.l;
	return aa.r<bb.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%lld",&n,&k);
	if(n<=1000){
		long long ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",a+i);
			p[i]=p[i-1] xor a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				long long q=0;
				for(int kk=i;kk<=j;kk++)q=(q xor a[kk]);
				if(q==k){
					point tag;
					tag.l=i,tag.r=j;
					v.push_back(tag);
				}
			}
		}
		int lv=v.size();
		int t=0;
		sort(v.begin(),v.end(),cmp);
		for(int i=0;i<lv;i++){
			
			if(v[i].l>t){
				ans++,t=v[i].r;
			}
		}
		printf("%lld",ans);
	}else if(k<=1){
		if(k==1){
			long long ans=0;
			for(int i=1;i<=n;i++){
				scanf("%lld",a+i);
				if(a[i]==1)ans++;
			}
			printf("%lld",ans);
		}else{
			long long ans=0;
			for(int i=1;i<=n;i++){
				scanf("%lld",a+i);
				if(a[i]==0)ans++;
			}
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i-1]==1){
					ans++,i+=1;
				}
			}
			printf("%lld",ans);
		}
	}else{
		long long ans=0,tag=1;
		for(int i=1;i<=n;i++){
			scanf("%lld",a+i);
			p[i]=(p[i-1] xor a[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j>=tag;j--){
				if((p[i] xor p[j-1])==k){
					ans++;
					tag=i+1;
				}
			}
		}
		printf("%lld",ans);
	}
	return 0;
}
