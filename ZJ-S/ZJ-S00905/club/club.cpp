#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define lb lower_bound
struct ab{
	int a,b,c,m1,m2,m3,v1,v2,v3;
}d[100005];
bool cmp(ab x,ab y){
	if(x.m1==y.m1){
		if(x.m2==y.m2)return x.m3>=y.m3;
		return x.m2>y.m2;
	}
	return x.m1>y.m1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		vector<int>v[5];
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&d[i].a,&d[i].b,&d[i].c);
			if(d[i].a>=d[i].b){
				if(d[i].a>=d[i].c){
					d[i].m1=d[i].a;d[i].v1=1;
					if(d[i].c>=d[i].b)d[i].m2=d[i].c,d[i].m3=d[i].b,d[i].v2=3,d[i].v3=2;
					else d[i].m2=d[i].b,d[i].m3=d[i].c,d[i].v2=2,d[i].v3=3;
				}else{
					d[i].m1=d[i].c,d[i].v1=3;
					d[i].m2=d[i].a,d[i].m3=d[i].b;
					d[i].v2=1;d[i].v3=2;
				}
			}else{
				if(d[i].a>=d[i].c){
					d[i].m1=d[i].b;
					d[i].m2=d[i].a,d[i].m3=d[i].c;
					d[i].v1=2;d[i].v2=1;d[i].v3=3;
					
				}else{
					d[i].m3=d[i].a;d[i].v3=1;
					if(d[i].c>=d[i].b)d[i].m1=d[i].c,d[i].m2=d[i].b,d[i].v1=3,d[i].v2=2;
					else d[i].m1=d[i].b,d[i].m2=d[i].c,d[i].v1=2,d[i].v2=3;
				}
			}
			
		}
		sort(d+1,d+n+1,cmp);
		//for(int i=1;i<=n;i++)printf("%d %d %d %d %d %d\n",d[i].m1,d[i].m2,d[i].m3,d[i].v1,d[i].v2,d[i].v3);
		int t[5]={},e[100005]={};
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=d[i].m1;
			t[d[i].v1]++;
			v[d[i].v1].pb(i);
		}
		//printf("      %d",ans);
		for(int i=1;i<=3;i++){
			if(t[i]>n/2){
				for(int p=0;p<v[i].size();p++){
					int j=v[i][p];
					e[p]=d[j].m1-d[j].m2;
				}
				sort(e,e+v[i].size());
				//for(int j=0;j<v[i].size();j++)printf("  %d\n",e[j]);
				//printf("    %d\n",t[i]);
				for(int j=0;j<(t[i]-n/2);j++)ans-=e[j];
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
