#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int a,b,c;
	for (int i=1;i<=a;i++){
		getline(cin,c);
	}
	cin>>a>>b;
	for (int i=1;i<=b;i++){
		cout<<rand()%4+1<<" ";
	}
}
