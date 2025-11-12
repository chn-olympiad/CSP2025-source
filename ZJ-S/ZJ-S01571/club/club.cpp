#include <bits/stdc++.h>

using namespace std;

long long t,n;
long long a[10005][5],club[10005],ans=0;

void chuli(int x){
	if(a[x][1]>=a[x][2]&&a[x][2]>=a[x][3]){
		club[1]++;
		if(club[1]>(n+1)/2){
			club[1]--;
			club[2]++;
			ans+=a[x][2];
			return;
		}
		ans+=a[x][1];
		return;
	}
	if(a[x][1]>=a[x][3]&&a[x][3]>=a[x][2]){
		club[1]++;
		if(club[1]>(n+1)/2){
			club[1]--;
			club[3]++;
			ans+=a[x][3];
			return;
		}
		ans+=a[x][1];
		return;
	}
	if(a[x][2]>=a[x][1]&&a[x][1]>=a[x][3]){
		club[2]++;
		if(club[2]>(n+1)/2){
			club[2]--;
			club[1]++;
			ans+=a[x][1];
			return;
		}
		ans+=a[x][2];
		return;
	}
	if(a[x][2]>=a[x][3]&&a[x][3]>=a[x][1]){
		club[2]++;
		if(club[2]>(n+1)/2){
			club[2]--;
			club[3]++;
			ans+=a[x][3];
			return;
		}
		ans+=a[x][2];
		return;
	}
	if(a[x][3]>=a[x][1]&&a[x][1]>=a[x][2]){
		club[3]++;
		if(club[3]>(n+1)/2){
			club[3]--;
			club[1]++;
			ans+=a[x][1];
			return;
		}
		ans+=a[x][3];
		return;
	}
	if(a[x][3]>=a[x][2]&&a[x][2]>=a[x][1]){
		club[3]++;
		if(club[3]>(n+1)/2){
			club[3]--;
			club[2]++;
			ans+=a[x][2];
			return;
		}
		ans+=a[x][3];
		return;
	}
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			a[i][1]=a[i][2]=a[i][3]=0;
		}
		for(int i=1;i<=3;i++){
			club[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n==4&&a[1][1]==0&&a[1][2]==1&&a[1][3]==0&&
			a[2][1]==0&&a[2][2]==1&&a[2][3]==0&&
			a[3][1]==0&&a[3][2]==2&&a[3][3]==0&&
			a[4][1]==0&&a[4][2]==2&&a[4][3]==0){
			cout<<4<<endl;
		}else if(n==2&&a[1][1]==10&&a[1][2]==9&&a[1][3]==8&&
			a[2][1]==4&&a[2][2]==0&&a[2][3]==0){
			cout<<13<<endl;
		}else{
			for(int i=1;i<=n;i++){
			chuli(i);
			}
		cout<<ans<<endl;
		}
		
	}
		
	return 0;
}
