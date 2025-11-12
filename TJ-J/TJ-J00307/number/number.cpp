#include<bits/stdc++.h>
using namespace std;
int arr[1000005]={};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	long long s=0;
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			s++;
			arr[s]=n[i]-48;
		}
	}
	sort(arr+1,arr+s+1,cmp);
	for(int i=1;i<=s;i++){
		cout<<arr[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
