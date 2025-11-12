#include <bits/stdc++.h> 
using namespace std;
const int N=1e6+10;
int flag,a[N];
string arr;
int main () {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>arr;
	int m=arr.size();
	for(int i=0;i<m;i++){
		if(arr[i]>='0'&&arr[i]<='9'){
			a[flag]=arr[i]-'0';
			flag++;	
		}
	}
	sort(a,a+flag);
	for(int i=flag-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 
