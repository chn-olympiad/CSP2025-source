#include <bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
long long cnta;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	long long l=s.size();
	for (long long i=0;i<l;i++){
		if (s[i]>='0' && s[i] <= '9'){
			a[++cnta]=s[i];
		}
	}
	sort(a+1,a+1+cnta);
	for (long long i=cnta;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
