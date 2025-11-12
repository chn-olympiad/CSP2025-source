#include<bits/stdc++.h>
using namespace std;
long long m=0;
int main(){
//	freopen("number2.in","r",stdin);
//	freopen("number2.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s,a;
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[m]=s[i];
			m++;
		}
	}
	
	for(int j=0;j<m;j++){
		if(a[j]<a[j+1]){
			int temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
	}
	for(int l=0;l<m;l++){
		cout<<a[l];
	}
	return 0;
}
