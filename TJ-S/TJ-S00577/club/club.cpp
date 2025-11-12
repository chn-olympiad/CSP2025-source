#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t;
int n;
int ans;
struct null{
	int a,b,c;
}k[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1; i<=n; i++){
			cin >> k[i].a >> k[i].b >> k[i].c;
			ans += max(k[i].a , k[i].b , k[i].c);
		}
	}
	cout << ans <<"\n";
	
	return 0;
} 
