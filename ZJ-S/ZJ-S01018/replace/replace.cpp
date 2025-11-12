#include<bits/stdc++.h>
#define maxn 200005
#define ull unsigned long long
using namespace std;
namespace Super_Ultra_CZS_Office{
	inline int read(){
		int x=0,f=1;
		char ch=getchar();
		while(ch<'0'||ch>'9'){
			if(ch=='-')f=-1;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
		return x*f;
	}
	inline void write(int x){
		if(x<0){putchar('-');x=-x;}
		if(x>=10)write(x/10);
		putchar(x%10+'0');return;
	}
}
using namespace Super_Ultra_CZS_Office;
int n,q,cnt;
string s[maxn][2],t[2];
unordered_map<string,int>mp;
unordered_map<int,bool>gogo[maxn*5];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		for(int j=0;j<2;++j)
			cin>>s[i][j];
		if(!mp.count(s[i][0]))mp[s[i][0]]=++cnt;
		if(!mp.count(s[i][1]))mp[s[i][1]]=++cnt;
		++gogo[mp[s[i][1]]][mp[s[i][0]]];
	}
	while(q--){
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size()){
			cout<<0<<"\n";
			continue;
		}
		int len=t[0].size();
		int l=-1,r=-1;
		for(int i=0;i<len;++i){
			if(t[0][i]!=t[1][i]){
				if(l==-1)l=i;
				r=i;
			}
		}
		int ans=0;
		if(l==-1){
			for(int i=len-1;i>=0;--i)
				for(int j=1;j<=len-i;++j)
					ans+=gogo[mp[t[1].substr(i,j)]][mp[t[0].substr(i,j)]];
		}
		else{
			for(int i=l;i>=0;--i)
				for(int j=(r-i+1);j<=len-i;++j)
					ans+=gogo[mp[t[1].substr(i,j)]][mp[t[0].substr(i,j)]];
		}
		
		cout<<ans<<"\n";
	}
	return 0;
}
