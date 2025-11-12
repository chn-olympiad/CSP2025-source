#include<bits/stdc++.h>
using namespace std;

char a[3000010][3000010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int t,n;
	cin>>t>>n;
	for(int i=1;i<=t;i++){
		for(int k=1;k<=n;k++){
			cin>>a[i][k];
		}
	}
	while(n--){
		cout<<endl;
	}	
	return 0;
}
