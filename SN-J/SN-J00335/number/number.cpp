#include<bits/stdc++.h>
using namespace std;
int a[100],sum=0;
int main(){
	freopen("member3.in","r",stdin);
	freopen("member3.out","w",stdout);
	string s;
	cin>>s;
	int p=s.size();
	for(int i=0;i<p;i++){
		if(s[i]>=48&&s[i]<=57){
			a[sum]=s[i]-48;
			sum++;
		}
	}
	sort(a,a+1+sum);
	for(int i=sum;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
