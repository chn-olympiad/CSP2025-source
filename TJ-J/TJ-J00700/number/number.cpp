#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
using namespace std;
string s;//scanf
priority_queue<char> a;//numbers
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9') a.push(s[i]);
	}
	while(!a.empty()){
		cout<<a.top();
		a.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//win
//sh4ngshnruoshui 
