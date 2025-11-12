#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int b=0,sum[100007];
	cin>>a;
	for(int i=0;i<=a.length();i++){
		if(a[i]>='0'&&a[i]<='9'){
			sum[b]=int(a[i])-48;
			b++;
		}
	}
	sort(sum,sum+b,cmp);
	for(int i=0;i<b;i++){
		cout<<sum[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
