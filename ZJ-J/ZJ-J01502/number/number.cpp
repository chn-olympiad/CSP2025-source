#include<bits/stdc++.h>
using namespace std;
string str;
int arr[10]={},n;
bool isnum(char ass){//check number or not
	if(ass>='0'&&ass<='9')return 1;//is number
	else return 0;//not number
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	int len=str.size();//str's size
	for(int i=0;i<len;i++){
		if(isnum(str[i])){
			arr[(int(str[i])-int('0'))]++;
			n++;//numbersize
		}
	}for(int i=1;i<=n;i++){//print
		if(arr[9]>0){
			cout<<'9';
			arr[9]--;
		}else if(arr[8]>0){
			cout<<'8';
			arr[8]--;
		}else if(arr[7]>0){
			cout<<'7';
			arr[7]--;
		}else if(arr[6]>0){
			cout<<'6';
			arr[6]--;
		}else if(arr[5]>0){
			cout<<'5';
			arr[5]--;
		}else if(arr[4]>0){
			cout<<'4';
			arr[4]--;
		}else if(arr[3]>0){
			cout<<'3';
			arr[3]--;
		}else if(arr[2]>0){
			cout<<'2';
			arr[2]--;
		}else if(arr[1]>0){
			cout<<'1';
			arr[1]--;
		}else if(arr[0]>0){
			cout<<'0';
			arr[0]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}