#include<bits/stdc++.h>
using namespace std;
int n,q;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(NULL));
	cin>>n>>q;
	for(int i=1; i<=q; i++)cout<<rand()%(n+1);
}
