#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int a[1000010],top;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++top]=s[i]-'0';
	sort(a+1,a+top+1);
	for(int i=top;i>=1;i--){
		printf("%d",a[i]);
	}
	return 0;
}
