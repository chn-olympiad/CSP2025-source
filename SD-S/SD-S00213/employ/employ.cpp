#include<bits/stdc++.h>
using namespace std;
#define go(i,l,r) for(int (i)=(l);(i)<=(r);++(i))

#define ll long long
#define int ll

int read(){
	int w=1,x=0;
	char ch=getchar();
	while(ch<'0'||'9'<ch){
		if(ch=='-') w=-w;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=10*x+ch-'0';
		ch=getchar();
	}
	return w*x;
}

const int N=5e2+10;
const int M=1e4+10;
const int mod=998244353;
int n,m,c[N];
string s;
int t[N],ans=1;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("empoly.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	go(i,1,n){
		c[i]=read();
		t[c[i]]++;
	}
	bool fg=0;
	go(i,0,s.size()-1){
		if(s[i]!='1'){
			fg=1;
			break;
		}
	}
	if(!fg){
		go(i,1,n-t[0]) ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	return 0;
}

