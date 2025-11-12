#include <bits/stdc++.h>
using namespace std;
string a;
long long flag[100],answer;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.size();
	//cout<<a[0]-48;
	for(int i=0; i<=len-1; i++) {
		if('0'<=a[i]&&'9'>=a[i]) {
			flag[int(a[i])-48]++;
			//int shu=a[i]-48;
			//cout<<shu;
		}
	}
	int sum=0;
	for(int i=9; i>=0; i--) {
		for(int j=1; j<=flag[i]; j++) {
			cout<<i;
		}
	}
	return 0;
}
