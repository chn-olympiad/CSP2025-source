#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n,fa=0;
	cin>>m>>n;
	string hard;
	cin>>hard;
	for(int a=0;a<hard.size();a++){
		if(hard[a]!='0'){
			fa=1;
		}
	}
	if(fa==0){
		cout<<pow(m,m);
	}
	return 0;
}
