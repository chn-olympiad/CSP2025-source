#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[5005], sum=0, jie[5005][5005];
const ll M=998244353;
vector<ll>vec;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(ll i=1; i<=n; i++)cin >> a[i];
	sort(a+1, a+1+n);
	jie[0][0]=1;
	for(ll i=0; i<=n+1; i++){
		for(ll j=0; j<=n+1; j++){
//			if(i==1&&j==1)jie[i][j]=1;
			jie[i][j]+=jie[i-1][j]+jie[i-1][j-1];
//			cout<<jie[i][j]<<' ';
		}
//		cout<<'\n';
	}
//	cout<<jie[n][3]<<' ';
	for(ll i=3; i<=n; i++){
		sum=(sum+jie[n][i])%M;
	}
//	cout<<sum;
	vec.push_back(a[1]);
	vec.push_back(a[2]);
	vec.push_back(a[1]+a[2]);
	for(ll i=3; i<=n; i++){
		ll vs=vec.size();
		for(ll j=0; j<vs; j++){
			if(a[i]>=vec[j]&&j>=2){
//				cout<<a[i]<<'>'<<j<<':'<<vec[j]<<'\n';
				sum--;
			}
			if(sum==-1)sum=M-1;
			vec.push_back(a[i]+vec[j]);
		}
	}
	cout<<sum;
	return 0;
}

