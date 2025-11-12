//RP++ 1= Please!
//50pts
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
const int maxn=2e5+5;
int n,Q,ans;
struct node{
	string x,y;
	int l;
}a[maxn];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=(ret<<1)+(ret<<3)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),Q=read();
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y,a[i].l=a[i].x.size();//Is this right?I forget how to use cin and cout.
	while(Q--){
		string s1,s2;
		cin>>s1>>s2;ans=0;
		int l1=s1.size(),l2=s2.size(),flg=0;
		if(l1!=l2){printf("%d\n",ans);continue;}
		for(int i=0;i<l1;i++)flg+=(s1[i]!=s2[i]);
		for(int i=1;i<=n;i++)for(int j=0;j<l1;j++){
			if(j+a[i].l>l1)break;
			int now=1;
			for(int k=0;k<a[i].l;k++)if(s1[j+k]!=a[i].x[k]||s2[j+k]!=a[i].y[k]){now=0;break;}
			if(now&&flg<=a[i].l)ans++;		
		}
		printf("%d\n",ans);
	}
	return 0;
}