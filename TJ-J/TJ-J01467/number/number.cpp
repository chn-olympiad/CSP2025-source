#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("number1.in","r",stdin);
	freopen("number1.ans","w",stdout);
	char s;
	cin>>s;
	if(s<10){
		cout<<s;
	}
	for(int i=0;i<=s;i++)
		cout<<s;
		
	} 
	dclose("number1.in","r",stdin);
	dclose("number1.ans","w",stdout);
	return 0;
}
