#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],jo[4]={0,0,0,0},sum,ans;

void baoli(int x){
	for(int i=1;i<4;i++)if(jo[i]>n/2)return;
	if(x>n){
		if(sum>ans)ans=sum;
		return;
	}
	for(int i=1;i<4;i++){
		jo[i]++;
		sum+=a[x][i];
		baoli(x+1);
		sum-=a[x][i];
		jo[i]--;
	}
}


int main(){
	freopen("club3.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int sb=1;sb<=t;sb++){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<4;j++)cin>>a[i][j];
		}
		sum=ans=0;
		baoli(1);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
} 
