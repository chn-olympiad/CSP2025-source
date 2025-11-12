#include<iostream>
#include<algorithm>
#define int long long
const int N=1e5+10;
using namespace std;
namespace IO{
	int read(){
		int x=0,f=1;char ch=getchar();
		while(ch<'0'||ch>'9'){
			if(ch=='-')f=-f;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9'){
			x=x*10+ch-'0';
			ch=getchar();
		}return x*f;
	}
	void print(int x){
		if(x<0){
			x=-x;
			putchar('-');
		}
		if(x>9)print(x/10);
		putchar(x%10+'0');
	}
	void put(int x){print(x);putchar('\n');}
}using namespace IO;
int T,n,ans,s[3],dif[N];
struct Node{int op,x[3];}a[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();ans=s[0]=s[1]=s[2]=0;
		for(int i=1;i<=n;i++)
			a[i].x[0]=read(),a[i].x[1]=read(),a[i].x[2]=read();
		for(int i=1;i<=n;i++){
			int sum=max(max(a[i].x[0],a[i].x[1]),a[i].x[2]);
			if(a[i].x[0]==sum)a[i].op=0,s[0]++;
			else if(a[i].x[1]==sum)a[i].op=1,s[1]++;
			else a[i].op=2,s[2]++;
			ans+=a[i].x[a[i].op];
		}
		int sum=max(max(s[0],s[1]),s[2]);
		if(sum<=(n>>1))put(ans);
		else{
			int m=sum-(n>>1),cnt=0,k=0;
			if(s[0]==sum)k=0;
			else if(s[1]==sum)k=1;
			else k=2;
			for(int i=1;i<=n;i++)
				if(a[i].op==k)
					dif[++cnt]=a[i].x[k]-max(a[i].x[(k+1)%3],a[i].x[(k+2)%3]);
			sort(dif+1,dif+cnt+1);
			for(int i=1;i<=m;i++)ans-=dif[i];
			put(ans);
		}
	}
	return 0;
}
