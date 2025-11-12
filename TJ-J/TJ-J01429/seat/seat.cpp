#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[107],lzxr,k,sb=1,nm=1,cnt=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	k=n*m;
	for(int i = 0;i < k;i++){
		cin >> a[i];
	}
	lzxr=a[0];
	sort(a,a+k);
	for(int i = k-1;a[i] != lzxr;i--){
		if(sb<=n&&cnt==0){
			sb++;
		}else if(sb!=0&&cnt==1){
			sb--;
		}
		if(sb>n){
			nm++;
			sb--;
			cnt=1;
		}else if(sb==0){
			nm++;
			sb++;
			cnt=0;
		}
	}
	cout << nm << ' ' << sb;
	return 0;
} 


