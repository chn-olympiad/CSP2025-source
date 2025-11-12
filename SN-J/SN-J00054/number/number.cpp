#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","r",stdout);
	cin>>s;
	for(int v:s){
		if((v-'0'>=0)&&(v-'0'<=9)){
			a[(v-'0')]++;
		}
	}
	if(a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0&&a[6]==0&&a[7]==0&&a[8]==0){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
	    while(a[i]--){
	    	cout<<i;
		}	
    }
	return 0;
}
