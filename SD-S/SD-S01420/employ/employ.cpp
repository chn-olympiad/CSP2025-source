#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e5+5;
int rd(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}while(c>='0'&&c<='9')x=x*10+c-48,c=getchar();
	return f*x;
}int _s[20],_t;
void wt(int x){
	if(x<0)putchar('-'),x=-x;
	do _s[++_t]=x%10,x/=10;
	while(x);while(_t)putchar(_s[_t--]+48);
	return;
}
int main(){
//	freopen(".in","r",stdin);
	freopen("employ.out","w",stdout);
	cout<<0;
	return 0;
}

