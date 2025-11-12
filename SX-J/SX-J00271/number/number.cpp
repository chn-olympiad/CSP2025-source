#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int N=1e5+5;
int sum[N];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a=0,b=0;
	cin>>s;
	if(s.size()==1&&s[0]>='0'&&s[0]<='9'){
		cout<<s;
		return 0;
	}
	for(int i=0;i<s.size();++i){
		if(s[i]>='0'&&s[i]<='9'){
			b++;
			sum[b]=s[i]-48;
		}
	}
	for(int i=2;i<=b;++i){
		if(sum[i]>sum[i-1]){
			a=sum[i-1];
			sum[i-1]=sum[i];
			sum[i]=a;
		}
	}
	for(int i=1;i<=b;++i){
		cout<<sum[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}