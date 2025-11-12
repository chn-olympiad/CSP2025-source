#include<bits/stdc++.h>
using namespace std;
int n,s[5005],ak;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>s[i];
	if (n<=2){
		cout<<0;
		return 0;
	}
	for(int i = 1;i<=pow(2,n);i++){
		int ans = 0,mx = 0;
		for(int j = 1;j<=n;j++){
			if(i&(1<<(j-1))){
				ans+=s[j];
				mx = max(mx,s[j]);
			}
		}
		if (ans>2*mx)ak++;
	}
	cout<<ak;
	return 0;
}
