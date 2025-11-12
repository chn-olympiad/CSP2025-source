#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+10;
ll n,k,a[N];
inline ll read(){
	ll s=0,w=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-'){
			w=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+ch-'0';
		ch=getchar();
	}
	return s*w;
}
struct Node{
	ll x,y;
}awa[1919810];
ll cnt=0;
bool cmp(Node a,Node b){
	return a.y<b.y;
}
ll ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	a[0]=0;
	for(ll i=1;i<=n;i++){
		a[i]=read();
	}
	for(ll i=1;i<=n;i++){
		ll sum=0;
		for(ll j=i;j<=n;j++){
			sum^=a[j];
			if(sum==k){
				++cnt;
				awa[cnt].x=i;
				awa[cnt].y=j;
				break;
			}
		}
	}
	sort(awa+1,awa+1+cnt,cmp);
	ll last=0;
	for(ll i=1;i<=cnt;i++){
		if(awa[i].x>last){
			last=awa[i].y;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}