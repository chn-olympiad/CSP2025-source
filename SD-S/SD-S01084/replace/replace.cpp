#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &n);
int main(){
	//ios::sync_with_stdio(0);
	freopen("debug.in","r",stdin);
	//freopen(".out","w",stdout);

	return 0;
 }
template<typename T>inline void read(T &n){
	n=0;char c;
	T f=1;
	do{
		c=getchar();
		if (c=='-') f=-1;
	}while (c>'9'||c<'0');
	while (c>='0'&&c<='9'){
		n=(n<<1)+(n<<3)+(c^48);
		c=getchar();
	}
	n*=f;
}

