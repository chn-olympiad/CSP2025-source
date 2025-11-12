#include<bits/stdc++.h>
using namespace std;
int b[1000000]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int i,j,s,sum=0,t;
	cin>>a;
	s=a.size();
	for(i=0;i<s;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[++sum]=a[i]-'0';
		}
	}
	for(i=1;i<=sum;i++){
		for(j=i;j<=sum;j++){
			if(b[j]<b[j+1]){
				t=b[j];
				b[j]=b[j+1];
				b[j+1]=t;
			}
		}
	}
	for(i=1;i<=sum;i++){
		cout<<b[i];
	}
	return 0;
}
