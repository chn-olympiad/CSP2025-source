#include<iostream>
#include<algorithm>
#define int long long
const int N=5e2+10;
const int M=5e2+10;
const int mod=998244353;
using namespace std;
namespace IO{
	int read(){
		int x=0,f=1;char ch=getchar();
		while(ch<'0'||ch>'9'){
			if(ch=='-')f=-f;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9'){
			x=x*10+ch-'0';
			ch=getchar();
		}return x*f;
	}
	void print(int x){
		if(x<0){
			x=-x;
			putchar('-');
		}
		if(x>9)print(x/10);
		putchar(x%10+'0');
	}
	void put(int x){print(x);putchar('\n');}
}using namespace IO;
int n,m,ans,a[N],c[N],b[N];
char s[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();cin>>(s+1);
	for(int i=1;i<=n;i++)c[i]=read(),a[i]=(s[i]=='1');
	for(int i=1;i<=n;i++)b[i]=i;
	do{
		int sum=0;
		for(int i=1;i<=n;i++)
			if(a[i]==0||sum>=c[b[i]])sum++;
		if(n-sum>=m)ans++;
	}while(next_permutation(b+1,b+n+1));
	print(ans);
	return 0;
}
