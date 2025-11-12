#include <bits/stdc++.h>
using namespace std;
const long long MAX=1e6+5;
long long a[MAX];
long long sum,ans;//ans统计最大数 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			sum++; 
		}
	}
	for(int i=0;i<sum;i++){
		for(int j=0;j<n;j++){
			ans=max(ans,a[j]);
		}
		cout<<ans;
		for(int j=0;j<n;j++){
			if(ans==a[j]){
				a[j]=0;
				break;
			}
		}
		ans=0;
	}
	return 0;
}
