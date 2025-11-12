#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	int dx=0,t=0;
	string sz[100009];
	cin>>n;
	dx=n.size();
	for(int i=0;i<dx;i++){
		if((n[i]=='0')||(n[i]=='1')||(n[i]=='2')||(n[i]=='3')||(n[i]=='4')||(n[i]=='5')||(n[i]=='6')||(n[i]=='7')||(n[i]=='8')||(n[i]=='9')){
			sz[t]=n[i];
			++t;
		}
	}
	string mt="",ne[100009];
	int ws=0;
	for(int k=0;k<dx;k++){
		mt="";
		ws=0;
		for(int i=0;i<dx;i++){
			if(sz[i]>mt){
				mt=sz[i];
				ws=i;
			}
		}
		ne[k]=mt;
		sz[ws]='0';
}
	for(int i=0;i<t;i++){
		cout<<ne[i];
	}
	return 0; 
} 
