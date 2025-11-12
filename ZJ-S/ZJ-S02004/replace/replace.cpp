#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=2e5+5;
int n,q,pre[N],len[N],yi[N],i,j;
int pret,lent,pres,prett,panb;
string s,ss,t,tt;
map<int,int,int>a;
int read(){
	int op=1,x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')op=-1;
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	return op*x;
}
void out(int x){
	if(x<0){
		x=-x;cout<<"-";
	}
	if(x>=10){
		out(x/10);
	}
		cout<<x%10;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();panb=0;
	for(i=1;i<=n;i++){
		cin>>s>>ss;
		int pan=0,yuan=0,yuanss=0;
		len[i]=s.length();
		for(j=0;j<s.length();j++){
			if(s[j]!='a'&&s[j]!='b'&&ss[j]!='a'&&ss[j]!='b')panb=1;
			if(s[j]=='b')pre[i]=j;
			if(ss[j]=='b')pres=j;
		}
		yi[i]=pres-pre[i];
	}
	for(i=1;i<=q;i++){
		cin>>t>>tt;
		int pan=0,yuan=0,yuanss=0,ans=0;
		for(j=0;j<t.length();j++){
			if(t[j]!='a'&&t[j]!='b'&&tt[j]!='a'&&tt[j]!='b')panb=1;
			if(t[j]=='b')pret=j;
			if(tt[j]=='b')prett=j;
		}
		int yit=prett-pret;lent=t.length();
		if(panb)cout<<0<<endl;
		else{
			for(j=1;j<=n;j++){
				if(yit==yi[j]&&pret>=pre[j]&&(lent-pret>=len[j]-pre[j])){
					ans++;
				}
			}
			out(ans);cout<<endl;
		}
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
/*
1 1
aabaa abaaa
aabaa abaaa
*/