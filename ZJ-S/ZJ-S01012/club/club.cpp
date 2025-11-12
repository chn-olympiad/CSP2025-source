#include<bits/stdc++.h>
using namespace std;
int n,t,a[1010101][5],used[5],maxx,ma[1001010],maxid[1010101],to[10];
void dfs(int step,int sum){
	if(step==n+1){
		maxx=max(maxx,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(used[i]<n/2){
			used[i]++;
			//cout<<sum<<" ";
			dfs(step+1,sum+a[step][i]);
			used[i]--;
		}
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		maxx=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i][1]);
			scanf("%d",&a[i][2]);
			scanf("%d",&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				ma[i]=a[i][1];
				maxid[i]=1;
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
			{
				ma[i]=a[i][2];
				maxid[i]=2;
			}
			else{
				ma[i]=a[i][3];
				maxid[i]=3;				
			}
		}
		for(int i=1;i<=n;i++){
			to[maxid[i]]++;
		}
		bool flagx=1;
		for(int i=1;i<=3;i++){
			if(to[i]>n/2){
				flagx=0;
				break;
			}
		}
		if(flagx){
			long long posum=0;
			for(int i=1;i<=n;i++){
				posum+=ma[i];
			}
			cout<<posum<<endl;
		}
		else{
			used[1]=0;
			used[2]=0;
			used[3]=0;
			dfs(1,0);
			cout<<maxx<<endl;		
		}

	}
	
	return 0;
}
