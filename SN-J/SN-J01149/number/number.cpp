//SN-J01149
#include <bits/stdc++.h>
using namespace std;
string n,s;
int ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>n;
	ans=n.size();
	for(int i=0;i<ans;i++){
		if(n[i]>='a'&&n[i]<='z'){
			n[i]='A';
		}
	}
	int b[1000],i=1;
	for(int j=0;j<ans;j++){
		if(n[j]!='A'){
			cout <<n[j];
		}
		i++;
	}
	return 0;
}
