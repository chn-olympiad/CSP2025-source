#include<bits/stdc++.h>
using namespace std;
string s;
long long num[1000005],cnt=0,ans=0;

bool cmp(long long x,long long y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[++cnt]=s[i]-'0';
		}
	}
	sort(num+1,num+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		printf("%lld",num[i]);
	}
	return 0;
}