#include<bits/stdc++.h>
#define ll long long
using namespace std;
char c;
int ans[12];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while((scanf("%c",&c))!=EOF)
		if(c>='0'&&c<='9')
			++ans[c-'0'];
	for(int i=9;i>=0;--i){
		for(int j=1;j<=ans[i];++j)
			putchar(i+'0');
	}
	return 0;
}
