#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,j,L,sum;
	cin>>s;
 	for(i=1;i<1000005;i++){
 		if(s[i]){
			sum++;
		}
	}
	j=9;
	while(sum!=0){
		if(a[j]!=0){
			cout<<a[j];
		}
		else{
			j--;
		}
	}
	return 0;
}