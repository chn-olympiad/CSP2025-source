#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+25;
struct node{
	ll a,b,c;
}s[N];
ll t,n,ans,l[15];
bool cmp1(node x,node y){
	return x.a-max(x.b,x.c)<y.a-max(y.b,y.c);
}
bool cmp2(node x,node y){
	return x.b-max(x.a,x.c)<y.b-max(y.a,y.c);
}
bool cmp3(node x,node y){
	return x.c-max(x.b,x.a)<y.c-max(y.b,y.a);
}
void sol(){
	cin>>n;
	ans=0;
	memset(l,0,sizeof(l));
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b>>s[i].c;
		if(s[i].a>=s[i].b&&s[i].a>=s[i].c){
			l[1]++;
			ans+=s[i].a;
		}else if(s[i].b>=s[i].a&&s[i].b>=s[i].c){
			l[2]++;
			ans+=s[i].b;
		}else{
			l[3]++;
			ans+=s[i].c;
		}
	}
	if(l[1]<=n/2&&l[2]<=n/2&&l[3]<=n/2){
		cout<<ans;
	}else{
		if(l[1]>n/2){
			sort(s+1,s+1+n,cmp1);
			for(int i=1;l[1]>n/2;i++){
				if(s[i].a<max(s[i].b,s[i].c))continue;
				ans-=s[i].a;ans+=max(s[i].b,s[i].c);l[1]--;
			}
		}else if(l[2]>n/2){
			sort(s+1,s+1+n,cmp2);
			for(int i=1;l[2]>n/2;i++){
				if(s[i].b<max(s[i].c,s[i].a))continue;
				ans-=s[i].b;ans+=max(s[i].a,s[i].c);l[2]--;
			}
		}else{
			sort(s+1,s+1+n,cmp3);
			for(int i=1;l[3]>n/2;i++){
				if(s[i].c<max(s[i].b,s[i].a))continue;
				ans-=s[i].c;ans+=max(s[i].b,s[i].a);l[3]--;
			}
		}
		cout<<ans;
	}
	cout<<'\n';
}
int main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		sol();
	}
	return 0;
}