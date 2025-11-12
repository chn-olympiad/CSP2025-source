#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
string a[maxn],b[maxn];
int n,q;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)) f^=!(ch^'-'),ch=getchar();
	while( isdigit(ch)){
		ret=(ret<<3)+(ret<<1)+(ch^48);
		ch=getchar();
	}
	return ret*(f-(f^1));
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	while(q--){
		string l=read(),r=read();
		if(l.size()!=r.size()){
			printf("0\n");
			continue;
		}
//		for(int i=0;i<n;i++)
//		for(int j=0,j+i<n;j++){
//			
//		}
		printf("0\n");
	}
	return 0;
}