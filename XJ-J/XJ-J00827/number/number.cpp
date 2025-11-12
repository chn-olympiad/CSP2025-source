#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int num[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cot=0;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0 && s[i]-'0'<=9){
			cot++;
			num[cot]=s[i]-'0';
		}
	}
	sort(num+1,num+1+cot,cmp);
	for(int i=1;i<=cot;i++){
		cout<<num[i];
	}
	return 0;
}
