#include<bits/stdc++.h>
#define int long long
#define rg register
#define gc getchar
#define pc putchar
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int inf=0x3f3f3f3f;
namespace IO{
	inline int read(){
		int x=0,f=1;
		char ch=gc();
		while(!isdigit(ch)){
			if(ch=='-') f=-f;
			ch=gc();
		}
		while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=gc();
		return x*f;
	}
	inline void write(int x){
		if(x<0) pc('-'),x=-x;
		if(x>9) write(x/10);
		pc(x%10+'0');
	}
}using namespace IO;
const int mod=998244353;
const int N=505;
string s;
int n,k,c[N],p[N],now[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	IOS
	cin>>n>>k>>s;s=" "+s;
	for(rg int i=1;i<=n;i++) cin>>c[i];
	if(n<=10){
		for(rg int i=1;i<=n;i++) p[i]=i;
		int ans=0;
		do{
//			for(rg int i=1;i<=n;i++) now[i]=p[i];
			int num=0;
			for(rg int i=1;i<=n;i++){
				if(s[i]=='0'||num>=c[p[i]]) num++;
			}
			if(n-num>=k) ans=(ans+1)%mod;
		}while(next_permutation(p+1,p+1+n));
		cout<<ans;
		return 0;
	}
	int ans=1;
	for(rg int i=1;i<=n;i++) ans=ans*i%mod;
	cout<<ans;
	return 0;
}
