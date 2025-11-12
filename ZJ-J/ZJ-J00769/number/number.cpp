#include<bits/stdc++.h>
using namespace std;
long long a[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long l=s.size();
	int cnt=0;
	for(long long i=0;i<l;i++){
		a[int(s[i])]+=1;
	}
	for(int i=57;i>=48;i--){
		for(long long j=0;j<a[i];j++)cout<<char(i);
	}
	return 0;
}

