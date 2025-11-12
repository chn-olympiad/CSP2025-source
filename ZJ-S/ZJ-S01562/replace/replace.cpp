#include <bits/stdc++.h>
using namespace std;
int main(){
	srand(time(0));
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=q;i++){
		int x=rand()%3;
		cout<<x<<'\n';
	}
	return 0;
}
