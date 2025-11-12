#include<bits/stdc++.h>
using namespace std;
string a;
long long s[10]={0},n=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=a.size();
	for(int q=0;q<n;q++){
		if(a[q]>='0'&&a[q]<='9')s[a[q]-'0']++;
	}
	for(int q=9;q>=0;q--){
		for(int w=1;w<=s[q];w++)cout<<q;
	}
	return 0;
}
