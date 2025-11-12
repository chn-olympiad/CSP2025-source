#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int b[1000005],cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a+1);
	int n=strlen(a+1);
	for(int i=1;i<=n;i++){
		if('0'<=a[i]&&a[i]<='9') b[++cnt]=a[i]-'0';
	}
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<=cnt;i++) putchar(b[i]+'0');
	return 0;
}
