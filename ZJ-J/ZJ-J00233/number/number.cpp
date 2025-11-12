#include<bits/stdc++.h>
using namespace std;
int arr[1000001],ans=0;
string a;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int t=a.size()-1;
	for(int i=0;i<=t;i++){
		if(a[i]>='0'&&a[i]<='9'){
			ans++;
			arr[ans]=a[i]-'0';
		}
	}
	sort(arr+1,arr+1+ans,cmp);
	for(int i=1;i<=ans;i++) cout<<arr[i];
	return 0;
}

