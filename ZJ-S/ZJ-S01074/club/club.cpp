#include<bits/stdc++.h>
using namespace std;
const int N=206;
const int M=1e5+5;
#define LL long long
int in(){
	char cc=getchar();
	int aa=0,bb=1;
	while(cc<'0'||cc>'9'){
		if(cc=='-')	bb=-1;
		cc=getchar();
	}
	while(cc>='0'&&cc<='9'){
		aa=aa*10+cc-'0';
		cc=getchar();
	}
	return aa*bb;
}
void out(LL aa){
	if(aa<0){
		aa=-aa;
		putchar('-');
	}
	if(aa<=9)	putchar(aa+'0');
	else{
		out(aa/10);
		putchar(aa%10+'0');
	}
	return ;
}
struct S{
	int a,b,c;
}p[M];
bool cmp(S x1,S x2){
	return x1.a>x2.a;
}
LL maxn(LL x1,LL x2,LL x3){
	return max(x1,max(x2,x3));
}
LL dp[N][N][N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=in(),n;
	while(t--){
		n=in();
		if(n<=200){
			LL ans=-999;
			for(int i=1;i<=n;i++){
				p[i].a=in();
				p[i].b=in();
				p[i].c=in();
			}
			for(int a=0;a<=n/2;a++){
				for(int b=0;b<=n/2;b++){
					for(int c=0;c<=n/2;c++){
					if(a==0&&b==0&&c==0)	continue;
					if(a+b+c>n)	continue;
					if(a<=n/2&&b<=n/2&&c<=n/2){
						if(a==0&b==0)	dp[a][b][c]=dp[a][b][c-1]+p[a+b+c].c;
						else if(a==0&&c==0)	dp[a][b][c]=dp[a][b-1][c]+p[a+b+c].b;
						else if(b==0&&c==0)	dp[a][b][c]=dp[a-1][b][c]+p[a+b+c].a;
						else if(a==0){
							dp[a][b][c]=max(dp[a][b-1][c]+p[a+b+c].b,
							dp[a][b][c-1]+p[a+b+c].c);
						}
						else if(b==0){
							dp[a][b][c]=max(dp[a-1][b][c]+p[a+b+c].a,
							dp[a][b][c-1]+p[a+b+c].c);
						}
						else if(c==0){
							dp[a][b][c]=max(dp[a-1][b][c]+p[a+b+c].a,
							dp[a][b-1][c]+p[a+b+c].b);		
						}
						else{
							dp[a][b][c]=maxn(
								dp[a-1][b][c]+p[a+b+c].a,
								dp[a][b-1][c]+p[a+b+c].b,
								dp[a][b][c-1]+p[a+b+c].c);
						}
							if(a+b+c==n)	ans=max(ans,dp[a][b][c]);
						}
					}
				}
			}
			out(ans);
			putchar('\n');
		}
		else{
			LL ans=0;
			for(int i=1;i<=n;i++){
				p[i].a=in();
				p[i].b=in();
				p[i].c=in();
			}
			sort(p+1,p+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=p[i].a;
			}
			out(ans);
			putchar('\n');
		}
	}
}
/*
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
