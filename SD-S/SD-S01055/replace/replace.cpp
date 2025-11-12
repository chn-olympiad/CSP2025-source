#include <bits/stdc++.h>
#define For(i,x,y) for(int (i)=(x);(i)<=(y);(i)++)
using namespace std;
typedef unsigned long long ll;
const int N=2e5+5,P=1331;
int n,q;
string s1[N],s2[N];
ll h1[N],h2[N],len[N];
int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}
void write(ll x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	For(i,1,n) cin>>s1[i]>>s2[i];
	For(i,1,q){
		string x,y;
		cin>>x>>y;
		int ans=0;
		For(k,1,n){
			For(j,0,x.length()-1){
				string z=x;
				int flag=1;
				For(l,0,s1[k].length()-1){
					if(x[j+l]==s1[k][l]) z[j+l]=s2[k][l];
					else{
						flag=0;
						break;
					}
				}
				if(z==y&&flag) ans++;
			}
		}
		write(ans);
		putchar(10);
	}
	return 0;
}
