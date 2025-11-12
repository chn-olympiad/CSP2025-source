#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll _base_=31,mod=1e14+31;
ll bas[5001000],n,q,nd[201000],st[201000],len,has[201000][2],s,ha1[5001000],ha2[5001000],l[201000];
string str1,str2;
ll g__1(ll pl,ll pr){
	ll sr=ha1[pr];
	ll sl=ha1[pl-1]*bas[pr-pl+1]%mod;
	return (((sr-sl)%mod+mod)%mod);
}
ll g__2(ll pl,ll pr){
	ll sr=ha2[pr];
	ll sl=ha2[pl-1]*bas[pr-pl+1]%mod;
	return (((sr-sl)%mod+mod)%mod);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	bas[0]=1;
	for(int i=1;i<=5000000;i++) bas[i]=bas[i-1]*_base_%mod;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		st[i]=LLONG_MAX;
		nd[i]=LLONG_MAX;
		cin>>str1;
		len=str1.size();
		for(int j=0;j<len;j++) has[i][0]=(has[i][0]*_base_+(str1[j]-'a'))%mod;
		cin>>str2;
		len=str2.size();
		for(int j=0;j<len;j++) has[i][1]=(has[i][1]*_base_+(str2[j]-'a'))%mod;
		for(int j=0;j<len;j++) if(str1[j]!=str2[j]) nd[i]=min(nd[i],len-1-j),st[i]=min(st[i],j*1ll);
		l[i]=len;
	}
	for(int i=1;i<=q;i++){
		s=0;
		cin>>str1>>str2;
		if(str1.size()!=str2.size()){
			cout<<0<<'\n';
			continue;
		}
		len=str1.size();
		for(int j=0;j<len;j++) ha1[j+1]=(ha1[j]*_base_+str1[j]-'a')%mod;
		for(int j=0;j<len;j++) ha2[j+1]=(ha2[j]*_base_+str2[j]-'a')%mod;
		ll nnd=LLONG_MIN,sst=LLONG_MAX;
		for(int j=0;j<len;j++) if(str1[j]!=str2[j]) nnd=max(nnd,j*1ll),sst=min(sst,j*1ll);
		for(int j=1;j<=n;j++){
			if(nnd+nd[j]>=len||nnd+nd[j]-l[j]+1<0) continue;
			if(g__1(nnd+nd[j]-l[j]+1+1,nnd+nd[j]+1)==has[j][0]&&g__2(nnd+nd[j]-l[j]+1+1,nnd+nd[j]+1)==has[j][1]&&g__1(1,nnd+nd[j]-l[j]+1)==g__2(1,nnd+nd[j]-l[j]+1)&&g__1(nnd+nd[j]+2,len)==g__2(nnd+nd[j]+2,len)) s++;
		}
		cout<<s<<'\n';
	}
	return 0;
}