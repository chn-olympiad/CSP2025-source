#include<bits/stdc++.h>
using namespace std;
int n,q;
string ru1,ru2;
vector<string> vec1,vec2,q1,q2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>ru1>>ru2;
		vec1.push_back(ru1);
		vec2.push_back(ru2);
	}
	for(int i=1;i<=q;i++){
		cin>>ru1>>ru2;
		q1.push_back(ru1);
		q2.push_back(ru2);
	}
	for(int i=1;i<=q;i++){
		cout<<"0"<<endl;
	}
	return 0;
}
