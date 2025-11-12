#include<bits/stdc++.h> 
using namespace std;
string s;
int a[1000006];
long long j;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.size();
	for(long long i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j++]=s[i]-'0';
		}
	}
	sort(a,a+j);
	for(long long i=j-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
