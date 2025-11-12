#include<bits/stdc++.h>
using namespace std; 

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string b;
	cin>>b;
	int a[100001],ii=0;
	memset(a,-1,sizeof(a));
	for(int i=0;i<b.size();i++){
		if(b[i]>='0'&&b[i]<='9'){
			a[ii]=b[i]-'0';
		}
		if(a[ii]>-1){
			ii++;
		}
	}
	for(int i=0;i<ii;i++){
		for(int j=0;j<ii;j++){
			if(a[j]<a[j+1]){
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(int i=0;i<ii;i++){
		cout<<a[i];
	}
	return 0;
}

