#include <bits/stdc++.h>
using namespace std;
int T,n,ans1,ans2,ans3;
struct node{
	int a,b,c;
}s[101000];
bool cmp1(const node &A,const node &B){
	if(A.a==B.a){
		if(A.b==B.b){
			return A.c<B.c;
		}
		if(A.c==B.c){
			return A.b<B.b;
		}
		return max(A.b,A.c)<max(B.b,B.c);
	}
	return A.a>B.a;
}
bool cmp2(const node &A,const node &B){
	if(A.b==B.b){
		if(A.a==B.a){
			return A.c<B.c;
		}
		if(A.c==B.c){
			return A.a<B.a;
		}
		return max(A.a,A.c)<max(B.a,B.c);
	}
	return A.b>B.b;
}
bool cmp3(const node &A,const node &B){
	if(A.c==B.c){
		if(A.b==B.b){
			return A.a<B.a;
		}  
		if(A.a==B.a){
			return A.b<B.b;
		}
		return max(A.b,A.a)<max(B.b,B.a);
	}
	return A.c>B.c;
}
void solve(){
	scanf("%d",&n);
	ans1=ans2=ans3=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
	}
	sort(s+1,s+n+1,cmp1);
	for(int i=1;i<=n/2;i++){
		ans1+=s[i].a;
	}
	for(int i=n/2+1;i<=n;i++){
		ans1+=max(s[i].b,s[i].c);
	}
	sort(s+1,s+n+1,cmp2);
	for(int i=1;i<=n/2;i++){
		ans2+=s[i].b;	
	}
	for(int i=n/2+1;i<=n;i++){
		ans2+=max(s[i].a,s[i].c);
	}
	sort(s+1,s+n+1,cmp3);
	for(int i=1;i<=n/2;i++){
		ans3+=s[i].c;	
	}
	for(int i=n/2+1;i<=n;i++){
		ans3+=max(s[i].a,s[i].b);
	}
	printf("%d\n",max(ans1,max(ans2,ans3)));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);	
	while(T--){
		solve();
	}
	return 0;
} 
