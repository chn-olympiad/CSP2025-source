#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e6+5;
int num[15];
char s[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf(" %s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9') num[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++)
			printf("%d",i);
	}
	return 0;
}