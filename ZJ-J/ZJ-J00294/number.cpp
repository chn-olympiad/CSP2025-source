#include<bits/stdc++.h>
using namespace std;
vector<int> v;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			v.push_back(s[i]-'0');
		}
	}
	sort(v.begin(),v.end(),&cmp);
	if(v[0]==0) printf("0");
	else{
		for(int num:v){
			printf("%d",num);
		}
	}
	return 0;
}