#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int a[maxn],n;
string ch;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f*=-1;ch=getchar();}
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>ch;
	for(int i=1;i<=ch.size();i++)if(isdigit(ch[i-1])) a[++n]=ch[i-1]-'0';
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--) printf("%d",a[i]);
	return 0;
}
