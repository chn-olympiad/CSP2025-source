//孙浩桐SN-J00275西安市曲江第一中学; 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout); 
	string s;
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			if(s[i]>=s[i+1]){
				cout<<s[i];
			}
			else{
				cout<<s[i+1];
			}
		}
	}
	return 0;
}
