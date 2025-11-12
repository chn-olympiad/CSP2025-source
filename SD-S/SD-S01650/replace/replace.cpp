#include<algorithm>
#include<iostream>
#include<cstring>
#include<bitset>
#include<cstdio>
#include<string>
#define INF 0x3f3f3f3f
using namespace std;
#ifdef __linux__
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif
inline bool blank(const char x){
	return !(x^32)||!(x^10)||!(x^13)||!(x^9);
}
template<typename Tp>
inline void read(Tp &x){
	x=0;
	bool f=1;
	char ch=gc();
	for(;ch<'0'||'9'<ch;ch=gc())
		if(ch=='-') f=0;
	for(;'0'<=ch&&ch<='9';ch=gc())
		x=(x<<1)+(x<<3)+(ch^48);
	x=(f?x:~x+1);
}
inline void read(char &x){
	for(;blank(x)&&(x^-1);x=gc());
}
inline void read(char *x){
	char ch=gc();
	for(;blank(ch)&&(ch^-1);ch=gc());
	for(;!blank(ch)&&(ch^-1);ch=gc())
		*x++=ch;
	*x=0;
}
inline void read(string &x){
	x="";
	char ch=gc();
	for(;blank(ch)&&(ch^-1);ch=gc());
	for(;!blank(ch)&&(ch^-1);ch=gc())
		x+=ch;
}
template<typename T,typename ...Tp>
inline void read(T &x,Tp &...y){
	read(x),read(y...);
}
const int N=2e5+010;
int n,q,ans;
string str1[N],str2[N];
int str3[N],str4[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n,q);
	for(int i=1;i<=n;i++){
		read(str1[i],str2[i]);
		str3[i]=str1[i].find('b'),str4[i]=str2[i].find('b');
	}
	for(int i=1;i<=q;i++){
		ans=0;
		string s1,s2;
		read(s1,s2);
		if(s1.length()!=s2.length()) printf("0\n");
		else{
			if(n<=100&&q<=100){
				for(int j=1;j<=n;j++){
					int x=s1.find(str1[i]);
					int y=s2.find(str2[i]);
					while(x!=-1&&y!=-1){
						if(x==y) ans++;
						else if(x<y) x=s1.find(str1[i],x);
						else y=s2.find(str2[i],y);
					}
				}
				printf("%d\n",ans);
			}
			else if(n<=10000&&q<=10000){
				int s3=s1.find('b'),s4=s2.find('b');
				for(int i=1;i<=n;i++){
					if(str3[i]>=s3&&str1[i].length()-str3[i]<s1.length()-s3&&str4[i]>=s4&&str2[i].length()-str4[i]<s2.length()-s4) ans++;
				}
				printf("%d\n",ans);
			}
			else printf("0\n");
		}
	}
	return 0;
}

