#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in",'r',stdin);
	freopen("number.out",'w',stdout);
	string s;
	cin>>s;
	int n=0;
	string ans[s.size()];
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			ans[n]=s[i];
			n+=1;
		}
	}
	string arr;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(ans[i]>ans[j]){
				arr=ans[i];
				ans[i]=ans[j];
				ans[j]=arr;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<ans[i];
	}
	return 0;
} 
