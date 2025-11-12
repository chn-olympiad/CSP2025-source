#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pr pair<long long,long long>
#define forr(i,n) for(long long i=1;(i)<=(n);i++)
#define fo(i,n) for(long long i=0;(i)<(n);i++)
#define gc getchar
#define pc putchar
ll num,numm[110],f,cnt;
char cc;
ll m,n,s[510],c[510],sum,ans,p,nn;
ll in(){
	f=1,num=0,cc=gc();
	for(;cc>'9'||cc<'0';cc=gc())
		if(cc=='-')
			f=-1;
	for(;cc<='9'&&cc>='0';cc=gc())
		num=num*10+cc-'0';
	return num*f;
}
void out(ll x){
	cnt=0,f=1;
	if(x==0)
		pc('0');
	else{
		if(x<0)
			x=-x,f=-1;
		while(x)
			numm[++cnt]=x%10,x/=10;
		for(ll i=cnt;i>=1;i--)
			pc(numm[i]+'0');
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=in(),m=in();
	f=1;
	forr(i,n){
		s[i]=gc();
		if(!s[i])
			f=0;
		else
			sum++;
	}
	forr(i,n)
		c[i]=in();
	if(f){
		ans=1;
		forr(i,n)
			ans=ans*i%998244353;
		out(ans);
	}
	else if(sum<m)
		pc('0');
	else if(m==1){
		forr(i,n)
			if(s[i]==1){
				p=i;
				break;
			}
		sort(c+1,c+n+1);
		nn=n;
		forr(i,n){
			if(c[i]<p)
				nn--;
			else
				break;
		}
		ans=1;
		forr(i,nn)
			ans=ans*i%998244353;
		out(ans);
	}
	return 0;
}