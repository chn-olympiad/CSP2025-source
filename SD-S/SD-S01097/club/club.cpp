#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char ch=getchar();
	int x=0;
	while(ch>'9'||ch<'0')ch=getchar();
	while('0'<=ch&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}inline void write(int x){
	if(!x)return putchar('0'),void();
	char ch[40];int cnt=0;
	while(x)ch[++cnt]=x%10^48,x/=10;
	while(cnt)putchar(ch[cnt--]);
}int a[100005][3];
int choice[100005];
int b[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		int n=read();
		for(int i=1; i<=n; i++)a[i][0]=read(),a[i][1]=read(),a[i][2]=read();
		
		long long res=0;
		int cnt[3];cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1; i<=n; i++){
			int tmp=max(a[i][0],max(a[i][1],a[i][2]));
			res+=tmp;
			if(tmp==a[i][0])cnt[0]++,choice[i]=0;
			else if(tmp==a[i][1])cnt[1]++,choice[i]=1;
			else cnt[2]++,choice[i]=2;
		}
		int op=3;
		for(int i=0; i<=2; i++)if(cnt[i]>(n/2))op=i;
		if(op==3)printf("%lld\n",res);
		else{
			b[0]=0;
			
			for(int i=1; i<=n; i++){
				if(choice[i]==op){
					b[++b[0]]=0;
					for(int j=0; j<=2; j++){
						if(j!=op)b[b[0]]=max(b[b[0]],a[i][j]);
					}
					b[b[0]]=-b[b[0]]+a[i][op];
				}
			}sort(b+1,b+1+b[0]);
//			cout<<cnt[op]<<endl;
			for(int i=1; i<=cnt[op]-(n/2); i++){
				res-=b[i];
			}printf("%lld\n",res);
		}
	}
	return 0;
}/*

*/ 

