#include<bits/stdc++.h>
using namespace std;
int n,a[100002][3],t,ans,f1,f2,f3,f;
void search(int k,int sum){
	if(k==n+1){
		ans=max(ans,sum);return;
	}
	if(f1<n/2){
		f1++;search(k+1,sum+a[k][0]);f1--;
	}
	if(f2<n/2){
		f2++;search(k+1,sum+a[k][1]);f2--;
	}
	if(f3<n/2){
		f3++;search(k+1,sum+a[k][2]);f3--;
	}
}
int main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;ans=0;f=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][1]==0&&a[i][2]==0){
				f+=a[i][0];i--;n--;
			}
		}
		search(1,0);
		cout<<ans+f<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}