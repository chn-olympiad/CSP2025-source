#include <bits/stdc++.h>

using namespace std;

string r;
long long x[10];
long long l;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> r;
	l = r.size();
	for (long long i=0;i<l;i++){
 		int k = r[i]-'0';
 		if (k<0||k>9)continue;
 		x[k]++;
	}
	for (int i=9;i>=0;i--){
		int m = x[i];
		for (long long j=1;j<=m;j++){
			cout << i;
		}
	}
	return 0;
}
