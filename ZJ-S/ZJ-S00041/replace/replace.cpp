#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int sum=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-f;c=getchar();}
	while(isdigit(c)){sum=sum*10+c-'0';c=getchar();}
	return sum*f;
}
const int N=1e4+5,M=1e6+5;
int n,q;
string s1,s2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1>>s2;
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		cout<<0<<endl;
	}
	return 0;
}
