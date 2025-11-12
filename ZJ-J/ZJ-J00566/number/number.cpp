#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	if(x<y){
		swap(x,y);
	}
	return x>y; 
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	long long ans=0;
	int i=0,j=1,m=0;
	int b[100001]={};
	while(a[i]!='\0'){
		if(a[i]>='0'&&a[i]<='9'){
			b[j]=a[i]-48;
			j++;
			m++;
		}
		i++;
	}
	for(i=1;i<=m;i++){
		for(j=2;j<=m+1-i;j++){
			if(b[j-1]<b[j]){
				swap(b[j-1],b[j]);
			}
		}
	}
	for(i=1;i<=m;i++){
		cout<<b[i];
	}
	return 0;
}
