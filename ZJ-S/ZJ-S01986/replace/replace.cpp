#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	srand(time(0));
	while(q--){
		cout<<rand()%n<<'\n';
	}
}
