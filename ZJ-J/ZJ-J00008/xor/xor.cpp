//#Shang4Shan3Ruo6Shui4
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pr pair<long long,long long>
#define forr(i,n) for(long long i=1;(i)<=(n);(i)++)
#define fo(i,n) for(long long i=0;(i)<(n);(i)++)
#define gc getchar
#define pc putchar
#define one first
#define two second
ll num,numm[110],f,cnt;
ll n,k,a[500010],sum,s[500010],ans,p;
pr b[500010];
char c;
ll in(){
	f=1,num=0,c=gc();
	for(;c<'0'||c>'9';c=gc())
		if(c=='-')
			f=-1;
	for(;c>='0'&&c<='9';c=gc())
		num=num*10+c-'0';
	return num*f;
}
void out(ll x){
	f=1,cnt=0;
	if(x){
	if(x<0)
		f=-1,x=-x;
	while(x)
		numm[++cnt]=x%10,x/=10;
	for(ll i=cnt;i>=1;i--)
		pc(numm[i]+'0');
	}
	else if(x==0)
		pc('0');
}
bool cmp(pr a,pr b){
	return (a.two==b.two?a.one<b.one:a.two<b.two);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=in();
	k=in();
	f=2;
	forr(i,n){
		a[i]=in();
		if(a[i]==1&&f==2)
			f=1;
		if(a[i]==0&&f==1)
			f=0;
		sum=max(a[i],sum);
		s[i]=s[i-1]^a[i];
	}

	if(sum<k){
		fo(i,31)
		if((1<<i)>=sum&&(1<<i)<=k){
			out(0);
			break;
		}
	}
	else{
		cnt=0;
		forr(i,n){
			for(ll j=i;j<=n;j++)
				if((s[i-1]^s[j])==k){
					b[++cnt].one=i,b[cnt].two=j;
					break;
				}
		}
	}
	sort(b+1,b+cnt+1,cmp);
	for(ll i=1;i<=cnt;i++)
		if(b[i].one>p)
			ans++,p=b[i].two;
	cout<<ans;
	return 0;
}