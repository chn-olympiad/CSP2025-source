#include<bits/stdc++.h>
using namespace std;
int d[210];
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int a,s;
	cin>>a>>s;
	for(int i=1;i<=a*s;i++){
		cin>>d[i];
	}
	int f=d[1];
	int ma;
	sort(d+1,d+(a*s)+1);
	for(int i=1;i<=a*s;i++){
		if(d[i]==f){
			ma=a*s-i+1;
			break;
		}
	}
	int t=ma/s;
	int t1=ma%s;
	if(t1!=0)t++;
	if(t%2==0){
		if(t1==0){
			t1=ma;
		}
		else{
			t1=s-t1+1;
		}
	} 
	else{
		if(t1==0){
			t1=s;
		}
	}
	cout<<t<<" "<<t1;
	return 0;
}
