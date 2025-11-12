#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)) f=(ch=='-'?-f:f),ch=getchar();
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int a[1000005],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char ch=getchar();
	while(ch!=EOF){
		if(isdigit(ch)) a[++cnt]=ch-'0';
		ch=getchar();
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i;i--) printf("%d",a[i]);
	return 0;
}