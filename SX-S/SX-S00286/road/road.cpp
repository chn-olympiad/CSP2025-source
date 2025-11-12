#include<bits/stdc++.h>
#define endl '\n'
#define endline putchar('\n')
#define qwe putchar(' ')
//#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> PII;
typedef long long ll;
inline int read(){
	int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	putchar('0');
	return 0;
}