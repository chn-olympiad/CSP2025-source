#include<bits/stdc++.h>
#define ll long long
const ll N=1e5+100;
using namespace std;
ll read(){
	ll f=1,k=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+(c-'0');
		c=getchar();
	}
	return f*k;
}
void print(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else print(x/10),putchar(x%10+'0');
} 
ll T,n,ans;
ll sza,szb,szc;
priority_queue<ll>qa,qb,qc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		while(!qa.empty())qa.pop();
		while(!qb.empty())qb.pop();
		while(!qc.empty())qc.pop();
		sza=0,szb=0,szc=0;
		ans=0;
		n=read();
		for(ll i=1;i<=n;i++){
			ll a=read(),b=read(),c=read();
			ll ma=max(a,max(b,c));
			ans+=ma;
			if(a==ma){
				sza++;
				qa.push(max(b,c)-a);
			}
			else if(b==ma){
				szb++;
				qb.push(max(a,c)-b);
			}
			else if(c==ma){
				szc++;
				qc.push(max(a,b)-c);
			}
		}
		while(sza>n/2){
			ans+=qa.top();
			qa.pop();sza--;
		}
		while(szb>n/2){
			ans+=qb.top();
			qb.pop();szb--;
		}
		while(szc>n/2){
			ans+=qc.top();
			qc.pop();szc--;
		}
		print(ans);putchar('\n');
	}
	return 0;
} 
