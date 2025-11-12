#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#define _for(i,a,b) for(int i=(a);i<=(b);i++)
#define _rof(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline int read(){
	int f=1,num=0;
	char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	return f*num;
}
int n,m,p[20],c[20];
const int mod=998244353;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n=read(),m=read();
	cin>>s;s=' '+s;
	_for(i,1,n) c[i]=read(),p[i]=i;
	int res=0;
	do{
		int cnt0=0,cnt1=0;
		_for(i,1,n){
			if(c[p[i]]<=cnt0 || s[i]-'0'==0) cnt0++;
			else cnt1++;
		}
		if(cnt1>=m) res++;
	}while(next_permutation(p+1,p+n+1));
	printf("%d\n",res);
	return 0;
}
//i love ccf
