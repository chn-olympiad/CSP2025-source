#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')  f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1ll)+(x<<3ll)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int const N=1e3+5;
int n,m,ans,cnt,q;
struct node{
	int x,y,len;
	bool operator < (const node &x) const{
		return x.len<len;
	}
};
map<node,int> mp;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    n=read(),q=read();
    for(int i=1;i<=n;i++){
    	string s,ss;
    	cin>>s>>ss;
    	s=' '+s;
    	ss=' '+ss;
    	int x=0,y=0;
    	for(int j=1;j<s.size();j++){
			if(s[j]=='b'){
				x=i;
				break;
			}
		}
		for(int j=1;j<ss.size();j++){
			if(ss[j]=='b'){
				y=i;
				break;
			}
		}
		mp[{x,y,s.size()-1}]++;
	}
	while(q--){
		string t[2];
		cin>>t[0]>>t[1];
		t[0]=' '+t[0];
		t[1]=' '+t[1];
		int x=0,y=0;
		for(int i=1;i<t[0].size();i++){
			if(t[0][i]=='b'){
				x=i;
				break;
			}
		}
		for(int i=1;i<t[1].size();i++){
			if(t[1][i]=='b'){
				y=i;
				break;
			}
		}
		int w=max(x,y);
		int res=mp[{x,y,w}];
		//Òª»»[x,y]Çø¼ä
		int z=min(x,y);
		for(int j=1;j<z;j++){
			res+=mp[{x-j,y-j,w-j}];
		}
		for(int j=w+1;j<t[0].size();j++){
			int uu=j-w;
			res+=mp[{x,y,j}];
		}
		cout<<res<<'\n';	
	}
	return 0;
}

