#include<bits/stdc++.h>
using namespace std;
string str;
vector<int> ve;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	int len=str.length();
	for(int i=0;i<len;i++){
		if(str[i]>='0'&&str[i]<='9'){
			ve.push_back(str[i]-48);
		}
	}
	sort(ve.begin(),ve.end());
	for(int i=ve.size()-1;i>=0;i--){
		cout<<ve[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
