#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
char s[maxn];
int n,cnt[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	for(int i=1;s[i];i++)if(s[i]>='0'&&s[i]<='9')cnt[s[i]-'0']++;
	for(int i=9;i>=0;i--)for(int j=1;j<=cnt[i];j++)putchar(i+'0');
	return 0;
}

