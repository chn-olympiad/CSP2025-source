//SN-J00427 强立琨 西安市交大附中浐灞右岸学校 
#include<bits/stdc++.h>
using namespace std;
long long big,ans,n,a,b,c;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	if(n==3){
		cin>>a>>b>>c;
		ans=a+b+c;
		big=max(a,b);
		big=max(big,c);
		if(big>=ans-big){
			cout<<0;
		}
		else{
			cout<<1;
		}
	}
	return 0;
}
