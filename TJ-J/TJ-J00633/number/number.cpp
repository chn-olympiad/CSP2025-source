#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	bool flag=true;
	long long a[100005],nu[100005];
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i];
		}else{
			flag=false;
		}
	}
	long long n=s.size();
	if(flag){
		sort(a,a+n,cmp);
		for(long long i=0;i<n;i++){
			cout<<a[i]-48; 
		}
		return 0;
	}
	long long t=0;
	sort(a+1,a+1+n,cmp);
	for(long long i=0;i<n;i++){
		if(a[i]-48<=0){
			t=i;
		}
	}
	for(long long i=0;i<t-1;i++){
		nu[i]=a[i]-48;
	}
	long long p=t-2;
	sort(nu,nu+p+1,cmp);
	for(long long i=0;i<=p;i++){
		if(nu[i]>=0){
			cout<<nu[i];
		}
	}
	
	return 0;
}
