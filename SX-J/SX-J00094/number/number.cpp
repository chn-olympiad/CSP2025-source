#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
string s;
ll a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin>>s;
	ll j=0;
	for(ll i=1;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=(int)s[i]-'0';
			j++;
		}else{
			continue;
		}
	}
//	for(int i=0;i<j;i++){
//		cout<<a[i]<<endl;
//	}
	//cout<<j;
	sort(a,a+j);
	for(int i=j-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}