#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,t[5];
struct people{
	int score,num;
};
struct node{
	people a,b,c;
}s[N];
int cmp(node a,node b){
//	int x=max(max(a.a,a.b),a.c),z=min(min(a.a,a.b),a.c);
//	int xx=max(max(b.a,b.b),b.c),zz=min(min(b.a,b.b),b.c);
//	int y=a.a+a.b+a.c-x-z;
//	int yy=b.a+b.b+b.c-xx-zz;
//	if(x-y==xx-yy) return y-z>yy-zz;
//	return x-y>xx-yy;
	if(a.a.score-a.b.score==b.a.score-b.b.score) return a.b.score-a.c.score>b.b.score-b.c.score;
	return a.a.score-a.b.score>b.a.score-b.b.score;
} 
int main(){//15:13ÄÃÏÂ£¡£¡£¡ 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(t,0,sizeof t);
		int ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&s[i].a.score,&s[i].b.score,&s[i].c.score);
			s[i].a.num=1,s[i].b.num=2,s[i].c.num=3;
			if(s[i].a.score<s[i].b.score) swap(s[i].a,s[i].b);
			if(s[i].a.score<s[i].c.score) swap(s[i].a,s[i].c);
			if(s[i].b.score<s[i].c.score) swap(s[i].b,s[i].c);
		}
		sort(s+1,s+n+1,cmp);
//		cout<<endl;
//		for(int i=1;i<=n;i++){
//			printf("%d %d %d\n",s[i].a,s[i].b,s[i].c);
//		}
		for(int i=1;i<=n;i++){
			if(t[s[i].a.num]<n/2) t[s[i].a.num]++,ans+=s[i].a.score;
			else t[s[i].b.num]++,ans+=s[i].b.score;
		}
		printf("%d\n",ans);
	}
	return 0;
}
