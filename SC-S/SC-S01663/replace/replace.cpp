#include<bits/stdc++.h>
using namespace std;
unordered_map<string,string> rpment;
string keyt,valuet;
unsigned int n,q;

void answering(){
	string que;
	cin >> que;
	cout << 0 << endl;
	
}

int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin >> n >> q;
	for(int i=0;i<n;i++){
		cin >> keyt >> valuet;
		rpment[keyt] = valuet;		
	}
	for(int i=0;i<q;i++){
		answering();
	}
	
	
	
	return 0;
}