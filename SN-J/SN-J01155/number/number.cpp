#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	char a[N+5],b[N+5];
	for(int i = 1;i<=N;i++) b[i] = s[i];
	int flag = 0;
	for(int i = 1;i<=N;i++){
		if((b[i] == '0') || (b[i] == '1') || (b[i] == '2') || (b[i] == '3') || (b[i] == '4') || (b[i] == '5') || (b[i] == '6') || (b[i] == '7') || (b[i] == '8') || (b[i] == '9')){
			a[i] = b[i];
			flag++;
			continue;
		}
	}
	sort(a+1,a+flag+1);
	for(int i = 1;i<=flag;i++) cout<<a[flag-i+1];
	return 0;
}
