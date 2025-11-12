#include<bits/stdc++.h>
using namespace std;
const int S=1e6+5;
char c[S];int cnt[10],l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",c);
	l=strlen(c);
	for(int i=0;i<l;i++)
		if(c[i]>='0'&&c[i]<='9')
			cnt[c[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=0;j<cnt[i];j++)
			printf("%d",i);
	return 0;
}