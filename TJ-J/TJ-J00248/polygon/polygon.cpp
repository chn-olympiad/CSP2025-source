#include<bits/stdc++.h>
using namespace std;
//string n;
int a[1000];
bool cmp(int a,int b){
	return a>b;
}
int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<0;
		return 0;	
	}if(n==2){
		cout<<0;
		return 0;
	}if(n==3){
		int yes=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(j==i) continue;
				else{
					for(int k=0;k<n;k++){
						if(k==i || k==j) continue;
						else{
							if(a[j]+a[i]>a[k]){
							}else{
//								cout<<i<<j<<k;
								yes=0;
							}
						}
					}
				}
			}
		}
		if(yes){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
//	cout<<"I don,t know";
	return 0;
}
