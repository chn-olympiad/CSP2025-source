#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int n=0,cnt=0,a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=-(s[i]-'0');
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=1;i<=cnt;i++){
		printf("%d",-a[i]);
	}
	return 0;
}
//AC!!!
