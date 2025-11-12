#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[100005][3];
unsigned long long ans;
int t1[40005],t3[40005];
bool vis1[100005];
long long tans;
void sol(unsigned long long t,int d,int t1,int t2,int t3){
	int tn=n/2;
	if(t1>tn||t2>tn||t3>tn)return;
	if(d==n){
		if(ans<t)ans=t;
	}
	sol(t+a[d][0],d+1,t1+1,t2,t3);
	sol(t+a[d][1],d+1,t1,t2+1,t3);
	sol(t+a[d][2],d+1,t1,t2,t3+1);
}
void x(){
	sol(0,0,0,0,0);
	cout<<ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		tans=0;
		bool b=1;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]<a[i][2]||a[i][1]<a[i][2])b=0;
		}
		if(n<=10)x();
		else if(b){
			for(int i=0;i<=40000;i++)t1[i]=0;
			for(int i=0;i<n;i++){
				ans+=a[i][1];
				a[i][0]-=a[i][1];
				t1[a[i][0]+20000]++;
			}
			int tn=n/2,cnt=40000;
			while(tn>0){
				if(t1[cnt]>0){
					ans+=cnt;
					ans-=20000;
					t1[cnt]--;
					tn--;
				}
				else cnt--;
			}
			cout<<ans;
		}
		else{
			
		}
		cout<<endl;
	}
	return 0;
}