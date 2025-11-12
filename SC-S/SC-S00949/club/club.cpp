#include<bits/stdc++.h>
#define N 100005
using namespace std;
int T,n,a[N],b[N],c[N],kk;
vector<int>d,e,f;
struct Node{
	int id,n;
	const int operator<(const Node& b)const{
		return n<b.n;
	}
}k[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n,kk=0;
		d.clear(),e.clear(),f.clear();
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i])d.push_back(i),ans+=a[i];
			else if(b[i]>=c[i]&&b[i]>=a[i])e.push_back(i),ans+=b[i];
			else f.push_back(i),ans+=c[i];
		}if(d.size()>n/2){
			int odd=d.size()-n/2;
			for(int i:d)k[++kk]={i,min(a[i]-b[i],a[i]-c[i])};
			sort(k+1,k+kk+1);
			for(int i=1;i<=odd;i++)ans-=k[i].n;
		}else if(e.size()>n/2){
			int odd=e.size()-n/2;
			for(int i:e)k[++kk]={i,min(b[i]-a[i],b[i]-c[i])};
			sort(k+1,k+kk+1);
			for(int i=1;i<=odd;i++)ans-=k[i].n;
		}else if(f.size()>n/2){
			int odd=f.size()-n/2;
			for(int i:f)k[++kk]={i,min(c[i]-b[i],c[i]-a[i])};
			sort(k+1,k+kk+1);
			for(int i=1;i<=odd;i++)ans-=k[i].n;
		}cout<<ans<<endl;
	}return 0;
}
/*
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