#include<bits/stdc++.h>
#define N 505
#define M 998244353
using namespace std;
int n,m,c[N],p[N],ans;
char ch[N];
long long jc[N],dp[N];
int check(){
	for(int i=1;i<=n;i++)if(c[i]=='0')return 0;
	return 1;
}int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	jc[0]=1;
	for(int i=1;i<N;i++)jc[i]=i*jc[i-1]%M;
	cin>>n>>m>>(ch+1);
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10){
	for(int i=1;i<=n;i++)p[i]=i;
	do{
		int fa=0,mu=0;
		for(int i=1;i<=n;i++)if(ch[i]=='0')fa++;
		else{
			if(c[p[i]]>fa)mu++;
			else fa++;
		}if(mu>=m)ans++;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans%M;
	return 0;}
if(m==n){
	if(check())cout<<jc[n];
	cout<<0;
	return 0;
}if(check()){
	cout<<jc[n];
	return 0; 
}return 0;
}/*
luogu:sms123
orz kkksc03,chen_zhe,Alex_Wei...

IIIIIIIIII          WW      WW     IIIIIIIIII     LL             LL        
    II              WW      WW         II         LL             LL
    II              WW  WW  WW         II         LL             LL
    II              WW  WW  WW         II         LL             LL
    II              WW  WW  WW         II         LL             LL
    II              WWWW  WWWW         II         LL             LL
IIIIIIIIII          WW      WW     IIIIIIIIII     LLLLLLLLLL     LLLLLLLLLL


    AA         KK      KK          IIIIIIIIII       OOOOOO       IIIIIIIIII     !!
  AA  AA       KK    KK                II         OO      OO         II         !!
AA      AA     KK  KK                  II         OO      OO         II         !!
AA      AA     KKKK                    II         OO      OO         II         !!
AA      AA     KK  KK                  II         OO      OO         II         !!
AAAAAAAAAA     KK    KK                II         OO      OO         II
AA      AA     KK      KK          IIIIIIIIII       OOOOOO       IIIIIIIIII     !!


RRRRRRRR       PPPPPPPP
RR      RR     PP      PP         ++             ++
RR      RR     PP      PP         ++             ++
RRRRRRRR       PPPPPPPP       ++++++++++     ++++++++++
RR  RR         PP                 ++             ++
RR    RR       PP                 ++             ++
RR      RR     PP

long long int rp = 0;
int main()
{
	while (1) rp++;
	return 0;
}

PLEASE DO NOT
//freopen
feropen
freeopen
freopen("",r,stdin);
freopen("","r",stdout);
freopen("","r",stdin);
*/