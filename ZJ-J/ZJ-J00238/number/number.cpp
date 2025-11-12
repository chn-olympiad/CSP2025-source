#include<bits/stdc++.h>
#define ci const int
#define ri register int
using namespace std;
ci N=1e6+5;
char ch;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(~(ch=getchar())){
		if('0'<=ch&&ch<='9') a[ch-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(a[i]--){
			putchar(i+'0');
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}