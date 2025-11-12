#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,b;int d,a[1000]={0};
	ifstream fin("number.in");
	ofstream fout("number.out");
	fin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[d]=s[i];
			d++;
		}
		
	}
	sort(a,a+d);
	for(int i=d-1;i>=0;i--){
		fout<<a[i]-48;
	}
	fin.close();
	fout.close();
	return 0;
}
