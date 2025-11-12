#include<bits/stdc++.h>
using namespace std;
vector<int>vec;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string x;cin>>x;
	for(int i=0;i<x.size();i++)
		if(isdigit(x[i]))
			vec.push_back(x[i]-48);
	sort(vec.begin(),vec.end());
	for(int i=vec.size()-1;i>=0;i--)
		cout<<vec[i];cout<<'\n';
	return 0;
}
/*
8:37 100pts
*/
