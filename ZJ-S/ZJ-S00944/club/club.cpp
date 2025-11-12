#include<bits/stdc++.h>
#define int long long
#define whk 0
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(x) ((x)&-(x))
#define up(i,a,b) for(int i=(a);i<=(b);i++)
#define down(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;
constexpr int N=1e5+20;
int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}while(isdigit(ch)){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}return x*f;
}

int t,n,n_mx,ans=0;
int anum,bnum,cnum;
struct club{
	int sa,sb,sc,s[4];
	bool af,bf,cf;
}a[N]; 
bool cmp1(club x,club y){return x.sa>y.sa;}
bool cmp2(club x,club y){return x.sb>y.sb;}
bool cmp3(club x,club y){return x.sc>y.sc;}
void clubA(){sort(a+1,a+1+n,cmp1);up(i,1,n_mx) ans+=a[i].sa;}
void clubB(){sort(a+1,a+1+n,cmp2);up(i,1,n_mx) ans+=a[i].sb;}
void clubC(){sort(a+1,a+1+n,cmp3);up(i,1,n_mx) ans+=a[i].sc;}
int check(){
	int at=0,bt=0,ct=0;
	up(i,1,n){
		int k=max({a[i].sa,a[i].sb,a[i].sc});
		if(k==a[i].sa and k!=a[i].sb and k!=a[i].sc) anum++,a[i].af=1;
		else if(k!=a[i].sa and k==a[i].sb and k!=a[i].sc) bnum++,a[i].bf=1;
		else if(k!=a[i].sa and k!=a[i].sb and k==a[i].sc) cnum++,a[i].cf=1;
		else if(k==a[i].sa and k==a[i].sb and k!=a[i].sc) at++,bt++;
		else if(k!=a[i].sa and k==a[i].sb and k==a[i].sc) bt++,ct++;
		else if(k==a[i].sa and k!=a[i].sb and k==a[i].sc) at++,ct++;
		else if(k==a[i].sa and k==a[i].sb and k==a[i].sc) at++,ct++,bt++;
	}
	if(anum>n_mx) return 1;
	else if(bnum>n_mx) return 2;
	else if(cnum>n_mx) return 3;else return 0;
}
void ww(int x,int k){
	if(x==1)
		up(i,1,k) a[i].af=0;
	else if(x==2)
		up(i,1,k) a[i].bf=0;
	else if(x==3)
		up(i,1,k) a[i].cf=0;
}
pii emp[4];
bool che(int i,int j,int k,int h){
	if(i==j){
		if(i==k or i==h) 
		return 0;
	}if(i==k){
		if(i==j or i==h) 
		return 0;
	}if(i==h){
		if(i==k or i==j) 
		return 0;
	}if(j==k){
		if(j==h or j==i) 
		return 0;
	}if(j==h){
		if(i==j or j==k) 
		return 0;
	}if(k==h){
		if(i==k or k==h) 
		return 0;
	}
	return 1;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	emp[1].se=-999,emp[2].se=-999,emp[3].se=-999;
	while(t--){
		int noa=0,nob=0,noc=0;
		n=read();ans=0;
		anum=0,bnum=0,cnum=0;
		n_mx=n/2;
		up(i,1,n){
			a[i].sa=read(),a[i].sb=read(),a[i].sc=read();
			a[i].s[1]=a[i].sa,a[i].s[2]=a[i].sb,a[i].s[3]=a[i].sc;
			if(a[i].sa>emp[1].se)
				emp[1].fi=i,emp[1].se=a[i].sa;
			if(a[i].sb>emp[2].se)
				emp[2].fi=i,emp[2].se=a[i].sb;
			if(a[i].sc>emp[3].se)
				emp[3].fi=i,emp[3].se=a[i].sc;
			if(a[i].sa>0) noa=1;
			if(a[i].sb>0) nob=1;
			if(a[i].sc>0) noc=1;
		}
		if(n==2){
			int q=a[1].sa+a[2].sb,w=a[1].sa+a[2].sc;
			int e=a[1].sb+a[2].sa,r=a[1].sb+a[2].sc;
			int T=a[1].sc+a[2].sa,y=a[1].sc+a[2].sb;
			cout<<max({q,w,e,r,T,y})<<endl;return whk;
		}
		else if(n==4){
		
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int k=1;k<=3;k++){
						for(int h=1;h<=3;h++){
							if(che(i,j,k,h)){
								cout<<i<<" "<<j<<" "<<k<<" "<<h<<endl; 
								ans=max(ans,a[1].s[i]+a[2].s[j]+a[3].s[k]+a[4].s[h]);
							}
						}
					}
				}
			}
			cout<<ans<<endl;return whk;
		
		}
		if(!nob and !noc){clubA();cout<<ans<<'\n';continue;}
		else if(!noa and !noc){clubB();cout<<ans<<'\n';continue;}
		else if(!noa and !nob){clubC();cout<<ans<<'\n';continue;}
		else if(!noa and !nob and !noc){cout<<ans<<'\n';continue;}
		
		int f=check();
		if(f==0){
			up(i,1,n) ans+=max({a[i].sa,a[i].sb,a[i].sc});
			cout<<ans<<'\n';continue;
		}else{
			
		}
	}
	return 0;
}
//我常常追忆过去。
//前面记得后面记得中间忘了 
//我该在哪里停留？我问我自己。 
