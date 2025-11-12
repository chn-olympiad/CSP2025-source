#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
int n,m,i,len1,len,now,tot,j,ans,cnt;
int tri[maxn][30],mi[maxn];
char a[maxn],b[maxn],ch;
const int mb=2;
unsigned int h2[maxn],h[maxn],c[maxn],fut;
struct no{
	int hax,len;
}note[maxn];
unsigned int js(char a[]){
	len=strlen(a+1);
	int i;
	for(i=1;i<=len;i++) h2[i]=(h2[i-1]*mb+a[i]);
	return h2[len];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	while(n--){
		cin>>a+1>>b+1;
		len1=strlen(a+1);now=0;
		for(i=1;i<=len1;i++){
			ch=a[i]-'a';
			if(!tri[now][ch])
				tri[now][ch]=++tot;
			now=tri[now][ch];
		}
		note[now].hax=js(b);note[now].len=strlen(b+1);
	}
	mi[0]=1;
	for(i=1;i<=n;i++)
		mi[i]=mi[i-1]*mb;
	while(m--){
		cin>>a+1>>b+1;
		len=strlen(a+1);
		for(i=1;i<=len;i++) h[i]=h[i-1]*mb+a[i];
		ans=0;
		fut=js(b);
		len1=strlen(a+1);cnt=0;now=0;
		for(i=1;i<=len1;i++,now=0)
			for(j=i;j<=len1;j++){
				ch=a[j]-'a';
				if(!tri[now][ch]) break;
				else now=tri[now][ch];
				if(note[now].len){
					c[++cnt]=((h[i-1]*mi[len-i-1])*mi[min(0,(note[now].len-(j-(i-1)+1)))]+
					note[now].hax*mi[len1-j]+h[len1]-h[j]);
				}
			}
		for(i=1;i<=cnt;i++)
			if(c[i]==fut) ans++;
		cout<<ans<<"\n";
	}
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
