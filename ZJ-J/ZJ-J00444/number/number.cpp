#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	vector<int> a(10,0);
	cin>>s;
	for(auto &x:s){
		if(x>='0'&&x<='9'){
			a[x-'0']++;
		}
	}
	bool b=0;
	for(int i=9;i>=0;i--){
		if(i==0&&a[i]){
			if(b==0){
				cout<<"0";
			}else{
				for(int j=1;j<=a[i];j++) cout<<i;
			}
			continue;
		}
		if(a[i]) b=1;
		for(int j=1;j<=a[i];j++) cout<<i;
	}
	return 0;
}
