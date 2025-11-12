//RP++ 300+ Please!
//8:54 100pts
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
const int maxn=1e6+5;
int n,m,a[maxn];
char s[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++)if(isdigit(s[i]))a[++m]=s[i]-'0';
	sort(1+a,1+a+m,[](int x,int y){return x>y;});
	for(int i=1;i<=m;i++)printf("%d",a[i]);
	return 0;
}