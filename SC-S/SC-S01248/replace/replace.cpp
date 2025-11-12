#include<bits/stdc++.h>
using namespace std;
namespace solve{
	inline int read(){
		int x=0,f=1;char ch=getchar();
		while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
		while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
		return x*f;
	}
	int n,q;
	string s[200005][2];
	string t[200005][2];
	inline signed solve(){
		freopen("replace.in","r",stdin);
		freopen("replace.out","w",stdout);
		n=read();q=read();
		for(int i=1;i<=n;i++)
			cin>>s[i][0]>>s[i][1];
		for(int i=1;i<=q;i++){
			cin>>t[i][0]>>t[i][1];
			int rlt=0;
			for(int j=1;j<=n;j++)
				if(t[i][0].find(s[j][0],0)==t[i][0].find(s[j][1],0)&&
				t[i][0].find(s[j][0],0)!=string::npos){
					string bk1=t[i][0];
					string bk2=t[i][1];
					auto pos=t[i][0].find(s[j][0],0);
					bk1.erase(pos,s[j][0].size());
					bk2.erase(pos,s[j][1].size());
					if(bk1==bk2)rlt++;
				}
			cout<<rlt<<endl;
		}
		return 0;
	}
}
int main(){return solve::solve();}