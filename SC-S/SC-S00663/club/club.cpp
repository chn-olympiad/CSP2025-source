#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream inFile("club.in");
	ofstream onFile("club.out");
	string s1;
	getline(inFile,s1);
	int b=s1[0]+1-'1';
	while(b!=0){
		string s;
		getline(inFile,s);
		int a=s[0]-'1';
		a++;
		char c[3][3];
		for(int i=0;i<a;i++){
			string v;
			getline(inFile,v);
			for(int j=0;j<5;j+=2){
				c[i][j]=v[j];
			}	
		}
		
		onFile<<re<<endl;
		b--;
	}	
	inFile.close();
	onFile.close();
	return 0;
}