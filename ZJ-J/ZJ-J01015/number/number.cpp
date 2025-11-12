#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	long int a[100001];
	long int k=1;
	for(long int i=0;i<n.length();i++){
		if(n[i]>='0'&&n[i]<='9'){
			a[k]=n[i]-'0';
			k++;
		}
	}
	k-=1;
	sort(a+1,a+k+1,cmp);
	for(long int i=1;i<=k;i++){
		cout<<a[i];
	}
	return 0;
}
