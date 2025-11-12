#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a1,a2,a3,s=0,c1=0,c2=0,c3=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a1>>a2>>a3;
			if(a1>a2 && a1>a3){
				c1+=1;
				if(c1>n/2){
					s+=max(a2,a3);
				}else{
					s+=a1;
				}
			}else if(a2>a1 && a2>a3){
				c2+=1;
				if(c2>n/2){
					s+=max(a1,a3);
				}else{
					s+=a2;
				}
			}else if(a3>a2 && a3>a1){
				c3+=1;
				if(c3>n/2){
					s+=max(a2,a1);
				}else{
					s+=a3;
				}
			}
		}cout<<s<<endl;
		s=0;
	}
	return 0;
}
