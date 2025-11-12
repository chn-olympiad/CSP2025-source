#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string a;
	cin>>a;
	int n,cnt=0;
	n=a.size();
	int arr[n]={0};
	for(int i=0;i<n;++i){
		if(a[i]>='0'&&a[i]<='9'){
			arr[cnt]=a[i]-'0';
			++cnt;
		}
	}
	sort(arr,arr+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<arr[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
