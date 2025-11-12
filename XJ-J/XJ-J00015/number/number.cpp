#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	string q;
	long long a[100000];
	int n=0;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[n]+=s[i];
			n++;
		}
	}
	sort(a,a+n+1);
	for(int i=n;i>0;--i){
		q[i]=a[i];
		cout<<q[i];
	}
	
	return 0;
}
