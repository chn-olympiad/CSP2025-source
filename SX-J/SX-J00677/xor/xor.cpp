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
const int N=5e5+10;
struct Node{
	int st,ed;
}node[N];
int tot;
bool cmp(Node a,Node b){
	if(a.ed!=b.ed) return a.ed<b.ed;
	return a.st<b.st;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n=read(),k=read();
	vi a(n+5);
	int ans=0;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		int Xor=a[i],t=1;
		while(Xor!=k&&t+i<=n){
			Xor^=a[t+i];
			t++;
		}
		t--;
		if(Xor==k){
			node[tot].st=i,node[tot].ed=i+t;
			tot++;
		}
	}
	sort(node,node+tot,cmp);
//	for(int i=0;i<tot;i++){
//		cout<<node[i].st<<' '<<node[i].ed<<endl;
//	}
	int last_ed=0;
	for(int i=0;i<tot;i++){
		if(node[i].st>last_ed){
			ans++;
			last_ed=node[i].ed;
		}
	}
	write(ans);
	return 0;
}
