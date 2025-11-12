#include<bits/stdc++.h>
#define int long long
#define signed bool __End;signed
using namespace std;
bool __Begin;
namespace _IO{inline int read(){int f=1,res=0;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){res=res*10+(ch-'0');ch=getchar();}return f*res;}void write(int x){if(x<0){putchar('-');write(-x);}else if(x<=9){putchar(x+'0');}else{write(x/10);putchar(x%10+'0');}return;}}
namespace _Min{int Min(int x,int y){return x<y?x:y;}int Max(int x,int y){return x>y?x:y;}}

using namespace _IO;
using namespace _Min;

int T;
int n,ans;
int b1[2000005],t1;
int b2[2000005],t2;
int b3[2000005],t3;
int b4[2000005],t4;
int a[2000005],b[2000005],c[2000005];
void solve(){
	n=read();
	ans=t1=t2=t3=t4=0;
	for(int i=1;i<=n;i++){
		a[i]=read(),b[i]=read(),c[i]=read();
		if(a[i]>=b[i]&&a[i]>=c[i]){
			t1++,b1[t1]=i;
			ans+=a[i];
		}else if(b[i]>=a[i]&&b[i]>=c[i]){
			t2++,b2[t2]=i;
			ans+=b[i];
		}else if(c[i]>=a[i]&&c[i]>=b[i]){
			t3++,b3[t3]=i;
			ans+=c[i];
		}
	}
	if(t1>n/2){
		for(int i=1;i<=t1;i++){
			t4++,b4[t4]=Min(a[b1[i]]-b[b1[i]],a[b1[i]]-c[b1[i]]);
		}
		sort(b4+1,b4+1+t4);
		for(int i=1;i<=t4-(n/2);i++){
			ans-=b4[i];
		}
	}else if(t2>n/2){
		for(int i=1;i<=t2;i++){
			t4++,b4[t4]=Min(b[b2[i]]-a[b2[i]],b[b2[i]]-c[b2[i]]);
		}
		sort(b4+1,b4+1+t4);
		for(int i=1;i<=t4-(n/2);i++){
			ans-=b4[i];
		}
	}else if(t3>n/2){
		for(int i=1;i<=t3;i++){
			t4++,b4[t4]=Min(c[b3[i]]-a[b3[i]],c[b3[i]]-b[b3[i]]);
		}
		sort(b4+1,b4+1+t4);
		for(int i=1;i<=t4-(n/2);i++){
			ans-=b4[i];
		}
	}
	write(ans),puts("");
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	for(int i=1;i<=T;i++){
		solve();
	}
//	cerr<<(clock())<<"ms "<<(((&__Begin)-(&__End))>>20)<<"MB\n";
	return 0;
}
