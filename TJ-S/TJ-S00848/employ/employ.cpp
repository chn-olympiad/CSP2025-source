#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,s=0;
    cin>>n>>m;
    int arr[1005]={};
    string a;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
    for(int i=1;i<=n;i++){
    	cin>>arr[i];
    }
	for(int i=1;i<=n;i++){
		if(a[i]!=0){
			s++;
		}else if(a[i]!=0){
			s+=0;
		}
	}
	cout<<s-1;
	
 return 0;	
}
