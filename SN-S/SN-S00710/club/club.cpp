#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	int t;
	for(int i = 0;i<n;i++){
		int t;
		cin>>t;
		int a1[t],a2[t],a3[t];
		for(int j = 0;j<t;j++){
			cin>>a1[j]>>a2[j]>>a3[j];
		}
		int b1=0,b2=0,b3=0,f=0;
		for(int j = 0;j<t;j++){
			int a[3]={a1[j],a2[j],a3[j]};
			sort(a,a+3);
			int u =a[2];
			if(b1<=t/2||b2<=t/2||b3<=t/2){
				f+=u;
			}else{
				if(u==a1[j])a1[j]*=-1;
				if(u==a2[j])a2[j]*=-1;
				if(u==a3[j])a3[j]*=-1;
			}
		}
		cout<<f<<endl;
	}
	return 0;
}
