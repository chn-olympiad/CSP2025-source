#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,ans,h[N];
bool f[N];
struct node{
	int a,b,c,xc1,xc2,sum;
}s[N];
bool cmp(node x,node y){return x.a>y.a;}
bool cmp1(node x,node y){return x.xc1>y.xc1;}
void js(){
	int ss=0;
	for(int i=1;i<=n;i++){
		if(h[i]==1)ss+=s[i].a;
		if(h[i]==2)ss+=s[i].b;
		if(h[i]==3)ss+=s[i].c;
	}
	ans=max(ans,ss);
}
void dd(int k,int t1,int t2,int t3){
	if(k>n){
		js();
		return;
	}
	if(t1!=(n/2)){
		h[k]=1;
		dd(k+1,t1+1,t2,t3);
	}
	if(t2!=(n/2)){
		h[k]=2;
		dd(k+1,t1,t2+1,t3);
	}
	if(t3!=(n/2)){
		h[k]=3;
		dd(k+1,t1,t2,t3+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			s[i].xc1=abs(s[i].a-s[i].b);
		}
		ans=0;
		if(n<=10){
			dd(1,0,0,0);
			cout<<ans<<'\n';
			continue;
		}
		sort(s+1,s+n+1,cmp1);
		memset(f,0,sizeof(f));
		int k1=0,k2=0;
		for(int i=1;i<=n;i++){
			if(!f[i]){
				if(s[i].a>s[i].b){
					k1++;
					ans+=s[i].a;
				}
				else{
					k2++;
					ans+=s[i].b;
				}
				f[i]=1;
			}
			if(k1==(n/2)||k2==(n/2))break;
		}
		for(int i=1;i<=n;i++){
			if(!f[i]){
				if(k1==(n/2))ans+=s[i].b;
				else if(k2==(n/2))ans+=s[i].a;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
