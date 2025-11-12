#include<bits/stdc++.h>
using namespace std;
int num[1000005]={},sum=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[++sum]=s[i]-48;
		}
	}
	sort(num+1,num+sum+1);
	for(int i=sum;i>=1;i--){
		cout<<num[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

