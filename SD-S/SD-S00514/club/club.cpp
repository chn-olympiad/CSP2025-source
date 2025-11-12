#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
ll t,n,aa,bb,cc;
ll an,bn,cn;
struct node{
	ll a,b,c,id,num,nm;
}p[N];
bool cmp(node x,node y){
	if(x.nm==y.nm){
		if(x.num==y.num){
			if(x.a==y.a){
				if(x.b==y.b){
					if(x.c==y.c) return x.id>y.id;
					else return x.c>y.c;
				}
				else return x.b>y.b;
			}
			else return x.a>y.a;
		}
		else return x.num>y.num;
	}
	else return x.nm<y.nm;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		aa=0,bb=0,cc=0;
		an=0,bn=0,cn=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&p[i].a,&p[i].b,&p[i].c);
			p[i].id=i;
			p[i].num=p[i].a+p[i].b+p[i].c;
			p[i].nm=(p[i].a!=0)+(p[i].b!=0)+(p[i].c!=0);
		}
		sort(p+1,p+n+1,cmp);
//		for(int i=1;i<=n;i++){
//			cout<<p[i].num<<" "<<p[i].a<<" "<<p[i].b<<" "<<p[i].c<<" "<<p[i].id<<" "<<p[i].nm<<"\n";			
//		}
		for(int i=1;i<=n;i++){
			if(an>=n/2&&bn>=n/2&&cn>=n/2) continue;
			else if(an>=n/2&&bn>=n/2){
				cc+=p[i].c;
				cn++;
			}
			else if(an>=n/2&&cn>=n/2){
				bb+=p[i].b;
				bn++;
			}
			else if(bn>=n/2&&cn>=n/2){
				aa+=p[i].a;
				an++;
			}
			else if(an>=n/2){
				if(p[i].b>p[i].c){
					bb+=p[i].b;
					bn++;
				}
				else{
					cc+=p[i].c;
					cn++;
				}
			}
			else if(bn>=n/2){
				if(p[i].a>p[i].c){
					aa+=p[i].a;
					an++;
				}
				else{
					cc+=p[i].c;
					cn++;
				}
			}
			else if(cn>=n/2){
				if(p[i].b>p[i].a){
					bb+=p[i].b;
					bn++;
				}
				else{
					aa+=p[i].a;
					an++;
				}
			}
			else{
				if(p[i].a==max(p[i].a,max(p[i].b,p[i].c))){
					aa+=p[i].a;
					an++;
				}
				else if(p[i].b==max(p[i].a,max(p[i].b,p[i].c))){
					bb+=p[i].b;
					bn++;
				} 
				else{
					cc+=p[i].c;
					cn++;
				}
			}
		}
		printf("%lld\n",aa+bb+cc);
	}
	return 0;
}
