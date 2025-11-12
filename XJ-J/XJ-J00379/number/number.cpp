#include<bits/stdc++.h>
using namespace std;
string s;
int t[15],sum1,sum,zh; 
int main(){
	 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<=len-1;i++){
		t[int(s[i])-48]++;
	}
	for(int i=0;i<=9;i++){
		sum+=t[i];
	}
	for(int i=9;i>=0;i-- ){
		for(int j=1;j<=t[i];j++){
			cout<<i;
		}	
	}
	return 0; 
} 
