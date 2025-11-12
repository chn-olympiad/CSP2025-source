#include <bits/stdc++.h> 
using namespace std;
string s,ans;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>s;
	for(int i=1;i<=s.size();i++){
		if(s[i]=0){
			ans+=0;	
		}	
		else if(s[i]=1){
			ans+=1;
		}
		else if(s[i]=2){
			ans+=2;
		}
		else if(s[i]=3){
			ans+=3;
		}
		else if(s[i]=4){
			ans+=4;
		}
		else if(s[i]=5){
			ans+=5;
		}
		else if(s[i]=6){
			ans+=6;
		}
		else if(s[i]=7){
			ans+=7;
		}
		else if(s[i]=8){
			ans+=8;
		}
		else if(s[i]=9){
			ans+=9;
		}
		for(int j=0;j<=sizeof(ans);j++){
			for(int k=0;k<=j;k++){
				if(ans[i]>ans[i-1]){
					ans[i-1]=ans[i];
				}
				else{
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
