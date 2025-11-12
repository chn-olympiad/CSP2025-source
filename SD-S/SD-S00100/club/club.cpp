#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*f;
}
struct node{
	int maxn,max2,id,id2;
	ll der;
}c[N];
struct node2{
	int maxn,max2;
	ll der;
}b[N];
int n,hf;
int a[N][4],num[4];
bool cmp(node2 aa,node2 bb){
	return aa.der<bb.der;
}
ll solve(int now){
	ll ans=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		ans+=c[i].maxn;
		if(c[i].id==now) b[++cnt].maxn=c[i].maxn,b[cnt].max2=c[i].max2,b[cnt].der=c[i].der;
	}
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<=cnt-hf;i++){
		ans-=b[i].der;
	}
	return ans;
}
void init(){
	memset(b,0,sizeof b);
	memset(num,0,sizeof num);
	memset(c,0,sizeof c);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		init();
		n=read();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j]=read();
				if(c[i].maxn<=a[i][j]){
					c[i].max2=c[i].maxn,c[i].id2=c[i].id;
					c[i].maxn=a[i][j],c[i].id=j;
				}else if(c[i].max2<=a[i][j]){
					c[i].max2=a[i][j],c[i].id2=j;
				}
			}
			c[i].der=c[i].maxn-c[i].max2;
		}
		for(int i=1;i<=n;i++) num[c[i].id]++;
		hf=n/2;
		if(num[1]>hf){
			cout<<solve(1)<<"\n";
		}else if(num[2]>hf){
			cout<<solve(2)<<"\n";
		}else if(num[3]>hf){
			cout<<solve(3)<<"\n";
		}else{
			ll tmp=0;
			for(int i=1;i<=n;i++) tmp+=c[i].maxn;
			cout<<tmp<<"\n";
		}
	}
	return 0;
}
