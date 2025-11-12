#include<bits/stdc++.h>
using namespace std;
long long a[10000005],j = 1;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i = 0;i<s.size();++i){
		if(s[i] >= '0'&&s[i] <= '9'){
			a[j] = s[i]-'0';
			j++;
		}
	}
	sort(a+1,a+j);
	for(long long i = j-1;i>=1;--i){
		if(a[i] != 0||i==1){
			cout<<a[i];
		}
	}
	return 0;
}
