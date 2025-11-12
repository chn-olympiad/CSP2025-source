#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n=0;
	cin >> s;
	for(int i=1,j=0;j<=s.size();j++){
		if(s[j]>='0'&&s[j]<='9'){
			a[i] = s[j];
			i++;
			n++;
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		cout << (char)a[i];
	}
	return 0;
}
