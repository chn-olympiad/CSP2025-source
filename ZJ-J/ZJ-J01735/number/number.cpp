#include<bits/stdc++.h>
#define ll long long
const int N=1e6+10;
using namespace std;
string s;
ll len;
ll a[N],ind=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	len=s.length();
	
	for(ll i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[ind]=s[i]-'0';
			ind++;
		}
	}
	ind--;
	sort(a+1,a+ind+1);
	
	for(ll i=ind;i>=1;i--){
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
