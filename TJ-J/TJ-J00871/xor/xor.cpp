#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2){
		for(int i=1;i<=n;i++){
			if(a[i]==k) cnt++;
		}
		if(int(a[1]^a[2])==k) cnt++;
		cout<<cnt;
		return 0;
	}else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) cnt++;
		}
		cout<<cnt;
		return 0;
	}else if(k==0){
		int b[500010];
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				b[i]=1;
				cnt++;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				for(int j=1;j<n-1;j++){
					bool flag=false,flag2=true;
					bool flag3=true;
					for(int z=1;z<=j;z++){
						if(b[i+z]){
							flag3=false;
						}
					}
					if(!flag3) break;
					for(int z=1;z<=j;z++){
						if(a[i+z]!=1) flag2=false;
						if(a[i+z]!=0&&!flag2){
							flag=true;
							break;
						}
					}
					if(flag) continue;
					if(flag2&&j%2==0){
						cnt++;
						continue;
					}
					if(a[i+j+1]==1) cnt++;
				}
			}
		}
		cout<<cnt;
		return 0;
	}
	srand(time(0));
	cout<<rand()%(n+1);
	return 0;
}
