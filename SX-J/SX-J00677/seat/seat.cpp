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
		if (c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
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
int n,m;
int a[110];
int Score;
int c,r;
void SearchAns(int x){
	int cnt=1;
	const int N=2*n;
	for(int i=1;i<=n;i++){
		if((x-cnt)%N==0){
			r=i,c=((x-cnt)/N)*2+1;
			return;
		}
		cnt++;
	}
	//(x&1)==0
	for(int i=n;i>=1;i++){
		if((x-cnt)%N==0){
			r=i,c=((x-cnt)/N)*2+2;
			return;
		}
		cnt++;
	}
	//(x&1)==1
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++) a[i]=read();
	Score=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int pos=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==Score){
			pos=i;
			break;
		}
	}
	SearchAns(pos);
	write(c);qwe;write(r);
	return 0;
}
