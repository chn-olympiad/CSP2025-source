#include<bits/stdc++.h>
using namespace std;

bool ___(int a,int b);

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	//49
	vector<int> vec;
	for(int i=0;i<str.size();i++){
		if(str[i]>=48&&str[i]<=57){
			vec.push_back(str[i]-48);
		}
	}
	sort(vec.begin(),vec.end(),___);
	for(int i=0;i<vec.size();i++) cout<<vec[i];
	return 0;
}

bool ___(int a,int b){
	return a>b;
}
