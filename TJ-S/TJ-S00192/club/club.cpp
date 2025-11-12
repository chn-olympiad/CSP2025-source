#include<bits/stdc++.h>
using namespace std;
int a1[100005];
int a2[100005];
int a3[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club,out","w",stdout);
	int t,n;
	cin>>t;
	int sum[t+5];
	for(int j=1;j<=t;j++){
		cin>>n;
		int m1=0;
		int m2=0;
		int m3=0;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a1[i]>=a2[i]&&a1[i]>=a3[i]){
				m1=m1+a1[i];
			}else if(a2[i]>=a1[i]&&a2[i]>=a3[i]){
				m1+=a2[i];	
			}else if(a3[i]>=a2[i]&&a1[i]<=a3[i]){
				m1+=a3[i];
			}	
		}
		sum[j]=m1;
	}
	for(int j=1;j<=t;j++){
		if(j==t){
			cout<<sum[j];
		}else{
			cout<<sum[j]<<endl;	
		}
	}
	return 0;
}
