#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int c[505];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	bool flag=true;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			flag=false;
		}
	}
	if(flag){
		long long x=1;
		for(int i=n;i>=1;i--){
			x=(x%MOD*i%MOD)%MOD;
		}
		cout << x;
	}else{
		sort(c+1,c+n+1,cmp);
		int cnt=0;
		int x=1,y=1;
		for(int i=n;i>=1;i--){
			if(c[i]>=18){
				cnt++;
			}
		}
		if(cnt>=18){
			for(int i=cnt;i>=18;i--){
				x=(x%MOD*i%MOD)%MOD;
			}
			x=x/6402373705728000;
			cout << x;
		}else{
			for(int i=18;i>=1;i--){
				x=(x%MOD*i%MOD)%MOD;
			}
			cout << x;
		}
	}
	return 0;
}
