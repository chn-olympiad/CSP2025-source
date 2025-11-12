#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,n,ans,m;
priority_queue <int,vector<int>,greater<int> > x,y,z;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		while(!x.empty()) x.pop();
		while(!y.empty()) y.pop();
		while(!z.empty()) z.pop();
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a,&b,&c);
			//mormal push
			m=max(a,max(b,c));
			if(a==m){
				ans+=a;
				x.push(a-max(b,c));
			}
			else if(b==m){
				ans+=b;
				y.push(b-max(a,c));
			}
			else{
				ans+=c;
				z.push(c-max(a,b));
			}
		}
		while(x.size()>n/2){
			ans-=x.top();
			x.pop();
		}
		while(y.size()>n/2){
			ans-=y.top();
			y.pop();
		}
		while(z.size()>n/2){
			ans-=z.top();
			z.pop();
		}
		printf("%d\n",ans);
	}
	
	return 0;
}