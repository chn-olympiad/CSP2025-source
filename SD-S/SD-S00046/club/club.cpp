#include<bits/stdc++.h>
#define int long long
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define endl '\n'
using namespace std;

const int N=500010;
int n,ans=0;
struct nd{
	int a1,a2,a3;
}a[N];

void dfs(int pos,int x1,int x2,int lm){
	int x3=pos-x1-x2;
	if(pos==n+1){
		ans=max(ans,lm);
		return ;
	}
	if(x1<n/2){
		dfs(pos+1,x1+1,x2,lm+a[pos].a1);
	}
	if(x2<n/2){
		dfs(pos+1,x1,x2+1,lm+a[pos].a2);
	}
	if(x3<n/2){
		dfs(pos+1,x1,x2,lm+a[pos].a3);
	}
}
bool cmp(nd a,nd b){
	return a.a1>b.a1;
} 
void A(){
	int sum=0;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n/2;i++){
		sum+=a[i].a1;
	}
	cout<<sum<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	FILE("club")
	
	int T;cin>>T;
	while(T--){
		int flgA=1;
		memset(a,0,sizeof a);ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a2!=0||a[i].a3!=0) flgA=0;
		}
		if(flgA){
			A();
			continue;
		}
		dfs(1,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
