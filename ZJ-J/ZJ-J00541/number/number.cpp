#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	vector<int> number;
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9')number.push_back(str[i]-'0');
	}
	sort(number.begin(),number.end());
	for(int i=number.size()-1;i>=0;i--){
		printf("%d",number[i]);
	}
	return 0;
}
