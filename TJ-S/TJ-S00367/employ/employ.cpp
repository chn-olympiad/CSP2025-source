#include <bits/stdc++.h>
using namespace std;
#define lld __int128
#define MOD %998244353

void out(__int128 x){
	int a[128],l=0;
	while (x){
		int c=x-x/10*10;
		a[l]=c;
		x/=10;
		l++;
	}
	for(int i=l-1;i>=0;i--)printf("%d",a[i]);
}

lld tt(lld a){
	int sum=1;
	for(int i=1;i<=a;i++)sum=(sum*i);
	return sum;
}

lld C(lld n,lld k){
	return (tt(n)/tt(k)*tt(n-k))MOD;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	out(C(n,m));//Æ­·Ö 
	return 0;
} 
