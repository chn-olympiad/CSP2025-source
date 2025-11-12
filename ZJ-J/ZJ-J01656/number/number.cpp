//powered by Jin_Yichen
//Luogu UID:727101
#include<bits/stdc++.h>
using namespace std;
string str;
vector<char> vec;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(isdigit(str[i]))vec.push_back(str[i]);
	}
	sort(vec.begin(),vec.end());
	for(int i=vec.size()-1;i>=0;i--){
		cout<<vec[i];
	}
	return 0;
}
