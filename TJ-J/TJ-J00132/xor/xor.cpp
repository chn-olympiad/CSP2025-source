# include<bits/stdc++.h>
using namespace std;
int n,k,a[500100],cnt;
bool f=false;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			f=true;
		}
	}
	if(f==false){
		if(k==0){
			cout<<n/2;
		}
		if(k==1){
			cout<<n;
		}
	}
	else{
		if(k==0){
			for(int i=1;i<n;i++){
				if(a[i]==1&&a[i+1]==1||a[i]==0){
					cnt++;
				}
				else if(a[i]==0){
					cnt++;
				}
			}
		}
		else if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					cnt++;
				}
			}
		}
		cout<<cnt;	
	}
	return 0;
}
