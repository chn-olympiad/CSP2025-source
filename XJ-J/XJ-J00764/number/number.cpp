#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
long long int a[N],len,in=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	len = s.size();
	for(int i=0;i<=len-1;i++){
		if('0'<=s[i]&&s[i]<='9'){
			in++;
			a[in] = s[i]-'0';
		}
	}
	sort(a+1,a+1+in);
	for(int i=in;i>=1;i--){
		cout << a[i];
	}
	
	return 0;
}
