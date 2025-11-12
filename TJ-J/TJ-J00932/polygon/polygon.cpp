#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[5005];
ll cntpolygons(int c){
	int cntt = 0;
	for(int i1 = 1;i1 <= c;i1++){
		for(int i2 = i1+1;i2 <= c;i2++){
			for(int i3 = i2+1;i3 <= c;i3++){
				if(i1+i2>i3)cntt+=(a[i1]*a[i2]*a[i3])%998244353;
				cntt %= 998244353;
				for(int i4 = i3+1;i4 <= c;i4++){
					if(i1+i2+i3>i4)cntt+=(a[i1]*a[i2]*a[i3]*a[i4])%998244353;
					cntt %= 998244353;
					for(int i5 = i4+1;i5 <= c;i5++){
						if(i1+i2+i3+i4>i5)cntt+=(a[i1]*a[i2]*a[i3]*a[i4]*a[i5])%998244353;
						cntt %= 998244353;
						for(int i6 = i5+1;i6 <= c;i6++){
							if(i1+i2+i3+i4+i5>i6)cntt+=(a[i1]*a[i2]*a[i3]*a[i4]*a[i5]*a[i6])%998244353;
							cntt %= 998244353;
							for(int i7 = i6+1;i7 <= c;i7++){
								if(i1+i2+i3+i4+i5+i6>i7)cntt+=(a[i1]*a[i2]*a[i3]*a[i4]*a[i5]*a[i6]*a[i7])%998244353;
								cntt %= 998244353;
								for(int i8 = i7+1;i8 <= c;i8++){
									if(i1+i2+i3+i4+i5+i6+i7>i8)cntt+=(a[i1]*a[i2]*a[i3]*a[i4]*a[i5]*a[i6]*a[i7]*a[i8])%998244353;
									cntt %= 998244353;
									for(int i9 = i8+1;i9 <= c;i9++){
										if(i1+i2+i3+i4+i5+i6+i7+i8>i9)cntt+=(a[i1]*a[i2]*a[i3]*a[i4]*a[i5]*a[i6]*a[i7]*a[i8]*a[i9])%998244353;
										cntt %= 998244353;
										for(int i10 = i9+1;i10 <= c;i10++){
											if(i1+i2+i3+i4+i5+i6+i7+i8+i9>i10)cntt+=(a[i1]*a[i2]*a[i3]*a[i4]*a[i5]*a[i6]*a[i7]*a[i8]*a[i9]*a[i10])%998244353;
											cntt %= 998244353;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (cntt%998244353);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	if(n == 3){
		int x,y,z;
		cin >> x >> y >> z;
		if(x+y+z > 2*max(x,max(y,z))){
			cout << 1;
		}else{
			cout << 0;
		}
		return 0;
	}
	ll maxn = -1;
	for(int i = 0;i < n;i++){
		ll x;
		cin >> x;
		maxn = max(maxn,x);
		a[x]++;
	}
	if(maxn == 1){
		ll cnt = 0;
		for(ll i = 3;i <= n;i++){
			ll kk = 1;
			for(ll j = n;j > n-i;j--){
				kk = (kk*j)%998244353;
			}
			cnt += kk;
			cnt %= 998244353;
		}
		cout << cnt;
		return 0;
	}
	cout << cntpolygons(maxn);
	return 0;
} 
