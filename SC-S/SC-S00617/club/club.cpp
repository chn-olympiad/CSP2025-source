#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans=0,flag;
int num[N][4];
int pref[N][4],cnt[4];
int mmin[4][N/2],ty[4][N/2],tty[4];
void up(int x){
	for(int i=1;i<=tty[x]>>1;i++){
		if(mmin[x][i]>mmin[x][i*2]) swap(mmin[x][i],mmin[x][i*2]),swap(ty[x][i],ty[x][i*2]);
		if(mmin[x][i]>mmin[x][i*2+1]) swap(mmin[x][i],mmin[x][i*2+1]),swap(ty[x][1],ty[x][i*2+1]);		
	}

}
void down(int x){
	for(int i=tty[x];i>=1;i>>=1){
		if(mmin[x][i]<mmin[x][i>>1]) swap(mmin[x][i],mmin[x][i>>1]),swap(ty[x][i],ty[x][i>>1]);
		
	}
}
void add(int x,int y){
	mmin[x][tty[x]]=y;
	down(x);
}
void de(int x){
	swap(mmin[x][1],mmin[x][tty[x]]);
	swap(ty[x][1],ty[x][tty[x]]);
	mmin[x][tty[x]]=0;
	ty[x][tty[x]]=0;
	up(x);
}
void chan(int i){

	if(num[i][2]>num[i][1]){

		flag=2;
	} 
	else flag=1;
	if(flag==1){
		if(num[i][3]>num[i][1]){
			pref[i][1]=3,pref[i][2]=1,pref[i][3]=2;
		}
		else if(num[i][3]>num[i][2]) pref[i][1]=1,pref[i][2]=3,pref[i][3]=2;
		else pref[i][1]=1,pref[i][2]=2,pref[i][3]=3;
	}
	else{
		if(num[i][3]>num[i][2]){
			pref[i][1]=3,pref[i][2]=2,pref[i][3]=1;
		}
		else if(num[i][3]>num[i][1]) pref[i][1]=2,pref[i][2]=3,pref[i][3]=1;
		else pref[i][1]=2,pref[i][2]=1,pref[i][3]=3;				
	}
}
void huan(int x,int idx){
	
	cnt[pref[x][idx]]--;
	ans-=num[x][pref[x][idx]];
	idx++;
	cnt[pref[ty[pref[x][idx-1]][1]][idx]]++;
	ans+=num[ty[pref[x][idx-1]][1]][pref[ty[pref[x][idx-1]][1]][idx]];
	
	de(pref[x][idx-1]);
	if(cnt[pref[ty[pref[x][idx-1]][1]][idx]]>n/2){
		huan(ty[pref[x][idx-1]][1],idx);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>num[i][1]>>num[i][2]>>num[i][3];
			chan(i);
		}
		for(int i=1;i<=n;i++){
			cnt[pref[i][1]]++;
			ans+=num[i][pref[i][1]];
			ty[pref[i][1]][++tty[pref[i][1]]]=i;
			add(pref[i][1],num[i][pref[i][1]]);
			
			if(cnt[pref[i][1]]>n/2){
				
				huan(pref[i][1],1);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}