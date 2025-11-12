#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,ans1,_a,cnta,_b,cntb,_c,cntc;

struct EveryOne{
	ll _1;
	ll _2;
	ll _3;
}a[100010];

bool cmp(EveryOne x,EveryOne y){
	return x._1 > y._1;
}

ll read(){
	char c=getchar();
	ll res=0;
	while('0'<=c && c<='9'){
		res=res*10+(c-'0');
		c=getchar();
	}
	return res;
}

void dfs(ll x){
	if(x>n){
		ans1=max(ans1,_a+_b+_c);
		return;
	} 
	if(cnta<n/2){
		_a+=a[x]._1;
		cnta++;
		dfs(x+1);
		cnta--;
		_a-=a[x]._1;
	}
	if(cntb<n/2){
		_b+=a[x]._2;
		cntb++;
		dfs(x+1);
		cntb--;
		_b-=a[x]._2;
	}
	if(cnta<n/2){
		_c+=a[x]._3;
		cntc++;
		dfs(x+1);
		cntc--;
		_c-=a[x]._3;
	}
}

void s1(){
	ans1=0;
	cnta=0,cntb=0,cntc=0;
	dfs(1);
	cout << ans1 << endl;
}

void s2(){
	sort(a+1,a+n+1,cmp);
	ll ans2=0;
	for(int i=1;i<=n/2;i++){
		ans2+=a[i]._1;
	}
	cout << ans2;
}

void s(){
	n=read();
	bool flag=1;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++){
		a[i]._1=read();
		a[i]._2=read();
		a[i]._3=read();
		if(a[i]._3!=0 || a[i]._2!=0) flag=0;
	}
	if(flag) s2();
	else s1();
}

int main() {
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	ll T;
	T=read();
	for(int i=1;i<=T;i++){
		s();
	}
	return 0;
}

