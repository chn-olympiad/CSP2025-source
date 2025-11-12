#include<bits/stdc++.h>
using namespace std;
string s1;
int a[100101];
int n; 
int sum=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>s1;
	cin>>n;
	for(int i=1;i<=n;i++){
		if(s1[i]==1){
			cout<<s1[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(s1[i]>s1[i-1]){
			sum=max(sum,s1[i]+s1[i-1]);
			cout<<sum;
	}else{
		sum=max(sum,s1[i-1]+s1[i+1]);
			cout<<sum;
	}
}
	return 0;
} 
