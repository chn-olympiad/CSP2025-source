#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,q=0,w=0;
	cin>>n>>k;
	int x[n+5];
	for(int i=0;i<n;i++){
		cin>>x[i];
		if(x[i]==1){
			q++;
		}else if(x[i]==0){
			w++;
		}
	}
	if(k==1){
		cout<<q;
	}else if(k==0){
		q/=2;
		cout<<q+w;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}