#include<bits/stdc++.h>
using namespace std;
bool com(char a,char b){
	return (int)a>(int)b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	vector<char> num;
	for(int i=0;i<l;i++){
		if(isdigit(s[i])){
			num.push_back(s[i]);
		}
	}
	sort(num.begin(),num.end(),com);
	l=num.size();
	for(int i=0;i<l;i++){
		cout<<num[i];
	}
	return 0;
}
