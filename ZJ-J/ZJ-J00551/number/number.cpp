#include<bits/stdc++.h>
using namespace std;
long long f[105];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<=s.size();++i){
		if('0'<=s[i]&&s[i]<='9'){
			long long x=int(s[i]-'0');
			f[x]++;
		}
	}
	for(long long i=9;i>=0;--i){
		if(f[i]!=0){
			for(long long k=1;k<=f[i];++k){
				cout<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

