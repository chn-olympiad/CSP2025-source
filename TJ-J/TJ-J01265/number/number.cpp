#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s; 
	ll b=s.length();
	ll a[1010] = {0};
	if(s=="1"||s=="2"||s=="3"||s=="4"||s=="5"||s=="6"||s=="7"||s=="8"||s=="9"||s=="10"||s=="0"){
		cout<<s;
	}
	for(int i=0;i<=b;i++){
		if(i>0){//
			cin>>a[i];
		}
	}
	while(true){
		ll max_my = a[1];
		ll jg[1011]={0};
		ll z=a.length();//
		for(int i=1;i<=z;i++){
			if(a[i+1]>a[i]){
				max_my=a[i+1];
				jg[i]=max_my;
			}
		}
		break;
	}
	//我服了我在写什么1t都不会完蛋了 
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
