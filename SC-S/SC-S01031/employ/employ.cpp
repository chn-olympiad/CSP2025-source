#include<bits/stdc++.h>
using namespace std;
const int N = 500,M =998244353;
int a[N];
int main(){
 	freopen("employ.in","r",stdin);
 	freopen("employ.out","w",stdout);
	long long n,m,k=0,ans=1;
	string s;
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=0){
			k++;
		}
	}
	for(int i=1;i<=k;i++){
		ans = ans*i%M;
	}
	cout << ans;
	return 0;
}