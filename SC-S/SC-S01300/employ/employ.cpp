#include<bits/stdc++.h>
#define int long long
#define mp(a,b) make_pair(a,b)
using namespace std;

inline int read(){
	int a=0,b=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	b=-1;
		c=getchar(); 
	}
	while(isdigit(c)){
		a=(a<<1)+(a<<3)+(c-'0');
		c=getchar();
	}
	return a*b;
}
inline void write(int x){
	if(x<0)	putchar('-'),x=-x;
	if(x>=10)	write(x/10);
	putchar(x%10+48);
}
inline void write1(int x){
	write(x),putchar(' ');
}
inline void write2(int x){
	write(x),putchar('\n');
}
const int N=5*114514,M=20,R=500;
const int mod=998244353;
int n,m;
char s[N]; 
int c[N];
int dp[N][M];
int popcnt(int x){
	if(x<=1)	return x;
	return popcnt(x/2)+(x%2);
}
void sol1(){
	dp[0][0]=1;	//代表状态为 0 失败人数为 0 时的情况：有一种  
	for(int i=0;i<(1<<n);i++){
		//目前状态为 i 
		int now=popcnt(i);
		for(int j=0;j<=n;j++){
			for(int k=0;k<n;k++){
				//已经走到了 i 位 j 的人数 下一步走 k 
				if(i&(1<<k))	continue;	//这儿不好 
				if(j>=c[k]||s[now]=='0'){
					dp[i|(1<<k)][j+1]+=dp[i][j];
					dp[i|(1<<k)][j+1]%=mod;
				} 
				else{
					dp[i|(1<<k)][j]+=dp[i][j];
					dp[i|(1<<k)][j]%=mod;
				}
			}
//			cout<<'!'<<i<<' '<<j<<' '<<dp[i][j]<<endl;
		} 
//		cout<<endl;
	}
	int include13=0;
	for(int i=0;i<=n-m;i++){
		include13+=dp[(1<<n)-1][i];
		include13%=mod;
	}
	write2(include13);
	return;
}
#undef int
int main(){
	#define int long long
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	int JC=1;
	for(int i=1;i<=n;i++){
		JC=JC*i%mod; 
	}
	int flag=1;
	for(int i=0;i<n;i++){
		s[i]=getchar();
		while(!isdigit(s[i]))	s[i]=getchar();
		if(s[i]=='0')	flag=0;
	}
	for(int i=0;i<n;i++){
		c[i]=read();
		if(c[i]==0)	flag=0;
	}
	//判断数据类型 
	//第一种 n<=18 跑状压 
	if(n<=18){
		sol1(); 
		return 0;
	}	
//	else 
	if(flag==0){
		write2(0);
		return 0;
	}
	else{
		write2(JC);
		return 0;
	}
} //CSP-S 2025 RP++ 