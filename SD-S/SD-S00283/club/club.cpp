#include<bits/stdc++.h>
#define int long long
#define gcd __gcd

using namespace std;
const int N=1e5+5;
struct node{
	int a,b,c;
}x[N];
bool cmp(node x,node y){
	int dax=max(x.a,max(x.b,x.c));
	int day=max(y.a,max(y.b,y.c));
	return dax>day;
}
bool cmp1(node a,node b){
	if(a.a==b.a){
		if(a.b==b.b) return a.c>b.c;
		return b.b>b.b;
	}return a.a>b.a;
}
int r1=0,r2=0,r3=0;
void clear(int n){
	for(int i=1;i<=n;i++)
	x[i].a=x[i].b=x[i].c=0;
//	memset(f,0,sizeof(f));
	r1=r2=r3=0;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int T; cin>>T;
	while(T--){
		int n; cin>>n;
		for(int i=1;i<=n;i++)
		cin>>x[i].a>>x[i].b>>x[i].c;
		if(n==2){
			int ans=max(x[1].a+x[2].b,x[1].a+x[2].c);
			ans=max(ans,x[1].b+x[2].c);
			ans=max(x[1].b+x[2].a,ans);
			ans=max(x[1].c+x[2].a,ans);
			ans=max(x[1].c+x[2].b,ans);
			cout<<ans<<'\n';
			continue;
		}
		int zui=n/2;sort(x+1,x+n+1,cmp);
		int ans=0;
		bool lp=0;for(int i=1;i<=n;i++){if(x[i].b!=0||x[i].c!=0){lp=1;break;}}if(!lp){for(int i=1;i<=zui;i++){ans+=x[i].a;}cout<<ans;continue;}
		sort(x+1,x+n+1,cmp1);
		for(int i=1;i<=n;i++){
			int da=max(x[i].a,max(x[i].b,x[i].c));
			if(da==x[i].a){
				if(r1<zui){r1++;ans+=da;continue;}
				else{
					da=max(x[i].b,x[i].c);
					if(da==x[i].b){
						if(r2<zui){r2++;ans+=da;continue;}
						else{r3++;ans+=x[i].c;continue;}
					}
				}
			}
			if(da==x[i].b){
				if(r2<zui){r2++;ans+=da;continue;}
				else{
					da=max(x[i].a,x[i].c);
					if(da==x[i].a){
						if(r1<zui){r1++;ans+=da;continue;}
						else{r3++;ans+=x[i].c;continue;}
					}
				}
			}if(da==x[i].c){
				if(r3<zui){r3++;ans+=da;continue; }
				else{
					da=max(x[i].b,x[i].a);
					if(da==x[i].b){
						if(r2<zui){r2++;ans+=da;continue;}
						else{r1++;ans+=x[i].a;continue;}
					}
				}
			}
		}
		cout<<ans<<'\n';
		clear(n);
	}
	return 0;
}
