#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#define ll long long
using namespace std;
const int N=1e5+10;
int T,n,A,B,C,ans,res1,res2,res3,res4;
struct node{
	int a,b,c;
}p[N];
bool cmp1(struct node x,struct node y){
	return x.a-max(x.b,x.c)>y.a-max(y.b,y.c);
}
bool cmp2(struct node x,struct node y){
	return x.b-max(x.a,x.c)>y.b-max(y.a,y.c);
}
bool cmp3(struct node x,struct node y){
	return x.c-max(x.a,x.b)>y.c-max(y.a,y.b);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=res1=res2=res3=res4=0,A=B=C=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
			if(p[i].a==p[i].b&&p[i].b==p[i].c){
				res1+=p[i].a;
				if(A==min(min(A,B),C))A++;
				else if(B==min(min(A,B),C))B++;
				else C++;
			}if(p[i].a==p[i].b&&p[i].a>p[i].c){
				res1+=p[i].a;
				if(A<B)A++;
				else B++;
			}if(p[i].a==p[i].c&&p[i].c>p[i].b){
				res1+=p[i].a;
				if(A<C)A++;
				else C++;
			}if(p[i].b==p[i].c&&p[i].c>p[i].a){
				res1+=p[i].b;
				if(B<C)B++;
				else C++;
			}
			if(p[i].a>max(p[i].b,p[i].c))A++,res1+=p[i].a;
			if(p[i].b>max(p[i].a,p[i].c))B++,res1+=p[i].b;
			if(p[i].c>max(p[i].b,p[i].a))C++,res1+=p[i].c;
		}
		if(A<=n/2&&B<=n/2&&C<=n/2){
			printf("%d\n",res1);
		}else{
			sort(p+1,p+1+n,cmp1);
			for(int i=1;i<=n/2;i++){
				res2+=p[i].a;
			}for(int i=n/2+1;i<=n;i++){
				res2+=max(p[i].b,p[i].c);
			}
			sort(p+1,p+1+n,cmp2);
			for(int i=1;i<=n/2;i++){
				res3+=p[i].b;
			}for(int i=n/2+1;i<=n;i++){
				res3+=max(p[i].a,p[i].c);
			}
			sort(p+1,p+1+n,cmp3);
			for(int i=1;i<=n/2;i++){
				res4+=p[i].c;
			}for(int i=n/2+1;i<=n;i++){
				res4+=max(p[i].a,p[i].b);
			}
			ans=max(max(res2,res3),res4);
			printf("%d\n",ans);
		}
	}
	return 0;
}
