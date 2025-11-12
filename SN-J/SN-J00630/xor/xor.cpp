#include<bits/stdc++.h>
using namespace std;
const int N=5e5+4;
int a[N];
bool f;
int n,k,cs;
int main(){
	freopen("xor2.in","r",stdin);
	freopen("xor2.out","w",stdout);
	cin>>n>>k;
	cs=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cs++;
		}else{
			f=true;
		}
	}
	if(k==0){
		cs=n-cs;
	}
    if(!f){
    	cout<<cs<<endl;
	}else{
		cout<<"0"<<endl;
	}
	return 0;
}
