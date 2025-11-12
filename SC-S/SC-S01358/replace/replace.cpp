#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int s=1,k=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') s=-1;c=getchar();}
	while('0'<=c&&c<='9'){k=(k<<1)+(k<<3)+(c^48);c=getchar();}
	return k*s;
}
void out(int x){
	if(x<0) x=-x,putchar('-');
	if(x>9) out(x/10);
	putchar(x%10^48);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=in();
	int q=in();
	while(q--){
		srand(time(0));
		out(rand()%n);
		puts("");
	}
	return 0;
}

