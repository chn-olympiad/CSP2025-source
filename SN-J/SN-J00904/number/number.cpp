//hhz RP++ SCORE++ pts++
#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[11];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	int sum=0;
	for(int i=9;i>=0;i--){
		if(i==0&&sum==0){
			a[i]=1;
		}
		for(int j=1;j<=a[i];j++){
			cout<<i;
			sum+=i;
		}
	}
	return 0;
}
