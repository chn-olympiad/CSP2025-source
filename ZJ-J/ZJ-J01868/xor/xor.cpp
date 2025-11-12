#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]) sum++;
		}
		cout<<sum;
	}
	else if(k==0){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(!a[i]) sum++;
			else if(a[i]==a[i+1]){
				sum++;
				i++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
