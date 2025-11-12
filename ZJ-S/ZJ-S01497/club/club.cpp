#include<bits/stdc++.h>
using namespace std;
struct workers{
	int a,b,c,dif,op;
}f[100005];
priority_queue<int>A,B,C;
int ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&f[i].a,&f[i].b,&f[i].c);
		for(int i=1;i<=n;i++){
			if(f[i].a>=f[i].b&&f[i].a>=f[i].c){
				f[i].dif=max(f[i].b-f[i].a,f[i].c-f[i].a);
				f[i].op=1;
			}
			else if(f[i].b>=f[i].c){
				f[i].dif=max(f[i].a-f[i].b,f[i].c-f[i].b);
				f[i].op=2;
			}
			else{
				f[i].dif=max(f[i].a-f[i].c,f[i].b-f[i].c);
				f[i].op=3;
			}
		}
		for(int i=1;i<=n;i++){
			if(f[i].op==1){
				if(A.size()<n/2){
					A.push(f[i].dif);
					ans+=f[i].a;
				}
				else if(A.top()<f[i].dif) ans+=max(f[i].c,f[i].b);
				else{
					ans+=A.top();
					ans+=f[i].a;
					A.pop();
					A.push(f[i].dif);
				}
			}
			else if(f[i].op==2){
				if(B.size()<n/2){
					B.push(f[i].dif);
					ans+=f[i].b;
				}
				else if(B.top()<f[i].dif) ans+=max(f[i].a,f[i].c);
				else{
					ans+=B.top();
					ans+=f[i].b;
					B.pop();
					B.push(f[i].dif);
				}
			}
			else{
				if(C.size()<n/2){
					C.push(f[i].dif);
					ans+=f[i].c;
				}
				else if(C.top()<f[i].dif) ans+=max(f[i].a,f[i].b);
				else{
					ans+=C.top();
					ans+=f[i].c;
					C.pop();
					C.push(f[i].dif);
				}
			}
		}
		printf("%d\n",ans);
		while(!A.empty()) A.pop();
		while(!B.empty()) B.pop();
		while(!C.empty()) C.pop();
		ans=0;
	}
	return 0;
}