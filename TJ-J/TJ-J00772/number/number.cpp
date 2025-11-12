#include<bits/stdc++.h>

using namespace std;

//#define int long long
string s;
int n[1000005],a,b,j=0;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			n[j]=int(s[i]-'0');
			b++;
			j++;
		}
	}
	//cout<<b;
	sort(n,n+b);
	for(int i=b-1;i>=0;i--){
		cout<<n[i];
	}
	return 0;
} 
