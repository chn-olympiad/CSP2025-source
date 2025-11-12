#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
	int b[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long sum=0;
	string s,a;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a+=s[i];
			sum++;
		}
	}
	for(int i=0;i<s.size();i++){
		b[i+1]=a[i]-48;
	}
	long long c=s.size();
	sort(b+1,b+sum+1);
	for(int i=sum;i>=1;i--){
		cout<<b[i];
	}
	return 0;
} 
