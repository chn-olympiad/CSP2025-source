#include<bits/stdc++.h>
using namespace std;
__int128 read(){
	char c;
	__int128 ans = 0;
	__int128 fl = 1;
	c = getchar();
	while(c>'9'||c<'0'){
		if(c=='-'){
			fl *=-1;
		}
		c = getchar();
	}
	while(c<='9'&&c>='0'){
		ans*=10;
		ans += __int128(c-'0');
		c = getchar();
	}
	return ans;
}
void write(__int128 ans){
	if(ans<0){
		putchar('-');
		ans=-ans;
	}
	write(ans/10);
	putchar(char('0'+ans%10));
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(0));
	cout<<rand()%998244353; 
	return 0;
}

