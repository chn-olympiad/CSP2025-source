#include<iostream>
using namespace std;
char a1[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a,b;
	cin>>a;
	for(int i = 0 ;i<a.size();i++){
		if('0'<=a[i]&&a[i]<='9'){
			a1[i] = a[i];	
		}
	}
	int t;
	char s = '0'-1;
	for(int i = 0 ;i<a.size();i++){
		for(int j = 0 ;j<a.size();j++){
			if(a1[j]>s){
				s= a1[j];
				t = j;
			}
		}
		if(s != '0'-1){
			a1[t] = '0' -1;
			b += s;
			s = '0'-1;
		}
	}
	cout<<b;
	return 0;
}
