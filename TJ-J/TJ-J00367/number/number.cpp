#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char x;
int a[N];
int h;
string s;
int cmp(int a,int b) {
	return a>b;
}
int main() {
	cin>>s;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<s.length();i++) {
		
		x=s[i];
		int d=x-'0';
		if(d<=9&&d>=0)  {
			a[i]=d;
			h++;
		}
	}
	sort(a,a+N-1,cmp);
	for(int i=0;i<h;i++) {
		cout<<a[i];
	}
	return 0;
}
