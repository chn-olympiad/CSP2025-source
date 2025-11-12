#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s,i=1;
	cin>>s;
	if(s<=10) cout<<s;
	else{
		while(s>0){
			a[i]=s%10;
			s=s/10;
			i++;
		}
		for(int j=1;j<=i;j++){
			for(int k=1;k<=i;k++){
				if(a[k]<a[k+1]){
					int a1=a[k];
					a[k]=a[k+1];
					a[k+1]=a1;
				}
			}
		}
		for(int j=1;j<=i-1;j++){
			cout<<a[j];
		}
	}
	return 0;
}