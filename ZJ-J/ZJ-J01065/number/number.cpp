#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int num[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	//cout<<s;
	int len=strlen(s);
	for(int i=0; i<len; i++){
		if(s[i]>='0'&&s[i]<='9') num[s[i]-'0']++;
	}
	for(int i=9; i>=0; i--){
		while(num[i]) printf("%d",i), num[i]--;
	}
	return 0;
}
//290es1q0