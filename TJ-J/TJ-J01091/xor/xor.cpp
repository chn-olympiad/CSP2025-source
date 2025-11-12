#include<bits/stdc++.h>//hujunqin
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[500001]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	int yhz=0;
	for(int i=1;i<=n;i++) if(a[i]==k) cnt++; 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n&&a[i]!=k;j++){
			yhz=yhz^a[j];
			if(yhz==k){
				cnt++;
				yhz=0;
			}else if(a[i]==k) yhz=0;
		}
		//cout<<yhz<<endl;
	}
	cout<<cnt;
	return 0;
}
