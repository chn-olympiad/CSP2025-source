#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("club1.in","r",stdin);
freopen("club.out","w",stdout);
	int t,n,x,ans[6]={0};
	cin>>t;
	int a[100003][4];
	for(int q=1;q<=t;q++){
	cin>>n;
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
				cin>>a[i][j];
		}
	for(int j=0;j<n;j++){
		t=max(a[j][0],a[j][1]);
		ans[q]+=max(t,a[j][3]);
		}
	}
	for(int i=1;i<=t;i++)cout<<ans[i]+1<<endl;
	return 0;
}

