#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream("number.in");
	ofstream("number.out");
    int n,m,s[100],num=0,key=0,n1,m1;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
    	cin>>s[i];
	}
	for(int i=100;i>=0;i--){
		for(int j=0;j<n*m;j++){
			if(s[j]==i){
			    if(j==0){
					key=1;
				}
				num++;
				break;
			}
		}
		if(key==1){
		    m1=(num-1)/n+1;
		    n1=num%n;
		    if(num%n==0){
		    	n1=n;
			}
			break;
		}
	}
	cout<<m1<<" ";
	if(m1%2==1){
		cout<<n1;
	}
	else{
		cout<<n-n1+1;
	}
	return 0;
}
