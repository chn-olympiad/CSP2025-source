#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string a;
int n,s[N],sum,sum0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	
	cin>>a;
	n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]=='0'){
			sum0++;
		}else if(a[i]>='1'&&a[i]<='9'){
			sum++;
			s[sum]=a[i]-'0';
		}
	}
	sort(s+1,s+sum+1);
	for(int i=sum;i>=1;i--){
		cout<<s[i];
	}
	for(int i=1;i<=sum0;i++){
		cout<<0;
	}
	return 0;
}
