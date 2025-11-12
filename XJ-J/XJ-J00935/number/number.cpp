#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e6+10;
int a[N],p=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c;
	c = getchar();
	while ((c <= '9' && c >= '0') || (c >= 'a' && c <= 'z')){
		if (c <= '9' && c >= '0'){
			a[++p] = c-'0';
		}
		c = getchar();
	}
	sort(a+1,a+p+1,greater<int>());
	for (int i=1;i<=p;i++){
		c = a[i]+'0';
		putchar(c);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
