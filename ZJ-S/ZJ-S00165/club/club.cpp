#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
inline void read(int &x){scanf("%d",&x);}
inline void write(int x){printf("%d",x);}
int T,n,ans;
struct Node{
	int a,b,c;
}node[MAXN];
priority_queue<int,vector<int>,greater<int>>a,b,c;
inline void reset(){
	ans=0;
	while(!a.empty()) a.pop();
	while(!b.empty()) b.pop();
	while(!c.empty()) c.pop();
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
	while(T--){
		reset();
		read(n);
		for(int i=0;i<n;i++){
			read(node[i].a),read(node[i].b),read(node[i].c);
			if(node[i].a>=node[i].b&&node[i].a>=node[i].c){
				ans+=node[i].a;
				a.push(node[i].a-max(node[i].b,node[i].c));
			}
			else if(node[i].b>=node[i].a&&node[i].b>=node[i].c){
				ans+=node[i].b;
				b.push(node[i].b-max(node[i].a,node[i].c));
			}
			else{
				ans+=node[i].c;
				c.push(node[i].c-max(node[i].a,node[i].b));
			}
		}
		unsigned int m=n>>1;
		while(a.size()>m){
			ans-=a.top();
			a.pop();
		}
		while(b.size()>m){
			ans-=b.top();
			b.pop();
		}
		while(c.size()>m){
			ans-=c.top();
			c.pop();
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
