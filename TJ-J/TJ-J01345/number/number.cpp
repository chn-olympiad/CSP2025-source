#include<bits/stdc++.h>
using namespace std;
string n;
int arr[10000005],sum = 0,lc = 0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	int l = n.size();
	for(int i = 0;i<=l;i++){
		if(n[i]=='0'||n[i]=='2'||n[i]=='3'||n[i]=='1'||n[i]=='4'||n[i]=='5'||n[i]=='6'||n[i]=='7'||n[i]=='8'||n[i]=='9'){
			arr[sum] = n[i]-'0';
			sum++;
		}
	}
	sort(arr,arr+sum);
	for(int i = sum-1;i>=0;i--){
		cout<<arr[i];
	}
	return 0;
}

