#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
map<string,string> mp;
string t2,t1;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read();
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		mp[x]=y;
	}
	while(q--){
		cin>>t1>>t2;
		string s="";
		int m=t1.size(),ans=0;
		for(int i=0;i<=m;i++){
			if(i!=0) s+=t1[i-1];
			string c,ss=s;
			for(int j=i;j<m;j++){
				c+=t1[j];
				s+=mp[c];
				for(int k=j+1;k<m;k++) s+=t1[k];
				if(s==t2) ans++;
				s=ss;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
