#include<bits/stdc++.h>
using namespace std;
long long read(){
	char c=getchar();
	long long s=0;
	while(c<'0' || c>'9'){
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=(s<<1)+(s<<3)+int(c-'0');
		c=getchar();
	}
}
string strread(){
	char c=getchar();
	string sx="";
	while(c!='0' && c!='1'){
		c=getchar();
	}
	while(c=='0' || c=='1'){
		sx+=c;
		c=getchar();
	}
	return sx;
}
long long n,m,x,c[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	s=strread();
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			cout<<"0";
			return 0;
		}
	}
	x=1;
	for(int i=n;i>=n-m;i--){
		x=(x*i)%998244353;
	}
	cout<<x<<endl;
	return 0;
}
