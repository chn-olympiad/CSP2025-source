#include<bits/stdc++.h>
using namespace std;
int a[500050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,c=0,b=0;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
	    cin >> a[i];
		if(a[i]==1){
			c++;
		}
		else{
			b++;
		}	
	}
    if(k==0){
    	cout << b+c/2;
	}
	else{
		cout << c;
	}
	return 0;
}
