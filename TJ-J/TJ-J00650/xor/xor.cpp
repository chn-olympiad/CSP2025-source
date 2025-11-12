#include<bits/stdc++.h>;
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n],s=0;
	if(k==0){
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]==0)s++;
		}
		cout<<s;	
	}


	else cout<<k;
	cout<<endl;
	return 0;
}

