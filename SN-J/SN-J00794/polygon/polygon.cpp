//SN-J00794 王美萱 西安市曲江第一学校 
#include<bits/stdc++.h>
using namespace std;
int n,ans=0,he=0;
int a[5005];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		for(int i=1;i<=3;i++){
			he+=a[i];
			if(he>max(a[1],max(a[2],a[3]))){
				cout<<"1";
				return 0;
			}
		}
	}
	sort(a+1,a+1+n,cmp);
	for(int j=1;j<=n;j++){
		for(int i=3;i<=n;i++){
			he+=a[j];
			if(he>a[j]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
