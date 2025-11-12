#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","W",stdout);
	string s;
	int ans[1005]={0};
	int mx[1005]={-1};
	cin>>s;
	int len=s.size();
	for(int i=1;i<=len;i++){
		if(s[i]>'a'&&s[i]<'z'){
			if(s[i]<=10||s[i]%10==0){
				cout<<s;
				break;
			}
			else if(s[i]%1==s[i]){
				ans[i]=s[i];
				if(ans[i]>mx[i]){
					mx[i]=ans[i];
					cout<<mx;	
				}	
			}
		}
	} 
	return 0;
}
