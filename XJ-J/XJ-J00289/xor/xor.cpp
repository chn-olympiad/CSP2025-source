#include<bits/stdc++.h>
using namespace std;
int p(int v,int u){
	return v xor u; 
}
const int N=5*100010;
long long int a[N];
long long int b[N];
long long int n,k,cnt=0,x;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(b[i]==1){
			continue;
		}
		x=a[i];
		int flag=1;
		for(int j=i;j<=n;j++){
			if(k!=0&&a[i]==0){
				continue;
			}
			if(x==k){
				flag=0;
				cnt++;
				b[j]=2;
				break;
			}
			if(b[j]!=1){
				x=p(x,a[j+1]);
				b[j]=2;
				b[j+1]=2;
			}
			if(x==k){
				flag=0;
				cnt++;
				break;
			}
		}
		if(flag==1){
			for(int j=i;j<=n;j++){
				if(b[j]==2){
					b[j]=0;
				} 
			}
			continue;
		}
		for(int j=i;j<=n;j++){
			if(b[j]==2){
				b[j]=1;
			} 
		}
	}
	cout<<cnt<<endl;
	return 0;
}
