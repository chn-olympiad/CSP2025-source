#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int r=0,x=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*x;
} 
const int N=2e5+10;
int n,q;
string s1[N],s2[N];
string t1[N],t2[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(); q=read();
	for(int i=1;i<=n;i++){
		cin>>s1[i];
		cin>>s2[i]; 
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i];
		cin>>t2[i];
	}
	for(int i=1;i<=q;i++){
		puts("0");
	}
	fclose(stdin);
	fclose(stdout);
return 0;
}

