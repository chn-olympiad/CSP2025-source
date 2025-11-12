#include<bits/stdc++.h>
using namespace std;
int a;
vector<int>e;
string b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	for(int i=0;i<b.size();i++){
		if(b[i]>='0' && b[i]<='9'){
			e.push_back(b[i]-48);
		}
	}
	sort(e.begin(),e.end());
	for(int i=e.size()-1;i>=0;i--){
		cout<<e[i];
	}
	return 0;
}
