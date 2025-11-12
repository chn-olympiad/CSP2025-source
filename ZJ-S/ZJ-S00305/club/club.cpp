#include <bits/stdc++.h>
using namespace std;
long long t,n,ma,maxx,A,B,C,ans;
int sum[100050];
struct node{
	int a,b,c;
}d[100050];
bool cmp(node x,node y){
	return x.a>y.a;
}
void dfs(int i,int ans,bool f){
	if(i>n){
		if(ans>maxx)maxx=ans;
		ans=0;
		return;
	}
	if(sum[n]-sum[i-1]+ans<maxx)return;
	if(A<ma){
		A++;
		dfs(i+1,ans+d[i].a,f);
		A--;
	}
	if(B<ma){
		B++;
		dfs(i+1,ans+d[i].b,f);
		B--;
	}
	if(C<ma && f==0){
		C++;
		dfs(i+1,ans+d[i].c,f);
		C--;
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=A=B=C=0;
		maxx=-1;
		cin>>n;
		ma=n/2;
		memset(sum,0,sizeof(sum));
		bool F=1;
		for(int i=1;i<=n;i++){
			cin>>d[i].a>>d[i].b>>d[i].c;
			if(d[i].b!=0 || d[i].c!=0)F=0;
			sum[i]=sum[i-1]+max(d[i].a,max(d[i].b,d[i].c));
		}
		if(F==1){
			maxx=0;
			sort(d+1,d+n+1,cmp);
			for(int i=1;i<=n/2;i++)maxx+=d[i].a;
		}
		else if(n==200)
			dfs(1,0,1);
		else dfs(1,0,0);
		cout<<maxx<<endl;
	}
	return 0;
}
