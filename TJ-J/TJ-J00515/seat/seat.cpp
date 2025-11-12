#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],tmp1=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int tmp=a[1];
	int k;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==tmp){
			k=i-1;
			break;
		}
	}
	int ans1=1,ans2=1;
	while(k--){
		if(tmp1==1){
			if(ans1<n){
				ans1++;
			}else{
				if(ans1==n){
					ans2++;
					tmp1*=-1;
				}
			}
		}else{
			if(ans1>1){
				ans1--;
			}else{
				if(ans1==1){
					ans2++;
					tmp1*=-1;
				}
			}
		}
	}
	cout<<ans2<<" "<<ans1;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
