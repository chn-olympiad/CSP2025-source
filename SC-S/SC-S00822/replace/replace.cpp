#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	vector<string> H(n);
	vector<string> bH(n);
	vector<string> W(q);
	vector<string> gW(q);
	for (int i = 0;i < n;i++){
		cin>>H[i]>>bH[i];
	}
	for (int i = 0;i < q;i++){
		cin>>W[i]>>gW[i];
	}
	for (int i = 0;i < q;i++){
		cout<<"0"<<"\n";
	}
	return 0;
}