#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>s;
	vector<int>a(15);
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int x=s[i]-'0';
			a[x]++;
		}
		
	}
	
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=0;j<a[i];j++){
				cout<<i;
			}
		}
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
