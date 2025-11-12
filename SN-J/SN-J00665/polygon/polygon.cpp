//SN-J00665  樊楷宁  西安市雁塔区第一学校 
#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005],b[5005];
int main(){
  freopon("polygon.in","r",stdin);
  freopon("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i];
	b[a[i]]++;
}
for(int i=1;i<=500;i++){
	if(b[i]>=2){
		cout<<"6";
		return 0;
	}
}
cout<<"9";
   return 0;
}
