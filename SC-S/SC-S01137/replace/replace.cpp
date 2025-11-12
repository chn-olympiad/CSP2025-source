#include<bits/stdc++.h>
#define ull unsigned long long
#define pb push_back
#define pii pair<int,int>
#define mk mape_pair
using namespace std;
const int N=2e5+5,mx=5e6+5;
const ull md=1e9+7;
char s1[mx],s2[mx],t1[mx],t2[mx];
int n,q,ans,l[N];
ull hx[mx],hxp[N][2],hxto,pw[mx];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		ret=(ret<<3)+(ret<<1)+ch-'0';
		ch=getchar();
	}
	return ret*f;
}
void print(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>=10) print(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	pw[0]=1;
	for(int i=1;i<mx;i++) pw[i]=pw[i-1]*13331;
	for(int i=1;i<=n;i++){
		scanf("%s",s1+1);scanf("%s",s2+1);
		l[i]=strlen(s1+1);
		for(int j=1;j<=l[i];j++){
			hxp[i][0]=hxp[i][0]*13331+(ull)s1[j];
			hxp[i][1]=hxp[i][1]*13331+(ull)s2[j];
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%s",t1+1);scanf("%s",t2+1);
		int len=strlen(t1+1);
		for(int j=1;j<=len;j++){
			hxto=hxto*13331+(ull)t2[j];
			hx[j]=hx[j-1]*13331+(ull)t1[j];
		}
		for(int j=1;j<=len;j++)
			for(int k=1;k<=n;k++){
				if(j<l[k]) continue;
				if(hx[j]-hx[j-l[k]]*pw[l[k]]==hxp[k][0])
					ans+=((hx[j-l[k]]*pw[len-j+l[k]]+hxp[k][1]*pw[len-j]+hx[len]-hx[j]*pw[len-j])==hxto);
			}
		print(ans);putchar('\n');ans=0;
		hxto=0;
		for(int j=1;j<=len;j++) hx[j]=0;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
abc cdc
*/