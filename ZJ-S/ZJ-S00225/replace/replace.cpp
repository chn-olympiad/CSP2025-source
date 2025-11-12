#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5,maxl=2e6+5;
int n,q;

int read(){
    int ret=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
unordered_map<string,string> to[5000005];

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    n=read(),q=read();
    for(int i=1;i<=n;i++){
    	string a,b;
    	cin>>a>>b;
    	to[(int)a.size()][a]=b;
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()){cout<<0<<endl;
		continue;
		}
		int len=a.size();
		a=" "+a;
		b=" "+b;
		int l=1,r=len;
		for(;l<=len;l++) if(a[l]!=b[l]) break;
		for(;r;r--) if(a[r]!=b[r]) break;
		for(int _=(r-l+1);_<=len;_++)
		for(auto it:to[_]) for(int k=1;k<=len-(int)it.first.size()+1;k++) if(a.substr(k,it.first.size())==it.first&&b.substr(k,it.first.size())==it.second){ans++;;;}
		cout<<ans<<endl;
	}
    return 0;
}
