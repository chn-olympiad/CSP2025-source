#include <bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int n,a[maxn],len;
char str[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",str+1);
	len=strlen(str+1);
	for(int i=1;i<=len;i++){
		if(str[i]<'0'||str[i]>'9') continue;
		a[++n]=str[i]-'0';
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--) printf("%d",a[i]);
	printf("\n");
	return 0;
}