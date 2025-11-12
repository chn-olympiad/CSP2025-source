#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int f,a[10];
char c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	c=getchar();
	while(c!=' '&&c!='\n'){
		if('0'<=c&&c<='9') a[c-'0']++;
		c=getchar();
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++) putchar(i+'0'); 
	}
	return 0;
}