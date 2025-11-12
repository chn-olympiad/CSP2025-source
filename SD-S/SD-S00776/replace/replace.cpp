#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
namespace abc_{

int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
void print(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) print(x/10);
	putchar('0'+x%10);
	return ;
}

int my_main(){
	
	return 0;
}

}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	abc_::my_main();
	return 0;
}
