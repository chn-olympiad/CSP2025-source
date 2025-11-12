//贾腾翔，SN-J01008,高新第一学校 
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number","r",stdin);
	freopen("number","w",stdout);
	int s;
	int n=0;
	int r=0;
	int num=0;
	cin>>s;
	for(int i=1;i<=s;i++){
		n=s%10;
		if(n>r){
			num+=n*10;
			num+=r;
		}
		else{
			num+=r*10;
			num+=n;
		}
		r+=n; 
		s/=10;
	}
	cout<<num;
	return 0; 
}
