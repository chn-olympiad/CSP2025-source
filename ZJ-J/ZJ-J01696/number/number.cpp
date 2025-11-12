#include<bits/stdc++.h>
using namespace std;
int a[10];
char c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(scanf("%c",&c)){
		if(c<='9'&&c>='0')++a[c-'0'];
		else if(c>'z'||c<'a')break;
	}
	for(int i=9;i>=0;i--)while(a[i]--)printf("%d",i);
}
