#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
//I ac T1
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	int arr[1000001],cnt=0;
	string a;
	cin>>a;
	int id=0;
	for(int i=0;i<a.size();i++){
		if(a[i]<='9'&&a[i]>='0'){
			arr[id]=a[i]-'0';
			cnt+=arr[id]; 
			id++;
		}
	}
	sort(arr,arr+id,cmp);
	if(cnt==0){
		cout<<0;
		return 0;
	}
	for(int i=0;i<id;i++){
		cout<<arr[i];
	}
	return 0;
} 
//#Shang4Shan3Ruo6Shui4