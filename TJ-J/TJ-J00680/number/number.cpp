#include<bits/stdc++.h>
using namespace std;
char s[1000001];
int i,t,ans[1000001];
bool cmp(int,int);
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(scanf("%c",&s[++i])==1){
		if(s[i]>='0'&&s[i]<='9'){
			ans[++t]=s[i]-48;
		}
	}
	sort(ans+1,ans+1+t,cmp);
	for(int i=1;i<=t;i++){
		printf("%d",ans[i]);
	}
	return 0;
}
bool cmp(int a,int b) {
	return a>b;
}

