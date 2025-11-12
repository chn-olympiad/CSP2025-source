#include<bits/stdc++.h>
using namespace std;
string n;
int main(){
 	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			cout<<n<<" ";
		}
	}
	return 0;	
}
