#include<bits/stdc++.h>
using namespace std;
int arr[1234007],jl;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			arr[i]=a[i]-'0';
			jl++;
		}
	}
	sort(arr,arr+a.size()+1,cmp);
	for(int i=0;i<jl;i++){
		cout<<arr[i];
	}
	return 0;
} 
