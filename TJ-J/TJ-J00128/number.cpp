#include<bits/stdc++.h>
using namespace std;
string arr[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=1;i<=1000005;i++){
		if(arr[i]%arr[i]==0){
			if(arr[i]<=arr[i+1]){
				swap(arr[i+1],arr[i])
			}
		}else{
			erase(s,arr[i]);
		}
	}
	cout<<arr[i];
	return 0;
}
