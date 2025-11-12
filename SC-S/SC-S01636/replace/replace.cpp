#include<iostream>
using namespace std;
int main(){
	int n,q;
	string a,b;
	char y='x';
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
	}
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		if((a.size()<=3&&b.size()<=3)||(a[1]==a[0]&&b[1]==b[0])||(a.size()!=b.size())){
			cout<<0;
		}else{
			int sum=0;
			for(int j=0;j<a.size();j++){
				if(a[j]==b[j]&&a[j]!=y){
					y=a[j];
					sum++;
				}
			}
			cout<<sum;
		}
	}
	return 0;
} 