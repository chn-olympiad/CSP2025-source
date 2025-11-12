#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+2;
int t,n;
struct node{
	int a,b,c,m,id;
}s[MAXN];
bool cmp(node x,node y){
	return x.m>y.m;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		long long ans=0;
		//输入+预处理极大值 
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
			s[i].m=max({s[i].a,s[i].b,s[i].c});
			if(s[i].m==s[i].a) s[i].id=1;
			else if(s[i].m==s[i].b) s[i].id=2;
			else s[i].id=3;
		}
		sort(s+1,s+1+n,cmp);
		for(int i=1;i<=n/2;i++) ans+=s[i].m;
		cout<<ans<<endl;
	}
}
