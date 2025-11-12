#include<bits/stdc++.h>
using namespace std;
#define int long long
#define gc getchar
#define pc putchar
struct node{

};
inline int read(){
	int d=1,k=0;char c=gc();
	while(!(c>='0'&&c<='9'||c=='-'))c=gc();
	if(c=='-')c=gc(),d=-1;
	while(c>='0'&&c<='9')k=(k<<1)+(k<<3)+(c^48),c=gc();
	return d*k;
}inline void write(int x){
	static int sta[50];int top=0;
	do{sta[top++]=x%10;x/=10;}while(x);
	while(top)pc(sta[--top]+'0');
}inline int A(int n){
	int ans=1;
	for(int i=n;i>0;--i)ans*=i;
	return ans;
}signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n=read(),m=read();
	string s;cin>>s;
	for(int i=1;i<=n;++i)int c=read();
	write(A(n));
	return 0;
}

