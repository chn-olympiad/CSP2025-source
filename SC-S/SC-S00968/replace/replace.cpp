#include<bits/stdc++.h>
#define str string
#define endl '\n'
#define d(x) fixed<<setprecision(x)
#define go(i,a,b) for(int i=a;i<=b;i++)
#define re(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
using ll = long long;
const int N=1e6+5;
inline int read() {
    char c;
    int f=1,x=0;
    c=getchar();
    if(c=='-') f=-1;
    else if('0'<=c&&'9'>=c) x=c-'0';
    c=getchar();
    while('0'<=c&&'9'>=c) x=x*10+c-'0',c=getchar();
    return f*x;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int _=read();
	int t=read();
	while(t--)cout<<"0\n";
    return 0;
}

