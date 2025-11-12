#include<bits/stdc++.h>
using namespace std;
string a;
int b[15];
long long sum,s,n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	 n=a.size();
	for(int i=0;i<=n-1;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[a[i]-'0']++;
			s++;
		} 
	}
	if(s==b[0]){
		cout<<"0";
		return 0; 
	}
	sum=0;
	for(int i=9;i>=0;i--){
		for(int j=1;j<=b[i];j++){
			sum=sum*10+i;
		}
	}
	cout<<sum;
	return 0;
} 
