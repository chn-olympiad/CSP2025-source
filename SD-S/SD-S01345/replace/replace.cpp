#include<bits/stdc++.h>
#define LL long long
#define run(now) cout<<"there"<<now<<endl;
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x*f;
}
int n,q;
vector<string>s[2];
string t[2];
vector<vector<int> >kmp[2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	s[0].push_back("0");s[1].push_back("0");
	for(int i=1;i<=2*n;i++){
		string now;
		cin>>now;
		s[(i&1)^1].push_back(now);
	}
	while(q--){
		int L=10000000,R=0;
		cin>>t[0]>>t[1];
		for(int i=1;i<=t[0].size();i++)
			if(t[0][i-1]!=t[1][i-1])
				L=min(L,i),R=max(R,i);
		int ans=0;
		for(int i=1;i<=L;i++){
			for(int j=1;j<=n;j++){
				if(i+s[0][j].size()-1<R)continue;
				for(int k=1;k<=s[0][j].size();k++)
					if(s[0][j][k-1]!=t[0][i+k-1-1]||s[1][j][k-1]!=t[1][i+k-1-1])
						goto cx;
				ans++;
				cx:;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

