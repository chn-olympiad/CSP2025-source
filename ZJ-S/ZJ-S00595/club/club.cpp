#include<bits/stdc++.h>
using namespace std;
#define rep1(i,x,y) for(int i=(x);i<=(y);++i)
#define rep2(i,x,y) for(int i=(x);i>=(y);--i)
#define sp putchar(' ')
#define ln putchar('\n')
//#define int long long
int read(){
	int x=0;
	char c=getchar();
	bool p=0;
	while(c<'0'||c>'9'){
		p=(c=='-'?1:p);
		c=getchar();
	}while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}return (p?~(x-1):x);
}void write(int x){
	if(x<0){
		putchar('-');
		x=~(x-1);
	}if(x>9)write(x/10);
	putchar(x%10|48);
}struct node{
	int s,x,y;
	bool operator<(const node&t)const{return s>t.s;}
}c[300010];
int n,a[100010][3],dp[210][110][110],b[100010];
bool p[100010];
void solve(){
	n=read();
	bool fl=1;
	rep1(i,1,n)
		rep1(j,1,3){
			a[i][j]=read();
			if((j==2||j==3)&&a[i][j])fl=0;
		}
	if(fl){
		rep1(i,1,n)b[i]=a[i][1];
		sort(b+1,b+n+1);
		int sum=0;
		rep2(i,n,(n>>1)+1)sum+=b[i];
		write(sum);ln;
		return;
	}if(n>200){
		rep1(i,1,n)
			rep1(j,1,3)c[(i-1)*3+j]={a[i][j],i,j};
		sort(c+1,c+n*3+1);
		int ss[4]={0,0,0,0},sum=0;
		rep1(i,1,n)p[i]=0;
		rep1(i,1,n*3)
			if(!p[c[i].x]&&ss[c[i].y]<(n>>1)){
				p[c[i].x]=1;
				sum+=c[i].s;
				ss[c[i].y]++;
			}
		write(sum);ln;
		return;
	}rep1(i,1,n)
		rep1(j1,0,min(n>>1,i))
			rep2(j2,min(n>>1,i-j1),0){
				int j3=i-j1-j2;
//				write(i);sp;write(j1);sp;write(j2);sp;
				if(j3>(n>>1)){break;}
				if(j1)dp[i][j1][j2]=dp[i-1][j1-1][j2]+a[i][1];
				else dp[i][j1][j2]=0;
				if(j2)dp[i][j1][j2]=max(dp[i][j1][j2],dp[i-1][j1][j2-1]+a[i][2]);
				if(j3)dp[i][j1][j2]=max(dp[i][j1][j2],dp[i-1][j1][j2]+a[i][3]);
//				write(dp[i][j1][j2]);ln;
			}
	int maxn=-1;
	rep1(j1,0,n>>1)
		rep1(j2,0,n>>1)maxn=max(maxn,dp[n][j1][j2]);
	write(maxn);ln;
}signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int ttt=read();
	while(ttt--)solve();
	return 0;
}/*
期望 AC :1~12,15~16
期望得分:70pts
保守得分:60pts
aaaaaaaaa 不会写特殊性质B aaaaaaaaa
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
