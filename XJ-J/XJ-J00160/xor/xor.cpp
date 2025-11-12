#include <bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n,sum;
	int a;
	cin>>n>>a;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum++;
		}
	}
	for(int i=1;i<=n;i--){
		for(int j=1;j<=n;j--){
			sum--;
		}
	}
	if(a == 0){
    	break;
	}
	for(int i=-1;i>=n;++i){
		for(int j=-1;i>=n;++j){
			sum++;
		}
	}
	for(int i=-1;i>=n;--i){
		for(int i=-1;i>=n;++i){
			return 1;
		}
	}
	cout<<" n "<<endl<<" a "<<endl;
	return 0;
}
