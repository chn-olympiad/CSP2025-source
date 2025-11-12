#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define up(i,j,k,l) for(int i=j;i<=k;i+=l)
#define down(i,j,k,l) for(int i=j;i>=k;i-=l)
using namespace std;
const int N=5e2+10,MOD=998244353;
int n,m;
char a[N];
int c[N],p[N],lc,res,ct;
ll ans;
void solve()
{
	cin>>n>>m;
	bool f=true;
	up(i,1,n,1){
		cin>>a[i];
		if(a[i]=='0'){
			f=false;
		} 
	}
	up(i,1,n,1){
		cin>>c[i];
		if(c[i]==0){
			lc++;
		}
		p[i]=i;
	}
	if(n-lc<m){
		cout<<0;
		return;
	}
	if(f){
		if(lc){
			n--;
		} 
		ans=1;
		up(i,1,n,1){
			ans*=i;
			ans%=MOD;
		}
		cout<<ans;
		return;
	}
	do{
		ct=0;
		res=0;
		up(i,1,n,1){
			if(a[i]=='0'){
				res++;
			}
			else if(res<c[p[i]]){
				ct++;
			}
			else{
				res++;
			}
		}
		if(ct>=m){
			ans++;
		}
		ans%=MOD;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	int _=1;
	//cin>>_;
	up(i,1,_,1){
		solve();
	}
	return 0;
}

