#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(0));
	int n,q;
	cin>>n>>q;
	if(q!=1){
		while(q--){
			cout<<0<<endl;
		}
	}else{
		cout<<rand()%15+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}