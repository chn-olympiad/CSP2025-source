#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=strlen(s);
	for(int i=0;i<l;i++){
		if(s[i]=='0'){
			a[0]++;
		}
		else if(s[i]=='1'){
			a[1]++;
		}
		else if(s[i]=='2'){
			a[2]++;
		}
		else if(s[i]=='3'){
			a[3]++;
		}
		else if(s[i]=='4'){
			a[4]++;
		}
		else if(s[i]=='5'){
			a[5]++;
		}
		else if(s[i]=='6'){
			a[6]++;
		}
		else if(s[i]=='7'){
			a[7]++;
		}
		else if(s[i]=='8'){
			a[8]++;
		}
		else if(s[i]=='9'){
			a[9]++;
		}
	}
//	for(int i=9;i>=0;i--){
//		cout<<a[i]<<" ";
//	}	
	if(a[9]==0&&a[8]==0&&a[7]==0&&a[6]==0&&a[5]==0&&a[4]==0&&a[3]==0&&a[2]==0&&a[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
    return 0;
}
