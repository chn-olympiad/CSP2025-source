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
const int N=2e5+10;
int n,q;
string s[N][2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	IOS
	cin>>n>>q;
	for(rg int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	while(q--){
		string t1,t2;
		cin>>t1>>t2;int len=t1.size();
		int ans=0,l=0,r=0;
		for(rg int i=0;i<len;i++) if(t1[i]!=t2[i]){l=i;break;}
		for(rg int i=len-1;i>=0;i--) if(t1[i]!=t2[i]){r=i;break;}
		for(rg int i=1;i<=n;i++){
			int p1=t1.find(s[i][0]),p2=t2.find(s[i][1]);
			int L=s[i][0].size();
			if(p1!=-1&&p2!=-1&&p1==p2&&L>=(r-l+1)) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
