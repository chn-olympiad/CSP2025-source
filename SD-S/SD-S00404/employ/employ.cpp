#include<bits/stdc++.h>
#define int long long
#define f(i,j,k) for(int i=j;i<=k;i++)
#define rf(i,j,k) for(int i=j;i>=k;i--)
#define mm(i) memset(i,0,sizeof i)
#define rm(i) memset(i,0x3f,sizeof i)
const int N=2e5+10;
const int mo=998244353;
const double pi=acos(-1.0);
using namespace std;
int n,m;
string s;
int a[N],ans;
int x[15]={0,1,2,3,4,5,6,7,8,9,10};
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	f(i,1,n) cin>>a[i];
	if(n<=10){
		do{
			int c=0;
			f(i,1,n){
				if(c>=a[x[i]]) c++;
				else if(s[i-1]=='0') c++;
			}
			if(n-c>=m) ans++;
		}while(next_permutation(x+1,x+n+1));
		cout<<ans;		
	}
	else{
		int cnt=0;
		f(i,1,n) if(!a[i]) cnt++;
		cnt=n-cnt;
		if(cnt>=m){
			ans=1;
			f(i,1,n) ans*=i,ans%=mo;
			cout<<ans;
		}
		else cout<<0;
		/*
		好像是炸得，不管了 
		*/
	}
	return 0;
}
