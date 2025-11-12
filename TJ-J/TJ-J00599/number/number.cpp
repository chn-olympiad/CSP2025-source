#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000001],n,cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt++]=s[i]-'0';
		}
	}
	sort(a,a+cnt,greater<int>());
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	return 0;
}


