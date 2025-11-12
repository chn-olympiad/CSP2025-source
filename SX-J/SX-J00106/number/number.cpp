#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
char b;
int len;
char a[N];
int main () {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>s;
	len=s.size();
	for(int i=0;i<=len;i++) {
		b=s[i];
		if(b=='0'||b=='1'||b=='2'||b=='3'||b=='4'||b=='5'||b=='6'||b=='7'||b=='8'||b=='9'){
   			a[i]=b;
		}
	}
	sort(a,a+len);
	for(int i=len-1;i>=0;i--) {
		if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'){
			cout << a[i];
		}
	}
	return 0;
}