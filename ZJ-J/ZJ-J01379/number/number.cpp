#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int n,num[10];
char S[maxn];
namespace dhcio{
	inline int read(){
		char ch=getchar();int ret=0,f=1;
		while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
		while(ch>='0'&&ch<='9') ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
		return ret*f;
	}
	inline void write(int x){
		if(x<0) x=-x;
		if(x>9) write(x/10);
		putchar('0'+x%10);
	}
}
using namespace dhcio;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",S+1);n=strlen(S+1);
	for(int i=1;i<=n;i++)
	  if(S[i]>='0'&&S[i]<='9') num[S[i]-'0']++;
	for(int i=9;i>=0;i--)
	while(num[i]--) write(i);
	putchar('\n');
	return 0;
}