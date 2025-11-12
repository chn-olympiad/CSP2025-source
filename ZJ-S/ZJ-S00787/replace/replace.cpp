#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch))f=ch=='-'?-f:f,ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
const int N=2e5+10;
int n,q;
string t[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++)cin>>t[i][0]>>t[i][1];
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int l=-1,r=-1;
		for(int i=0;i<s1.size();++i)if(s1[i]!=s2[i]){l=i;break;}
		for(int i=s1.size()-1;i>=0;i--)if(s1[i]!=s2[i]){r=i;break;}
		int len=r-l+1;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(t[i][0].size()<len)continue;
			string str=s1;
			string L="";
			while(str.find(t[i][0])!=-1){
				l=str.find(t[i][0]),r=l+t[i][0].size();
				string s=L+str.substr(0,l)+t[i][1]+str.substr(r,str.size()-r);
				if(s==s2){ans++;break;}
				L+=str.substr(0,r),str.erase(0,r);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//Luogu user :I_Love_Furina
//Luogu uid 1113349
//Genshin Impact uid 275713829
//Fuirna!!!
//RP++
//100+56?+25+8=189?