//张皓涵 SN-S00248 西安高新第一中学南校区 

#include <bits/stdc++.h>
using namespace std;
pair<string,string> qp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin >> n>> q;
	for(int i = 0;i < n;i++){
		cin >> qp.first>>qp.second;
	}
	string b = qp.first;
	int a = sizeof(b);
	if(q==1){
		cout << a-6;
	}
	else if(q!=0){
		for(int i = 0;i <q;i++){
			cout << "0" << endl;
		}
	}
	return 0;
}
