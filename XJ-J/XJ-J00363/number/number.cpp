#include<iostream>
#include<cstring> 
#include<algorithm>
using namespace std;

const int N = 1e8;
int m[N];
int t[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n;
	n = s.size();
	int l = 0;
	int k;
	for(int i = 0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			k = s[i]-'0';
			t[k]++; 
		}	
	}
	
	for(int i = 9;i>=0;i--){
		for(int j = 1;j<=t[i];j++){
			cout<<i;
		}
	}
		
	
	
	
	return 0;
} 
