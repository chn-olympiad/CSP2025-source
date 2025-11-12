#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[10^7];
	cin>>a;
	char num[10^7];
	int k=0;
	for(int i=0;i<strlen(a)*3;i++){
		if(a[i]>='0'&&a[i]<='9'){
			num[k]=a[i];
			k+=1;
		}
	}
	
	for(int i=0;i<k;i++){
		for(int j=0;j<k+1;j++){
			if(num[i]>num[j]){
				int t=num[i];
				num[i]=num[j];
				num[j]=t;
			}
		}
	}

	for(int i=0;i<=k;i++){
		if(num[i]>='0'&&num[i]<='9'){
			cout<<num[i];
		}
		
		
	}
	
	return 0;
}
