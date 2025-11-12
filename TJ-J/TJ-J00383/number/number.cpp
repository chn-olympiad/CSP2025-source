#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000005];
	int b[10]={0};
	cin>>a;
	int n=strlen(a);
	for(int i=0;i<n;i++){
		int j=a[i]-'0';
		if(j>=0&&j<=9)b[j]++;
	}for(int i=9;i>=0;i--){
		for(int j=0;j<b[i];j++){
			cout<<i;
		}
	}
	return 0;
}

