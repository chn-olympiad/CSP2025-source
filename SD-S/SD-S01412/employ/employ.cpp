#include<bits/stdc++.h>
#define g() getchar()
#define int long long
using namespace std;
const int N=600;
const int mod=998244353;
int n,m;
int s[N];
int c[N];
int a[N];
string S;
int solve(){
	int res=1;
	for(int i=1;i<=n;i++){
		(res*=i)%=mod;
	}
	return res;
}
signed main(){
	ios::sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>S;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>c[i],s[i]=S[i-1]-'0',a[i]=i;
		if(!s[i])flag=0;
	}
	if(flag){
		cout<<solve()<<endl;
		return 0;
	}
	int num=0;
	do{
		int ct=0;
		int r=0;
		for(int i=1;i<=n;i++){
			if(ct>=c[a[i]]||s[i]==0)ct++;
		}
		if(n-ct>=m){
			num=(num+1)%mod;
		}
	}while(next_permutation(a+1,a+1+n));
	cout<<num<<endl;
	return 0;
}

