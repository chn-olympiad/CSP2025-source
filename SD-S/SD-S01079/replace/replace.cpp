#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
inline long long read(){
	long long f=1,x=0;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return f*x;
}
int n,q;
string a,b,s1[N],s2[N];
int b1[N];
int lth[5000006];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		b1[i]=s1[i].find('b')-s2[i].find('b');
		if(b1[i]<5000006) lth[b1[i]]++;
	}
	while(q--){
		cin>>a>>b;
		bool kg=0;
		for(int i=0;i<a.size();i++) if(a[i]!='a'&&a[i]!='b'||b[i]!='a'&&b[i]!='b'){kg=1;break;}
		if(!kg){
			int C=a.find('b')-b.find('b');
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a.size()>=s1[i].size()&&b1[i]==C) ans++;
			}
			cout<<ans<<'\n';
			continue;
		}
		string c;
		int ans=0;
		for(int i=1;i<=n;i++){
			c=a;
			int x=a.find(s1[i]);
			if(x>c.size()) continue;
			for(int j=x;j<x+s1[i].size();j++){
				c[j]=s2[i][j-x];
			}
			if(c==b) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
