#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,d,e,f,re;
	cin>>t>>n;
    int total[100005];
    int c=0;
    int a[3][100005];
    int ans1=0,ans2=0,ans3=0,ans=0;
    int b[10000];
    for(int g=1;g<=t;g++){
	for(int i=1;i<=3;i++){
		for(int j=1;j<=n;j++){
		cin>>a[i][j];
	}
	}
	if(n=2){
		int i=a[1][1]+a[2][2];
		int j=a[1][1]+a[3][2];
		int h=a[2][2]+a[3][3];
	if(i>j){	
			if(j<h){
				if(i>h){
					cout<<i;
				}else{
					cout<<h;
				}
			}else{
				cout<<i;
			}
		}else{
			if(j>h){
			cout<<j;
			}else{
				cout<<h;
			}
		}
	   }
		
		
    for(int i=1;i<=n;i++){
		d=a[1][i];e=a[2][i];f=a[3][i];
		if(d>e){	
			if(e<f){
				if(d>f){
					total[i]=d;
				}else{
					total[i]=f;
				}
			}else{
				total[i]=d;
			}
		}else{
			if(e>f){
				total[i]=e;
			}else{
				total[i]=f;
			}
		}
	   }
	    for(int i=1;i<=n;i++){
	    	c=total[i]+c;
		}
		cout<<c;
	}
	return 0;
} 
