#include<bits/stdc++.h>
using namespace std;
namespace{
	int read(){
		int x=0;char c=0;
		while(c<'0'||c>'9') c = getchar();
		while(c>='0'&&c<='9') {
			x = x*10 +(c^48);
			c = getchar();
		}
		return x;
	}
	struct node{
		int a,b,c;
	}a[100005];
	void solve(){
	    freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
		int T = read();
		while(T--){
			int n =read();
			int ans=0;
			for(int i = 1;i<=n;i++){
				a[i].a = read(),a[i].b = read(),a[i].c = read();
			}
			int ans1 = 0;
			sort(a+1,a+n+1,[](node x,node y)->bool{
				return max(x.b-x.a,x.c-x.a)>max(y.b-y.a,y.c-y.a);
			});
			for(int i = 1;i<=(n>>1);i++){
				ans1 +=  max(a[i].b,a[i].c);
			}
			for(int i = (n>>1)+1;i<=n;i++){
				ans1 +=  a[i].a;
			}
			//printf("%d\n",ans1);
			ans = max(ans,ans1);
			
			ans1 = 0;
			sort(a+1,a+n+1,[](node x,node y)->bool{
				return max(x.a-x.b,x.c-x.b)>max(y.a-y.b,y.c-y.b);
			});
			
			for(int i = 1;i<=(n>>1);i++){
				ans1 +=  max(a[i].a,a[i].c);
			}
			for(int i = (n>>1)+1;i<=n;i++){
				ans1 +=  a[i].b;
			}
			//printf("%d\n",ans1);
			ans = max(ans,ans1);
			
			ans1 = 0;
			sort(a+1,a+n+1,[](node x,node y)->bool{
				return max(x.a-x.c,x.b-x.c)>max(y.a-y.c,y.b-y.c);
			});
			
			for(int i = 1;i<=(n>>1);i++){
				ans1 +=  max(a[i].a,a[i].b);
			}
			for(int i = (n>>1)+1;i<=n;i++){
				ans1 +=  a[i].c;
			}
			//printf("%d\n",ans1);
			ans = max(ans,ans1);
			ans1 = 0;
			int na =0 ,nb = 0,nc = 0;
			for(int i = 1;i<=n;i++){
				if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
					ans1 += a[i].a;
					if(++na>=(n>>1)) break; 
				}else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
					ans1 += a[i].b;
					if(++nb>=(n>>1)) break; 
				}else if(a[i].c>=a[i].a&&a[i].c>=a[i].b){
					ans1 += a[i].c;
					if(++nc>=(n>>1)) break; 
				}
			}
			ans = max(ans1,ans);
			//printf("%d\n",ans1);
			printf("%d\n",ans);
		} 
	}
}
int main(){
	solve();
	return 0;
}

