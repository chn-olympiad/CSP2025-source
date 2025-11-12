#include<iostream>
#include<string>
#define int long long
using namespace std;
const int N=2e5+5;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return x*f;
}
int n,q;
string s[N][4],t[4];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	while(q--){
		cin>>t[1]>>t[2];
		int len=t[1].size(),ans=0;
		for(int i=1;i<=n;i++){
			int ll=s[i][1].size();
			for(int j=0;j+ll-1<=len;j++){
				int flg=1;
				for(int k=0;k<ll;k++){
					if(t[1][j+k]!=s[i][1][k]){
						flg=0;
						break;
					}
				}
				if(flg==0)continue;
				string tmp="";
				for(int k=0;k<j;k++)tmp+=t[1][k];
				for(int k=0;k<s[i][2].size();k++)tmp+=s[i][2][k];
				for(int k=j+ll;k<len;k++)tmp+=t[1][k];
//				cout<<tmp<<"\n";
				if(tmp.size()!=t[2].size())continue;
				flg=1;
				for(int k=0;k<tmp.size();k++){
					if(tmp[k]!=t[2][k]){
						flg=0;
						break;
					}
				}
				if(flg==0)continue;
				ans++;
//				printf("%lld %lld\n",i,j);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
4 2
xabcx
xadex
ab cd
bc de
aa bb
xabcx xadex
*/
