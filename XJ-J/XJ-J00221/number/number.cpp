#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
	freopen("number4.in","r",stdin);
	freopen("number4.out","w",stdout);
	string s;
	cin>>s;
	long long len=s.size();
	long long ai=0;
	for(long long i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			ai++;
			a[ai]=s[i]-'0';
		}
	}
	sort(a+1,a+1+ai);
	if(ai<=19){
		long long ans=0;
		for(long long i=1;i<=ai;i++){
			for(long long j=1;j<i;j++){
				a[i]*=10;
			}
			ans+=a[i];
		}
		cout<<ans;
	}
	else{
		for(int i=ai;i>=1;i--){
			cout<<a[i];
		}
	}
	return 0;
} 
