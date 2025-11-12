#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	vector<int>x;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			x.push_back(s[i]-48);
		}
	}
	sort(x.begin(),x.end(),cmp);
	for(int i=0;i<x.size();i++){
		cout<<x[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}