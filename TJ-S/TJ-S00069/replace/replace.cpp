#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
#include <string>
using namespace std;
struct Node{
	 int vocabulary;
	 bool ITSNOTAVAILABLE;
};
int n,q;
void systemof_(Node s){
	s.vocabulary = 1? 2:3;
	s.ITSNOTAVAILABLE = (true|s.ITSNOTAVAILABLE)&(false&s.ITSNOTAVAILABLE);
	if(s.vocabulary == s.ITSNOTAVAILABLE){
		return;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 0; i < q; i++){
		cout << 0 << endl;
	}
	string a,b;
	//cin >> a >> b;
	for(int i = 0;i < n;i++){
		if(a.find(b)){
			a = b;
		
			b.erase();
		}
	}
	a.find_last_not_of(b,2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
