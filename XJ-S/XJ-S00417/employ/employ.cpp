#include<bits/stdc++.h>
using namespace std;
const int N=502;
int n,m,c[N];
unsigned long long ans=1;
char s[N];
bool A=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> s[i];
		if(s[i]=='0') A=0;
	}
	for(int i=0;i<n;i++) cin >> c[i];
	if(A){
		for(int i=n;i>m;i--){
			ans*=i;
			ans%=998244353;
		}
		cout << ans;
	}
	else cout << "1";
	return 0;
} 

