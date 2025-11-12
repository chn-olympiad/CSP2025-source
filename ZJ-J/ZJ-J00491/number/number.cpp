#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int a[1000005],m;
map<int,int> mp;
int cmp(int a,int b){
	return a>b;
}
signed main(){
	cin>>s;
	freopen("number.in","r",stdin);
	freopen("number,out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	int n=s.size(),cnt=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			m=s[i]-48;
			mp[m]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(mp[i]!=0){
			for(int j=1;j<=mp[i];j++){
				cout<<i;
			}
		}
	}	
}
