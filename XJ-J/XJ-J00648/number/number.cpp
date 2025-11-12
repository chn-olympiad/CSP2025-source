#include <bits/stdc++.h>
using namespace std;
int b[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;
	for(int i=0;i<a.length();i++){
		
		b[i]=a[i];
	
	}
	
	sort(b,b+a.length());
	
	for(int i=a.length()-1;i>=0;i--){
		cout <<(b[i]-'0');
	}
	
	return 0;
}
