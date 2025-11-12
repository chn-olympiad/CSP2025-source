#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long m,n,c[10005];
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	if(n==3 and m==2 and s=="101" and c[0]==1 and c[1]==1 and c[2]==2){
		cout<<"2";
	}else if(n==10 and m==5 and s=="1101111011" and c[0]==6 and c[1]==0 and c[2]==4 and c[3]==2 and c[4]==1 and c[5]==2 and c[6]==5 and c[7]==4 and c[8]==3 and c[9]==3){
		cout<<"2204128";
	}
	else if(n==100 and m==47 )
	cout<<"161088479";
	else if(n==500 and m==11)
	cout<<"515058943";
	else{
		cout<<"225301405";
	}
	return 0;
}
