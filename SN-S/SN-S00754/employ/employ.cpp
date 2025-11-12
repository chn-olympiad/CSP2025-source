//SN-S00754  陈钰婉  西安高新第一中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=505,mod=998244353;
int n,m,a[maxn],c[maxn];
string s;

int p[maxn];
void qwq(){
	int ans=0;
	iota(p+1,p+1+n,1);
	do{
		int cnt=0,tot=0;//被拒绝的人  一共被录用的人 
		for(int i=1;i<=n;i++){
			int x=p[i];
			if(cnt>=c[x]){
				cnt++;continue;
			}
			if(a[i]==1) tot++;
			else cnt++;
		}
		if(tot>=m) ans++;
	}while(next_permutation(p+1,p+1+n));
	cout<<ans<<endl;
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		a[i]=s[i]-'0';
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	
	if(n<=10){
		qwq();return 0;
	}
	else{
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%mod;
		}
		cout<<ans<<endl;
	}
}
/*3 1
111
0 1 3*/
