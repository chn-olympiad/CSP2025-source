#include<bits/stdc++.h>
using namespace std;
int check(int a[],int n){
	int f1=0,f2=0,f3=0;
	for(int i=0;i<n;i++){
		if(a[i]==0)
			f1++;
		else if(a[i]==1)
			f2++;
		else
			f3++;
	}
	if(f1<=n/2 && f2<=n/2 && f3<=n/2)
		return 1;
	else
		return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		int ans=0;
		cin>>n;
		int s[n][3];
		for(int j=0;j<n;j++){
			for(int z=0;z<3;z++){
				cin>>s[j][z];
			}
		}
		int a[n]={0};
		while(true){
			if(a[0]==3)
				break;
			if(check(a,n)){
				int p=0;
				for(int l=0;l<n;l++){
					p=p+s[l][a[l]];
				}
				if(ans<p)
					ans=p;
			}
			a[n-1]++;
			for(int w=n;w>0;w--){
				if(a[w]==3){
					a[w]=0;
					a[w-1]++;
				}
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
