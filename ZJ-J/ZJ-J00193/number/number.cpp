#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long i=0,a=0;
	cin>>s;
	char c[1000010];
	for(;i<s.size();i++){
		c[i]=s[i];
		if(c[i]<='9' && c[i]>='0'){
			a++;
		}
	}
	sort(c,c+i);
	for(int j=a-1;j>=0;j--){
		cout<<c[j];
	}
	return 0;
}