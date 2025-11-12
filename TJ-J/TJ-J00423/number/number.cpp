#include <bits/stdc++.h>
using namespace std;
string s;
long long l_;
long long a[1000001];
long long l=0;
long long i_=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l_=s.length();
	for(int i=0;i<l_;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[i_]=s[i]-'0';
			l++;
			i_++;
		}
	}
	sort(a,a+l);
	for(int i=l-1;i>=0;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

