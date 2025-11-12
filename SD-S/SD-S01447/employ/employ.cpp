#include<bits/stdc++.h>
using namespace std;
#define re(i,n) for(int i=1;i<=n;i++)
#define pe(i,n) for(int i=n;i>=1;i--)
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
#define CIOO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define lowbit(x) (x & -x)

const int N=505;
int n,m,c[N];
char s[N];
int p[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	CIOO;
	cin>>n>>m;
	cin>>(s+1);
	re(i,n)cin>>c[i];
	re(i,n)p[i]=i;
	int ans=0;
	do{
		int cnt=0,now=0;
		re(i,n){
			if(now>=c[p[i]]||s[i]=='0'){
				now++;
			}
			else cnt++;
		}
		if(cnt>=m)ans++;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans<<'\n';
	return 0;
}
