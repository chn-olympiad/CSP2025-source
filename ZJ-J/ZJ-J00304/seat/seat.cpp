#include<bits/stdc++.h>
#define ll long long
#define debug printf("!!!\n")
using namespace std;
ll read(){
	char c=getchar();
	ll x=0,f=1;
	for(;c<'0'||c>'9';c=getchar()){
		if(c=='-') f=-1;
	}
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void write(ll x,char c){
	write(x);putchar(c);
}
const ll N=105;
ll n,m,a[N],x,id;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();m=read();
	for(ll i=1;i<=n*m;i++) a[i]=read();
	x=a[1];
	sort(a+1,a+1+n*m,greater<ll>());
	for(ll i=1;i<=n*m;i++){
		if(a[i]==x){
			id=i;break;
		}
	}
	ll lie=(id+n-1)/n,hang=id%n;
	if(!hang) hang=n;
	write(lie,' ');
	if(lie&1) write(hang,'\n');
	else write(n-hang+1,'\n');
	return 0;
}
