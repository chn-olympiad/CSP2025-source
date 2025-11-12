#include <bits/stdc++.h>
using namespace std;
string a;
long long tong[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		tong[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(tong[i]){
			cout<<i;
			tong[i]--;
		}
	}
	return 0;
}
