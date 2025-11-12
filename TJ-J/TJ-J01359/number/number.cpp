#include<bits/stdc++.h>
using namespace std;
string a;
long long int t[100001],sum;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for (long long int i=0;i<a.size();i++){
		if (a[i]<='9'&&a[i]>='0'){
			t[sum]=int(a[i])-'0';
			sum++;
		}
	}
	sort(t,t+sum);
	//cout<<sum<<endl;
	//for (int i=0;i<sum;i++){
	//	cout<<t[i]<<" ";
	//}
	//cout<<endl;
	for (long long int i=sum-1;i>=0;i--){
		cout<<t[i];
	}
	return 0;
} 
