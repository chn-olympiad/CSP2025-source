#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.length();
	int a[10]={0};
	for(int i=0;i<len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			int huyd=s[i]-'0';
			a[huyd]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout<<i;
		}
	}
	cout<<endl;
	return 0;
}
