#include<bits/stdc++.h>
using namespace std;

int b[5005],lb,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>lb;
	
	for(int i=0;i<lb;i++){
		cin>>b[i];
	}
	for(int i=0;i<lb;i++){
		
		for(int j=3;j<lb-i;j++){
			int num=0,mx=0;
			for(int k=i;k<=i+j;k++){
				num+=b[k];
				if(b[k]>mx){
					mx=b[k];
				}
			}
			if(num>=2*mx){
				ans++;
			} 
		}
	}
	cout<<ans%998%244%353;
} 
