#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const ll N=510,md=998244353LL;
//#define DBL
using namespace std;
ll n,m,s[N],ss[N],a[N],ans=0;
char ch;
int v[N],pl[N],tp;
void dfs(int p){
	for(int i=1;i<=n;i++){
		if(!v[i]){
			pl[p]=i;
			if(p==n){
				tp=0;
				for(int i=1;i<=p;i++){
					if(a[pl[i]]>(i-tp-1)&&s[i]){
						tp++;
					}
				}
				if(tp>=m)ans++;
				return ;
			}
			v[i]=1;dfs(p+1);v[i]=0;
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ch;
		s[i]=ch-'0';
		ss[i]=ss[i-1]+s[i];
	}
	if(ss[n]<m){
		cout<<0;
		exit(0);
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=10){
		dfs(1);	
	}
	cout<<ans;
	return 0;
}

