#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,MOD=998244353;
int n,m,k,tot;
ll ans=1;
int wown=1,wowmx,wow[N];
int c[N],qz[N];
bool dif[N];
string s;
ll sq(ll x,ll y);
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;dif[0]=1;
	cin>>s;qz[0]=0;
	ans=sq(n-m,1);
	for(int i=0;i<s.size();i++){
		dif[i+1]=s[i]-'0';
		if(dif[i+1]==1)k++,wow[wown]++;
		else wown++;
		qz[1+i]=k;
	}wowmx=wown;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	if(qz[n]<m){
		cout<<0;
		return 0;
	}
	while(qz[tot]<c[m]){
		tot++;
	}
	if(tot>m){
		cout<<0;
		return 0;
	}k=0,tot=0;
	for(int i=1;i<=n;i++){
		if(dif[i]==0){k++;continue;}
		if(c[i]>k)tot++;
		if(tot>m){k=i;break;}
	}tot=0,wown=0;
	while(tot<k&&wown<wowmx){
		wown++;
		if(wow[wown]==0)tot++;
		else tot+=wow[wown];
		if(wow[wown]!=0){
			ans*=sq(wow[wown],1);
			ans%=MOD;
		}
	}
	for(int i=1;i<=min(k,(n-k));i++){
		ans*=sq(k,k-i+1)*n-k-i+1;
		ans%=MOD;
	}
	cout<<ans;
}
ll sq(ll x,ll y){
	ll res=1;
	while(x>=y){
		res*=x;
		x--;
		res%=MOD;
	}
	return res;
}
/*
dp[i][x][y][z]=max(dp[i-1][x-1][y][z]+a[i].pos[2],max(dp[i-1][x][y-1][z]+a[i].y,dp[i-1][x][y][z-1]+a[i].z)); 

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
