#include<bits/stdc++.h>
using namespace std;
int n,k;
int s;
int s1,s2;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	while(n--){
		cin>>s;
		if(s==0){
			++s1;
		}
		else{
			++s2;
		}
	}
	if(k==0){
		cout<<s1;
	}	
	else{
		cout<<s2;
	}
	return 0;
}
