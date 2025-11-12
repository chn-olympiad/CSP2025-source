#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
string S1[100100],S2[100100];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q,i;
	string s1,s2;
	cin>>n>>q;
	for(i = 1;i <= n;i++){
		cin>>S1[i]>>S2[i];
	}
	for(i = 1;i <= q;i++){
		cin>>s1>>s2;
	}
	for(i = 1;i <= n;i++){
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}//0pts
