#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string str1[N],str2[N],line1,line2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>str1[i]>>str2[i];
	while(q--){
		cin>>line1>>line2;
		cout<<line2.size()/2;
	}
	return 0;
}
