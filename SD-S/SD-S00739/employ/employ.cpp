#include<bits/stdc++.h>
using namespace std;
using ll=long long;
namespace StarRail{
	constexpr ll p=998244353;
	ll a[505],can[505],dp[20][(1<<18)+5];
	ll poptab[260];
	ll popcnt(ll x){
		if(!poptab[1]){
			for(int i=0;i<=255;i++){
				for(int j=0;j<=7;j++)if(i&(1<<j))poptab[i]++;
			}
		}
		return poptab[(x>>24)&255]+poptab[(x>>16)&255]+poptab[(x>>8)&255]+poptab[x&255];
	}
	
	void main(){
		freopen("employ.in","r",stdin);
		freopen("employ.out","w",stdout);
		//freopen("employ1.in","r",stdin);
		//freopen("employ1.out","w",stdout);
		ios::sync_with_stdio(0);cin.tie(0);
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			char c;
			cin>>c;
			can[i]=c-48;
		}
		for(int i=1;i<=n;i++)cin>>a[i];
		dp[0][0]=1;
		if(n<=18){
			for(int i=0;i<n;i++){
				for(int j=0;j<(1<<n);j++){
					if(popcnt(j)==i){
						for(int k=1;k<=n;k++){
							if(!(j&(1<<k-1))){
								for(int l=0;l<=i;l++){
									int nxtl=l+(can[i+1]==1&&i-l<a[k]),nxtj=j|(1<<k-1);
									dp[nxtl][nxtj]+=dp[l][j];
									if(dp[nxtl][nxtj]>p)dp[nxtl][nxtj]-=p;
								}
							}
						}
					}
				}
			}
			ll ans=0;
			for(int i=m;i<=n;i++)ans+=dp[i][(1<<n)-1];
			cout<<ans%p<<'\n';
		}
		else{
			ll ans=1;
			for(int i=1;i<=n;i++)ans=(ans*i)%p;
			cout<<ans<<'\n';
		} 
	}
}
int main(){
	StarRail::main();
}
/*
gu fen: 100+56+[25,100]+20=[201,276]
maybe 0?

thank you Furina
thank you Cyrene
thank you Elysia
thank you HL1
thank you Rabbit group
thank you Hikari
thank you Tairitsu
thank you Geopelia
thank you Gino
please let me 200+
please let me 1=
please let me level 7

t1 trivial greedy?
da yang li pass
t2 mst can do 16pts and pass sample 2???
mst + constraint A + O(2^k mlogm)=56?
t3 trie pao de fei kuai??
passed da yang li
25?50?100??
t4 zhuang ya dp
20?
I thought an O(n^2) solution but it's impossible to dp

//freopen
//freopen
#include<bits\stdc++.h>
int y1;
freopen("club.ans","w",stdout);
freopen("employee.in","r",stdin);
We're no strange to love
you know the rules and so do I

Darkest nignt I'll confront you here...

rain sky red blue touch collapse baby's sleep song

please let me 1=
please let me 1=
please let me 1=
please let me not 0pts
please let me 200+
please let me level 7


*/
