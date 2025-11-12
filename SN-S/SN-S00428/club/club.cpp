#include<bits/stdc++.h>
using namespace std;
int club[20010][5],club1[20020];
int a[4];
int ans=0;
int cnt=0,maxx=0;
void find(int n,int now,int k){
	
	if(now==n+1){
		if(cnt>=maxx){
			maxx=cnt;
		}
		return;
	}
	for(int i=1;i<=3;i++){
		if(club[now][i]>club[now][4]){
			
			if(a[i]<n/2){
				a[i]++;
				cnt+=club[now][i];
				find(n,now+1,i);
				cnt-=club[now][i];
				a[i]--;
			}
		}	
	}
}
void find2(int n,int now,int k){
	
	if(now==n+1){
		if(cnt>=maxx){
			maxx=cnt;
		}
		return;
	}
	for(int i=1;i<=2;i++){
		if(club[now][i]>club[now][4]){
			
			if(a[i]<n/2){
				a[i]++;
				cnt+=club[now][i];
				find(n,now+1,i);
				cnt-=club[now][i];
				a[i]--;
			}
		}	
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		int ss1=0,ss3=0;
		for(int j=1;j<=n;j++){
			cin>>club[j][1];
			cin>>club[j][2]; 
			cin>>club[j][3];
			club[j][4]=min(club[j][1],min(club[j][2],club[j][3]));
			if(club[j][1]==0)  	ss1++;
			if(club[j][3]==0)  	ss3++;
		}
		if(ss3==n){
			find2(n,1,1);
		}
		if(ss1==n && ss3==n){
			for(int k=1;k<=n;k++){
				club1[k]=club[k][2];
			}
			sort(club1+1,club1+1+n);
			for(int k=1;k<=n/2+1;k++){
				cnt+=club1[k];
			}
			cout<<cnt<<endl;
		}else{
			find(n,1,1);
			cout<<maxx<<endl;
			maxx=0;
			cnt=0;
		}
		maxx=0;
		cnt=0;
		ss1=ss3=0;
		ans=0;
	}
	return 0;
}
