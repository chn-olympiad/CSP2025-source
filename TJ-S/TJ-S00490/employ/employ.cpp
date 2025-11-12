#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
string a;
ll b[10];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> a;
	if(m == 1){
		cout << 1;
		return 0;
	}
	bool flag = true;
	for(int i = 0;i<a.size();i++){
		if(a[i]!='1'){
			flag = false;
		}
	}
	if(flag){
		if(m != n){
			cout << 0;
			return 0;
		}
		else{
			int ans = 1,num = n;
			for(int i = 0;i<num;i++){
				ans*=n;
				cout << ans << " " << n << endl;
				n--;
			}
			cout << ans;
			return 0;
		}
	}
	return 0;
}
 
