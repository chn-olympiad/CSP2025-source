#include<bits/stdc++.h>
using namespace std;
long long a[20];
int main(){
	string s;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0' and s[i]<='9'){
			a[int(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(long long j=0;j<a[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}
