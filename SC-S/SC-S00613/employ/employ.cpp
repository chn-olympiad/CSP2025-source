#include<bits/stdc++.h>
using namespace std;
#define db double
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
const int N=505,P=998244353;
int n,m;
int s[N],c[N],p[N];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	string ss;cin>>ss;rep(i,1,n)s[i]=ss[i-1]-'0';
	rep(i,1,n)cin>>c[i],p[i]=i;
	if(n==m){
		bool ck=1;rep(i,1,n)ck&=s[i],ck&=(!!c[i]);
		if(ck){
			ll ans=1;rep(i,1,n)ans*=i,ans%=P;
			printf("%lld",ans);
		}else printf("0");
		return 0;
	}
	int ans=0;
	do{
		int cnt=0;
		rep(i,1,n){
			if(cnt>=c[p[i]]||s[i]==0)cnt++;
		}
		if(n-cnt>=m)ans++;
	}while(next_permutation(p+1,p+n+1));
	printf("%d",ans);
	return 0;
}