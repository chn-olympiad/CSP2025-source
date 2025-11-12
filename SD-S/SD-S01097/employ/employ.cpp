#include<bits/stdc++.h>
#define mod 998244353
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
}
char ch[505];
int c[505];
long long f[20][1<<18];
vector<int>vec[20];
inline int lowbit(int x){return x&-x;}
inline int popcnt(int x){
	int cnt=0;
	while(x){
		cnt++;
		x-=lowbit(x);
	}return cnt;
}
int sum[1005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n=read(),m=read(); 
	scanf("%s",ch+1);
	for(int i=1; i<=n; i++)c[i]=read(),sum[c[i]]++;
	for(int i=1; i<=n; i++)sum[i]+=sum[i-1];
	bool ok=1;
	for(int i=1; i<=n; i++){
		ok&=(ch[i]=='1');
	}if(ok){
		long long res=1;
		for(int i=1; i<=n; i++)res=res*1ll*i%mod;
		cout<<res;
	}else if(m==1){
		int cnt=0;
		long long ans=0;
		for(int i=1; i<=n; i++){
			if(ch[i]=='1'){
				long long res=1;
				long long ct=sum[n]-sum[i-1];
				for(int j=1; j<i; j++){
					res=res*(sum[j-1]-j+1)%mod;
					if(sum[j-1]-j+1<=0)res=0;
				}
				for(int j=n-i; j>=1; j--)res=res*j%mod;
				res=res*ct%mod;
				ans=(ans+res)%mod;
			}
		}
		cout<<ans;
	}
	else if(m==n){
		printf("0");
	}else if(n<=18){
		for(int i=0; i<(1<<18); i++){
			vec[popcnt(i)].push_back(i);
		}
		f[0][0]=1;
//		cout<<114<<endl;
		for(int d=1; d<=n; d++){
			bool op=(ch[d]=='1');
			for(int j=0; j<vec[d].size(); j++){
				int S=vec[d][j];
				for(int k=0; k<n; k++){
					if((S>>k)&1){
						for(int l=0; l<n; l++){
							if(l>=c[k+1]){
								f[l+1][S]=(f[l][S^(1<<k)]+f[l+1][S])%mod;
							}else{
								if(!op)f[l+1][S]=(f[l][S^(1<<k)]+f[l+1][S])%mod;
								else f[l][S]=(f[l][S^(1<<k)]+f[l][S])%mod;
							}
						}
					}
				}
			}
		}long long res=0;
		for(int i=0; i<=n-m; i++)res=(res+f[i][(1<<n)-1])%mod;
		cout<<res;
	}
	return 0;
}/*
有点绷不住

感觉今天本来开局很好，结果自己糖丸了

A秒了

B秒了，忽然发现复杂度假了，然后1e-9秒想到了正解，但是因为犯了堂错，一度以为自己写错了，最后1h才发现问题

C写了一坨，以为自己被卡哈希了，结果发现是长度超过了

D写了24就滚了

100+100+[50,100]+24 =[274,324] 
*/

