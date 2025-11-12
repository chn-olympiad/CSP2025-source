#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	if(a.size()==1) cout<<a;
	else{
		if(a[2]>a[1]){
			for(int i=a.size();i>0;i--){
				cout<<a[i];
			}
		}
		else cout<<a;
	}
	return 0;
}
