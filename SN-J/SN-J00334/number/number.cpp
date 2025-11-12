#include<bits/stdc++.h>
using namespace std;
long long a[15];
int main(){
	//SN-J00334,张屹然，铁一中 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long n=s.size();
	s=' '+s;
	for(long long i=1;i<=n;i++){
		if(s[i]<='9' and s[i]>='0'){
			a[s[i]-'0']++;
		}
	}
	for(long long i=9;i>=0;i--){
		if(a[i]>0){
			for(long long j=1;j<=a[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
