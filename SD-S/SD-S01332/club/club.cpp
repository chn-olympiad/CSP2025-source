#include<bits/stdc++.h>
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout); 
using namespace std;
typedef long long ll;
namespace FastIO{
	template<typename T=int>T read(){
		T x=0;int f=1;char c=getchar();
		while(!isdigit(c)){if(c=='-') f=~f+1;c=getchar();};
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		return x*f;
	}
	template<typename T>void write(T x){
		if(x<0) putchar('-'),x=~x+1;
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
	template<typename T>void Write(T x,char c='\n'){
		write(x),putchar(c);
	}
}
using namespace FastIO;
const int maxn=1e5+5;
int a[maxn][4],c[maxn],cnt[3];
void Yorushika(){
	int n=read();ll ans=0;
	cnt[0]=cnt[1]=cnt[2]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++) a[i][j]=read();
		int p=3;
		for(int j=0;j<3;j++) if(a[i][j]>a[i][p]) p=j;
		cnt[p]++,c[i]=p;
		ans+=a[i][p];
	}
	int OK=3;
	for(int i=0;i<3;i++)
		if(cnt[i]>n/2) OK=i;
	if(OK!=3){
		vector<int>res;
		for(int i=1;i<=n;i++){
			if(c[i]==OK){
				int w=0;
				for(int j=0;j<3;j++)
					if(j!=c[i]) w=max(w,a[i][j]);
				res.push_back(a[i][c[i]]-w);
			}
		}
		sort(res.begin(),res.end());
		int T=cnt[OK]-n/2;
		for(int i=0;i<T;i++) ans-=res[i];
	}
	Write(ans);
}
int main(){
	file("club");
	int Tc=read();
	while(Tc--) Yorushika();
	return 0;
}
