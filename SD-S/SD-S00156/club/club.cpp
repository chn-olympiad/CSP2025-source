#include<bits/stdc++.h>
using namespace std;
struct abc{
	int a,b,c,s,o;
}a[100005];
struct ababab{
	int t,s;
	friend bool operator < (ababab a,ababab b){
		return a.s>b.s;
	}
}cba;
int t,n,ans=0;
priority_queue<ababab> w; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		while(!w.empty()){
			w.pop();
		}
		ans=0;
		int x=0,y=0,z=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
				a[i].o=1;
				a[i].s=min(a[i].a-a[i].b,a[i].a-a[i].c);
				x++;
			}else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
				a[i].o=2;
				a[i].s=min(a[i].b-a[i].a,a[i].b-a[i].c);
				y++;
			}else{
				a[i].o=3;
				a[i].s=min(a[i].c-a[i].a,a[i].c-a[i].b);
				z++;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i].o==1){
				ans+=a[i].a;
				if(x>(n/2)){
					cba.t=i;
					cba.s=a[i].s;
					w.push(cba);
				}
			}else if(a[i].o==2){
				ans+=a[i].b;
				if(y>(n/2)){
					cba.t=i;
					cba.s=a[i].s;
					w.push(cba);
				}
			}else{
				ans+=a[i].c;
				if(z>(n/2)){
					cba.t=i;
					cba.s=a[i].s;
					w.push(cba);
				}
			}
		}
		x=max(x,max(y,z));
		if(x>(n/2)){
			int l=x-(n/2);
			for(int i=1;i<=l;i++){
				ababab xyz=w.top();
				ans-=xyz.s;
				w.pop();
			}	
		}
		printf("%d\n",ans);
	}
	return 0;
}
