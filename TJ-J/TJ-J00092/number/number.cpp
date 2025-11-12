#include<bits/stdc++.h>
using namespace std;
int cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000001];
	int b[10];
	cin>>a;
	int len=strlen(a);
	for(int i=0;i<=len;i++){
		//if(a[i]>='0'&&a[i]<='9'){
		//	b[cnt]=a[i]-'0';
		//	cnt++;
		//}
		if(a[i]>='0'&&a[i]<='9'){
			if(a[i]=='0'){
				b[0]++;
			}
			if(a[i]=='1'){
				b[1]++;
			}
			if(a[i]=='2'){
				b[2]++;
			}
			if(a[i]=='3'){
				b[3]++;
			}
			if(a[i]=='4'){
				b[4]++;
			}
			if(a[i]=='5'){
				b[5]++;
			}
			if(a[i]=='6'){
				b[6]++;
			}
			if(a[i]=='7'){
				b[7]++;
			}
			if(a[i]=='8'){
				b[8]++;
			}
			if(a[i]=='9'){
				b[9]++;
			}
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=b[i];j++){
			if(i==9){
				cout<<"9";
			}
			if(i==8){
				cout<<"8";
			}
			if(i==7){
				cout<<"7";
			}
			if(i==6){
				cout<<"6";
			}
			if(i==5){
				cout<<"5";
			}
			if(i==4){
				cout<<"4";
			}
			if(i==3){
				cout<<"3";
			}
			if(i==2){
				cout<<"2";
			}
			if(i==1){
				cout<<"1";
			}
			if(i==0){
				cout<<"0";
			}
		}
	}
	return 0;
}
