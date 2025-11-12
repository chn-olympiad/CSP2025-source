#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	getline(cin,a);
	string s="";
	long long num=0;
	for(int i=0;i<a.size();i++)
		if(a[i]-48>=0 && a[i]-48<=9){
			s+=a[i];
			num++;
		}
	sort(s.begin(),s.end());
	reverse(s.begin(),s.end());
	cout<<s;
	return 0;
}
