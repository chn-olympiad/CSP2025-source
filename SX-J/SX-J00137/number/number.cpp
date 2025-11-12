#include<bits/stdc++.h>
using namespace std;

string s;
int a[1000005];
int k = 1;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for( int i = 0 ; i < s.size() ; i++ ){
		if( s[i] >= '0' && s[i] <= '9' ){
			a[k++] = s[i] - '0';
		}
	}
	sort(a+1,a+k+1);
	for( int i = k ; i > 1 ; i-- )cout << a[i];

	return 0;
}