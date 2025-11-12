#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
long long g[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long j=0;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			g[++j]=s[i]-'0';
		}
	}
	sort(g+1,g+1+j);
	for(long long i=j;i>=1;i--){
		cout<<g[i];
	} 
	return 0;
} 
