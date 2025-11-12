#include<bits/stdc++.h>
using namespace std;
long long a[1100000];
bool g(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int d=0;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			d++;
			a[d]=s[i]-'0';
		}
	}
	sort(a+1,a+d+1,g);
	for(int i=1;i<=d;i++){
		cout<<a[i];
	}
	return 0;
}

