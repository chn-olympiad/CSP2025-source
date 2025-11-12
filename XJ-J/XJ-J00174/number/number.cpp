#include <bits/stdc++.h>
using namespace std;
int main(){
	
	int n,d=1,ans=0;
	char s[10000];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	while(s[d]>0){
			if(s[d]<s[d+1]){
				ans=s[d+1];
			}else if(s[d]>s[d+1]){
				ans=s[d]; 
			}
			d++;	
		}
		cout<<ans;
	return 0;
}
