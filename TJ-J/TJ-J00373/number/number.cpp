#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	int lenth=str.size();
	vector<int>number;
	for(int i=0;i<lenth;i++){
		if(str[i]=='0'||str[i]=='1'||str[i]=='2'||str[i]=='3'||str[i]=='4'||str[i]=='5'||str[i]=='6'||str[i]=='7'||str[i]=='8'||str[i]=='9'){
			int a=str[i]-'0';
			number.push_back(a);
		}
	}
	sort(number.begin(),number.end(),greater<int>());
	int size=number.size();
	for(int i=0;i<size;i++){
		cout<<number[i];
	}
	return 0;
}
