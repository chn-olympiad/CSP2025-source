#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
char s[maxn];
char ans[maxn];
int n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number0.out","w",stdout);
	scanf("%s",s+1);
	for(int i=1;s[i];i++)if(s[i]>='0'&&s[i]<='9')ans[++n]=s[i];
	sort(ans+1,ans+n+1,greater<int>());
	for(int i=1;i<=n;i++)putchar(ans[i]);
	return 0;
}

