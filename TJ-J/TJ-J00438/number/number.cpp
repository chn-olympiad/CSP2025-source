#include<bits/stdc++.h>
using namespace std;
string x;
string a;
int num,k,m;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>x;
	for(int i=0;i<x.size();i++){
		if(x[i]<=57 && x[i]>=48){
			a[i]=x[i];
			num+=1;
		}
	}
	for(int i=0;i<num;i++){
		for(int j=i;j<num;j++){
			if(i!=j){
				if(a[j]>a[i]){
					k=a[j];
					m=a[i];
					a[i]=k;
					a[j]=m;
					k=0;m=0;
				}
			}
		}
	}
	for(int i=0;i<num;i++){
		cout<<a[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
