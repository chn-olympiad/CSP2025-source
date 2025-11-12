#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdin);
	string s,g;
	cin>>s;
	int sum=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
			g+=s[i];
			sum+=1; 
		}
	}
	sort(g.begin(),g.end());
	for(int i=sum-1;i>=0;i--){
		cout<<g[i];
	}
	
	
	
	
	
	
	
	
	
	
	return 0;
}
