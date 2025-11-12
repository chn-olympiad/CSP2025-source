#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int p=1,a[1000005];
	long long ans;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[p]=int(s[i]);
			p++;
		}
	}
	sort(a+1,a+p);
	for (int i=1;i<p;i++){
		ans+=a[i]*i;
	}
	cout<<ans;
	return 0;
} 
