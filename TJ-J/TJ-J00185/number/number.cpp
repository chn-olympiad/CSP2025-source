#include<iostream>
#include<cstring>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);	
	freopen("number.out","w",stdout);
	cin>>s;
	int a;
	for(int i=0;i<=s.size();i++){
		if(s[i+1]>s[i]){
			a=s[i];
			s[i]=s[i+1];
			s[i+1]=a;
		}
	}
	cout<<s;

	return 0;
}
