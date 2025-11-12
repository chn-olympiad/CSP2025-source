#include<bits/stdc++.h>
using namespace std;
const int maxx=1e5+5;
struct node{
	int a,b,c;
}P[maxx];
bool cmp(const node&A,const node&B){
	if(A.a!=B.a)return A.a>B.a;
	if(A.b!=B.b)return A.b>B.b;
	return A.c>B.c;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=0;i<n;i++)cin>>P[i].a>>P[i].b>>P[i].c;
		sort(P+1,P+1+n,cmp);
		int ans=0;
		for(int i=0;i<n/2;i++)ans+=P[i].a;
		for(int i=n/2;i<n;i++)ans+=P[i].b;
		cout<<ans<<"\n";
	}
	return 0;
}