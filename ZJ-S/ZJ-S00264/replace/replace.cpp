#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll _=4e5+5,L=3e6+5,K1=101,M1=1e9+7,K2=10007,M2=998244853;
ll pw1[L],pw2[L];
struct o{
	ll l,x,y;
	bool operator==(const o &t)const{return l==t.l&&x==t.x&&y==t.y;}
	o operator+(const char &t)const{return {l+1,(x*K1+t-96)%M1,(y*K2+t-96)%M2};}
	// void operator+=(const char &t){l++;x=(x*K1+t-96)%M1;y=(y*K2+t-96)%M2;}
	o operator+(const o &t)const{return {l+t.l,(x*pw1[t.l]+t.x)%M1,(y*pw2[t.l]+t.y)%M2};}
	o operator-(const o &t)const{return {l-t.l,(x+M1-t.x*pw1[l-t.l]%M1)%M1,(y+M2-t.y*pw2[l-t.l]%M2)%M2};}
};
ll n,q,m,x,y,z,s,al[_],ar[_],i,j;string sa,sb;o ot,af[_],at[_],bf[L],bt[L];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(pw1[0]=i=1;i<_;i++)pw1[i]=pw1[i-1]*K1%M1;
	for(pw2[0]=i=1;i<_;i++)pw2[i]=pw2[i-1]*K2%M2;
	cin>>n>>q;
	for(i=0;i<n;i++){
		cin>>sa>>sb;m=sa.size();
		if(sa==sb){i--;n--;continue;}
		for(j=0;j<m;j++)if(sa[j]!=sb[j]){al[i]=j;break;}
		for(j=m;j--;)if(sa[j]!=sb[j]){ar[i]=j;break;}
		ot={0,0,0};for(j=0;j<m;j++)ot=ot+sa[j];af[i]=ot;
		ot={0,0,0};for(j=0;j<m;j++)ot=ot+sb[j];at[i]=ot;
	}
	while(q--){
		cin>>sa>>sb;m=sa.size();s=0;
		if(sa.size()!=sb.size()){cout<<"0\n";continue;}
// if(sa==sb)cerr<<"!!!ERROR: qa==qb\n";
		for(j=0;j<m;j++)if(sa[j]!=sb[j]){x=j;break;}
		for(j=m;j--;)if(sa[j]!=sb[j]){y=j;break;}
		bf[0]={0,0,0};for(i=0;i<m;i++)bf[i+1]=bf[i]+sa[i];
		bt[0]={0,0,0};for(i=0;i<m;i++)bt[i+1]=bt[i]+sb[i];
		for(i=0;i<n;i++)if(ar[i]-al[i]==y-x&&al[i]<=x&&af[i].l-ar[i]<=m-y){
			z=x-al[i];
// cout<<'#'<<i<<' '<<z<<'\n';
			if(bf[af[i].l+z]-bf[z]==af[i]&&bt[at[i].l+z]-bt[z]==at[i])s++;
		}
		cout<<s<<'\n';
	}
}