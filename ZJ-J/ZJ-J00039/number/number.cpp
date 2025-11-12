#include<bits/stdc++.h>
using namespace std;
int a[1000005],n;
char s[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	for(int i=0;s[i];i++)if(isdigit(s[i]))a[++n]=s[i];
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++)putchar(a[i]);
	return 0;
}