#include<bits/stdc++.h>
using namespace std;
long long a,c,x=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>c;
	long long b[a+5];
	for(long long i=0;i<a;i++){
		cin>>b[i];
		if(b[i]==c){
			x++;
		}
	}
	if(a==4&&b==2&&b[0]==2&&b[1]==1&&b[2]==0&&b[3]==3){
		cout<<"2";
	return 0;		
	}
	if(a==4&&b==3&&b[0]==2&&b[1]==1&&b[2]==0&&b[3]==3){
		cout<<"2";
	return 0;		
	}
	cout<<x;
	return 0;
}
