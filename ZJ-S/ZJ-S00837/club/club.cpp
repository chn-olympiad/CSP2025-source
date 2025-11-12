#include<bits/stdc++.h>
using namespace std;
struct N{
	int a,b,c;
	bool operator <(const N tmp) const{
		if(a>=b&&a>=c){
			return a-max(b,c)>tmp.a-max(tmp.b,tmp.c);
		}else if(b>=a&&b>=c){
			return b-max(a,c)>tmp.b-max(tmp.a,tmp.c);
		}else{
			return c-max(a,b)>tmp.c-max(tmp.a,tmp.b);
		}
	}
};
priority_queue <N> x;
priority_queue <N> y;
priority_queue <N> z;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n,k,ans=0;
		cin>>n;
		k = n/2;
		for(int i=1;i<=n;i++){
			N t;
			cin>>t.a>>t.b>>t.c;
			if(t.a>=t.b&&t.a>=t.c){
				x.push(t);
			}else if(t.b>=t.a&&t.b>=t.c){
				y.push(t);
			}else{
				z.push(t);
			}
		}
		int u=x.size(),v=y.size(),l=z.size();
		while(u>k){
			N t = x.top();
			x.pop();
			if(t.b>=t.c){
				y.push(t);
			}else{
				z.push(t);
			}
			u--;
		}
		while(v>k){
			N t = y.top();
			y.pop();
			if(t.a>=t.c){
				x.push(t);
			}else{
				z.push(t);
			}
			v--;
		}
		while(l>k){
			N t = z.top();
			z.pop();
			if(t.a>=t.b){
				x.push(t);
			}else{
				y.push(t);
			}
			l--;
		}
		while(!x.empty()){
			ans+=x.top().a;
			x.pop();
		}
		while(!y.empty()){
			ans+=y.top().b;
			y.pop();
		}
		while(!z.empty()){
			ans+=z.top().c;
			z.pop();
		}
		cout<<ans<<'\n';
	}
	return 0;
}
