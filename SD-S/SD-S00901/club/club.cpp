#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> PII;
struct node{
	int id,mx,cz,mid;
}fa[100010],fb[100010],fc[100010];
//int 
bool cmp(node a,node b){
	return a.cz>b.cz;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	scanf("%lld",&t);
	while(t--){
		int n,ans=0;
		scanf("%lld",&n);
		int za=0,zb=0,zc=0;
		for(int i=1;i<=n;i++){
			int a,b,c;
			scanf("%lld%lld%lld",&a,&b,&c);
//			cin>>a>>b>>c;
			if(a>=b&&a>=c){
				ans+=a;
				fa[++za].id=i;
				fa[za].cz=min(a-b,a-c);
				fa[za].mx=a;
				fa[za].mid=1;
			}
			else if(b>=a&&b>=c){
				ans+=b;
				fb[++zb].id=i;
				fb[zb].cz=min(b-a,b-c);
				fb[zb].mx=b;
				fb[zb].mid=2;				
			}
			else if(c>=a&&c>=b){
				ans+=c;
				fc[++zc].id=i;
				fc[zc].cz=min(c-a,c-b);
				fc[zc].mx=c;
				fc[zc].mid=3;
			}

		}
		if(za>n/2){
			sort(fa+1,fa+za+1,cmp);
			for(int i=n/2+1;i<=za;i++){
				ans-=fa[i].cz;
			}
		}
		else if(zb>n/2){
			sort(fb+1,fb+zb+1,cmp);
			for(int i=n/2+1;i<=zb;i++){
				ans-=fb[i].cz;
			}
		}
		else if(zc>n/2){
			sort(fc+1,fc+zc+1,cmp);
			for(int i=n/2+1;i<=zc;i++){
				ans-=fc[i].cz;
			}
		}	
		printf("%lld\n",ans);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0





*/
