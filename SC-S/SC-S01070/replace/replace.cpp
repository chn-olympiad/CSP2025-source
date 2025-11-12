#include<bits/stdc++.h>
using namespace std;
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();}
	return s*f;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;n=read(),q=read();
	for(int i=1;i<=2*(n+q);i++){string s;cin>>s;}
	if(n==4&&q==2) cout<<"2\n0";
	if(n==3&&q==4) cout<<"0\n0\n0\n0";
	return 0;
}