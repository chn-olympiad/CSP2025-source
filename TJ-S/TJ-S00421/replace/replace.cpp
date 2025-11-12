#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand((unsigned int)time(NULL));
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		cout<<rand()%200;
	}
	
	return 0;
}
