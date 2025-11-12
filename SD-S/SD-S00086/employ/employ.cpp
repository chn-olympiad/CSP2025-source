#include<bits/stdc++.h>
#define ll long long
#define V vector
#define pi pair <int,int>
#define fi first
#define se second
using namespace std;

const int mod = 998244353;
V <int> a;
int n,m,ans=0;
int c[100];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	ios::sync_with_stdio(false);
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i=1;i<=n;i++) cin >> c[i];
	for(int i=1;i<=n;i++) a.push_back(i);
	do{
//		for(int i=0;i<n;i++) cout << a[i] << " ";cout << '\n';
//		for(int i=0;i<n;i++) cout << c[a[i]]  << " ";cout << '\n';
		int ok=0,out=0;
		for(int i=0;i<n;i++){
//			cout << a[i] << " " << c[a[i]] << " " << out << " " << ok << '\n'; 
			if(out>=c[a[i]]){
				out++;
				continue;
			}
			if(s[i]=='0') {
				out++;
				continue;
			}
			ok++;
//			cout << ok << '\n';
		}
//		cout << ok << '\n';
		if(ok>=m) ans=ans+1%mod;
	}while(next_permutation(a.begin(),a.end()));
	cout << ans;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

