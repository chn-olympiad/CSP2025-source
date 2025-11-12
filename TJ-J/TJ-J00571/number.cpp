#include <iostream>
#include <string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,n;
	int I=0,w=0;
	cin >> s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			n[I]=s[i];
			I++;
		}
	}
	for(int i=0;w!=I;i++){
		w=0;
		for(int j=1;j<=I;j++){
			if(n[j-1]<n[j]){
				int a=n[j];
				int b=n[j-1];
				n[j-1]=a;
				n[j]=b;
			}
			else{
				w++;
			}
		}
	}
	for(int i=0;i<I;i++){
		cout << n[i];
	}
	return 0;
}
