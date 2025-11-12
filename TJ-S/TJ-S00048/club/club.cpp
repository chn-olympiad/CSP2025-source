#include <bits/stdc++.h>
using namespace std;
struct node{
	long long a,b,c;
}s[100001];
long long L,n,a,b,c,maxn=-99999,c1,c2,c3;
bool cmp1(node x,node y){
	return x.a>y.a;
}
bool cmp2(node x,node y){
	return x.b>y.b;
}
bool cmp3(node x,node y){
	return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>L;
	for(int dao = 1;dao<=L;dao++){
		cin>>n;
		for(int i = 1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
		}
		
		sort(s+1,s+1+n,cmp1);
		for(int i = 1;i<=n;i++){
			c1+=s[i].a;
		}
		for(int i = n/2+1;i<=n;i++){
			int k = max(s[i].b,s[i].c);
			c1-=s[i].a;
			c1+=k;
		}
		
		sort(s+1,s+1+n,cmp2);
		for(int i = 1;i<=n;i++){
			c2+=s[i].b;
		}
		for(int i = n/2+1;i<=n;i++){
			int k = max(s[i].a,s[i].c);
			c2-=s[i].b;
			c2+=k;
		}
		
		sort(s+1,s+1+n,cmp3);
		for(int i = 1;i<=n;i++){
			c3+=s[i].c;
		}
		for(int i = n/2+1;i<=n;i++){
			int k = max(s[i].b,s[i].a);
			c3-=s[i].c;
			c3+=k;
		}
		
		
		maxn=max(maxn,c1);
		maxn=max(maxn,c2);
		maxn=max(maxn,c3);
		cout<<maxn;
		maxn=-99999;
		c1=0;c2=0;c3=0;
	} 
	return 0;
}
