#include<bits/stdc++.h>
using namespace std;
long long cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long o=1;
	long long a[s.size()+10];
	for(long long i=0;i<s.size();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[o]=s[i]-'0';
			o++;
		} 
	}
	sort(a+1,a+1+o,cmp);
	for(long long i=1;i<=o-1;i++){
		if(a[i]>=10) continue;
		cout << a[i];
	}
	cout << endl << o-1;
	return 0;
} 
