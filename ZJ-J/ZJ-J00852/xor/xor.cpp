#include<bits/stdc++.h>
using namespace std;
int k,n,l[500005],f[500005],t;
int a;
struct node{
	int z,y;
};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>t;
		l[i]=l[i-1]^t;
		//cout<<l[i]<<" ";
	}//cout<<endl;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		for(int j=1;j<=i;j++){
			t=l[i]^l[j-1];
			if(t==k){
				t=l[i]^l[j-1];
				//cout<<"--"<<t<<"--";
				f[i]=max(f[i],f[j-1]+1);
			}
			
			//cout<<f[i]<<" ";
		}//cout<<endl;
	}
	cout<<f[n];
	return 0;
}
