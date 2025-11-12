#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	int n=s.size();
	string num;
	for(int i=0;i<n;i++){
		if(s[i]<96||s[i]>122){
			num+=s[i];			
		}
	}
	for(int i=0;i<num.size();i++){
		for(int j=i+1;j<num.size();j++){
			if(num[i]<num[j]){
				int a=num[i];
				num[i]=num[j];
				num[j]=a;
			}
		}
	}
	cout<<num;
	return 0;
}