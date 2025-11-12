#include<bits/stdc++.h>
using namespace std;
string s;
long long n[1000005],cnt=0;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			cnt++;
			n[cnt]=s[i]-'0';
		} 
	}
	sort(n+1,n+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		printf("%lld",n[i]);
	}
	return 0;     
}
