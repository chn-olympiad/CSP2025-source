#include<bits/stdc++.h>
using namespace std;
int cnt,a[1000005];
char s[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	for(int i=0;i<strlen(s);i++)
		if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-'0'; 
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++) printf("%d",a[i]);
	return 0;
}
