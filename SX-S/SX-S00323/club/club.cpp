#include<bits/stdc++.h>
using namespace std;
struct node{
	int k,to,v;
} tj[200005];
int t,n,a[100005],b[100005],c[100005];
bool cmp(node n1,node n2){
	return n1.v>n2.v;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		bool flag[3]={1,1,1};
		long long ans=0;
		int aa=0,bb=0,cc=0;
		vector<int> g[4];
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			int ma=max(a[i],max(b[i],c[i]));
			ans+=ma;
			if(a[i]==ma) aa++,g[1].push_back(i);
			else if(b[i]==ma) bb++,g[2].push_back(i);
			else cc++,g[3].push_back(i);
			if(b[i]!=0||c[i]!=0) flag[1]=false;
			if(c[i]!=0) flag[2]=false;
		}
		if(flag[1]){
			sort(a+1,a+1+n);
			for(int i=1;i<=n/2;i++) ans-=a[i];
			printf("%lld\n",ans);
			continue;
		}
		if(flag[2]){
			if(aa>n/2){
				aa-=n/2;
				for(int i=0;i<g[1].size();i++){
					c[i]=b[g[1][i]]-a[g[1][i]];
				}
				sort(c,c+g[1].size());
				reverse(c,c+g[1].size());
				for(int i=0;i<aa;i++) ans+=c[i];
			}else if(bb>n/2){
				bb-=n/2;
				for(int i=0;i<g[2].size();i++){
					c[i]=a[g[2][i]]-b[g[2][i]];
				}
				sort(c,c+g[2].size());
				reverse(c,c+g[2].size());
				for(int i=0;i<bb;i++) ans+=c[i];
			}
			printf("%lld\n",ans);
			continue;
		}
		if(aa>n/2){
			aa-=n/2;
			for(int i=0;i<g[1].size();i++){
				if(b[g[1][i]]>=c[g[1][i]]) tj[i]={g[1][i],2,b[g[1][i]]-a[g[1][i]]};
				else tj[i]={g[1][i],3,c[g[1][i]]-a[g[1][i]]};
			}
			sort(tj,tj+n,cmp);
			for(int i=0;i<aa;i++){
				ans+=tj[i].v;
				g[tj[i].to].push_back(tj[i].k);
			}
		}
		if(bb>n/2){
			bb-=n/2;
			for(int i=0;i<g[2].size();i++){
				if(a[g[2][i]]>=c[g[2][i]]&&a[g[2][i]]-b[g[2][i]]<0) tj[i]={g[2][i],1,a[g[2][i]]-b[g[2][i]]};
				else tj[i]={g[2][i],3,c[g[2][i]]-b[g[2][i]]};
			}
			sort(tj,tj+n,cmp);
			for(int i=0;i<bb;i++){
				ans+=tj[i].v;
				g[tj[i].to].push_back(tj[i].k);
			}
		}
		if(cc>n/2){
			cc-=n/2;
			for(int i=0;i<g[3].size();i++){
				if(a[g[3][i]]>=b[g[3][i]]&&a[g[3][i]]-c[g[3][i]]<0) tj[i]={g[3][i],1,a[g[3][i]]-c[g[3][i]]};
				else tj[i]={g[2][i],2,b[g[2][i]]-c[g[2][i]]};
			}
			sort(tj,tj+n,cmp);
			for(int i=0;i<cc;i++){
				ans+=tj[i].v;
				g[tj[i].to].push_back(tj[i].k);
			}
		}
		printf("%lld",ans);
	}
	return 0;
}
