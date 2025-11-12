#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	vector<int> num;
	int a=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num.push_back(int(s[i]-'0'));
			a++;
		}
	}
	for(int i=0;i<num.size();i++){
		for(int j=0;j<num.size();j++){
			if(num[j]<num[j+1]){
			int a=num[j];
			num[j]=num[j+1];
			num[j+1]=a;
		}
		}
	}
	for(int i=0;i<num.size();i++){
		cout<<num[i];
	}
	return 0;
}
