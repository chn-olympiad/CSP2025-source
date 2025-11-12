#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
while(t--){
int sum=0;
int n;
cin>>n;
for(int i=0;i<n;i++){
	int a[3];
for(int j=0;j<3;j++){
	cin>>a[j];
}sort(a,a+3);
sum+=a[2];
}cout<<sum<<endl;
}
	return 0; 
} 
