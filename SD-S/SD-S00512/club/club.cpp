#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
inline int read();
int T,n;
int ans=-1;
bool vis[114514];
struct NODE{
	int a,b,c;
};
int cmp(const NODE &x,const NODE &y){
	if(x.a!=y.a) return x.a>y.a;
	if(x.b!=y.b) return x.b>y.b;
	return x.c>y.c;
}
void dfs(int sa,int sb,int sc,int na,int nb,int nc,vector<NODE> &s){
	ans=max(ans,sa+sb+sc);
	for(int t=0;t<n;t++)
		if(!vis[t]){ 
			NODE i=s[t];
			vis[t]=1;
			int a=i.a,b=i.b,c=i.c;
			if(na+1<=n/2)dfs(sa+a,sb,sc,na+1,nb,nc,s);
			if(nb+1<=n/2)dfs(sa,sb+b,sc,na,nb+1,nc,s);
			if(nc+1<=n/2)dfs(sa,sb,sc+c,na,nb,nc+1,s);
			vis[t]=0;
		}
	return ;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n<=8){
			ans=-1;
			memset(vis,0,sizeof(vis));
			vector<NODE> s(n);
			for(int i=0;i<n;i++)
			cin>>s[i].a>>s[i].b>>s[i].c;
			dfs(0,0,0,0,0,0,s);
			cout<<ans<<endl;
		}else{
			ans=0;
			vector<NODE> s(n);
			for(int i=0;i<n;i++)
			cin>>s[i].a>>s[i].b>>s[i].c;
			
			sort(s.begin(),s.end(),cmp);
			
			int na=0,nb=0,nc=0,ans=0,ans1=0;
			for(auto &i:s){
				int a=i.a,b=i.b,c=i.c;
				if(a>=b&&a>=c&&na<n/2){
					na++;
					ans+=a;
				}
				if(b>=a&&b>=c&&nb<n/2){
					nb++;
					ans+=b;
				}
				if(c>=a&&c>=b&&nc<n/2){
					nc++;
					ans+=c;
				}
			}
			na=0;nb=0;nc=0;
			for(int t=n-1;t>=0;t--){
				auto i=s[t];
				int a=i.a,b=i.b,c=i.c;
				if(na<=n/2&&nb<=n/2&&nc<=n/2){
					if(a>=b&&a>=c){
						na++;
						ans1+=a;
						continue;
					}
					if(b>=a&&b>=c){
						nb++;
						ans1+=b;
						continue;
					}
					if(c>=a&&c>=b){
						nc++;
						ans1+=c;
						continue;
					}
				}
				if(na==n/2){
					if(nb==n/2){
						if(nc==n/2) break;
						ans1+=c;nc++;continue;
					}else if(nc==n/2){
						if(nb==n/2) break;
						ans1+=b;nb++;continue;
					}
					if(b>c){
						ans1+=b;
						nb++;continue;
					}else{
						ans1+=c;
						nc++;continue;
					}
				}
				if(nb==n/2){
					if(na==n/2){
						if(nc==n/2) break;
						ans1+=c;nc++;continue;
					}else if(nc==n/2){
						if(na==n/2) break;
						ans1+=a;na++;continue;
					}
					if(a>c){
						ans1+=a;
						nb++;continue;
					}else{
						ans1+=c;
						nc++;continue;
					}
				}
				if(nc==n/2){
					if(na==n/2){
						if(nb==n/2) break;
						ans1+=b;nb++;continue;
					}else if(nb==n/2){
						if(na==n/2) break;
						ans1+=a;na++;continue;
					}
					if(b>a){
						ans1+=b;
						nb++;continue;
					}else{
						ans1+=a;
						na++;continue;
					}
				}
			}
			cout<<max(ans,ans1)<<endl;
		}
		
	}
	fclose(stdin); 
	fclose(stdout);
	return 0;
}
