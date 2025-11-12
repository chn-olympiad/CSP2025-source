#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[5];
	int b[5];
	int k=1;
	scanf("%s%s%s%s%s",&a[1],&a[2],&a[3],&a[4],&a[5]);
	for(int i=1;i<=5;i++){
		if(a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'||a[i]=='10'){
			b[k]=a[i]-'0';
			k++;
		}
	}
	for(int i=1;i<=5;i++){
		for(int j=1;j<=4;j++){
			if(a[j+1]<=a[j]){
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(int i=1;i<=5;i++){
		cout<<b[i];
	}
	return 0;
}
