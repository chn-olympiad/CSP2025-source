#include<bits/stdc++.h>
using namespace std;
string a,c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a;
	long long la=a.length();
	for(int i=0;i<la;i++){
		if(a[i]<='9' && a[i]>='0'){
			c+=a[i];
		}
	}
	sort(c.begin(),c.end());
	long long lc=c.length();
	for(int i=lc-1;i>=0;i--){
		cout<<c[i];
	}
	return 0;
}