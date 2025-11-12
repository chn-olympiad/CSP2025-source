#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long n=s.size(),ans=0,j=0;
	for(long long i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=(int)s[i]-48;
			ans++,j++;
		}
	}
	sort(a,a+ans);
	for(long long i=ans-1;i>=0;i--) cout<<a[i];
	return 0;
}
