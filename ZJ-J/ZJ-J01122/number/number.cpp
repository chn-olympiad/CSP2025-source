#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

int n,t[20];
char s[N];

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a=getchar();
	while(a==' '||a=='\n')a=getchar();
	while(a!=' '&&a!='\n'){
		t[a-'0']++;
		a=getchar();
	}
	bool flag=false;
	for(int i=9;i>0;i--){
		while(t[i]--){
			printf("%d",i);
			flag=true;
		}
	}
	if(!flag)cout<<'0';
	else while(t[0]--)printf("0");
	
	return 0;
}
//feropen("number.in","r",stdin);
//feropen("number.out","w",stdout);
//freopen("number.in","r",stdout);
//freopen("number.out","w",stdin);
//QwQ
//
//
