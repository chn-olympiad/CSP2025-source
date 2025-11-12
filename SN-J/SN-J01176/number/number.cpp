#include<bits/stdc++.h>
using namespace std;


int num[1000005];
int tong[110];

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a="";
	string b="";
	string ans="";
	cin>>a;
	int la=a.size();
//	cout<<la<<endl;
	
	
	//9:13
	for(int i=0;i<la;i++){
		if((a[i]-'0')>=0 && (a[i]-'0')<=9){
			b+=a[i];
		}
	}
	int lb=b.size();
	for(int i=0;i<lb;i++){
		tong[b[i]]++;
	}
	for(int i=60;i>=45;i--){
		if(tong[i]!=0){
			while(tong[i]--){
				ans+=char(i);
			}
		}
//		cout<<tong[i];
	}
	cout<<ans;
	
	
	return 0;
}
