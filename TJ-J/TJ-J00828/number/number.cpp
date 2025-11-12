#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[1000005],n,m=0;
	string s;
	cin>>s; 
	n=s.size();
	if(n==1){
		cout<<s;
		return 0;
	} 
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[m]=s[i];
			m++;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<=i;j++){
			if(a[i]>a[j]) swap(a[i],a[j]);
		}
	}
	for(int i=0;i<m;i++) cout<<a[i]-'0';
	return 0;
} 
