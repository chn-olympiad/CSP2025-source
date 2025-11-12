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
const ll N=1e6+5;
char s[N];
ll n,a[N],ai;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(ll i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9') a[++ai]=s[i]-'0';
	}
	sort(a+1,a+1+ai,greater<ll>());
	for(ll i=1;i<=ai;i++) write(a[i]);
	putchar('\n');
	return 0;
}
