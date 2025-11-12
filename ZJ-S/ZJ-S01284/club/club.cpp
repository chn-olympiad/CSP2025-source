#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn][3],n,t,now[3],ans=0;

priority_queue<int,vector<int>,greater<int>>zy[3];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		now[0]=0;
		now[1]=0;
		now[2]=0;
		ans=0;
		while(zy[0].size()){
			zy[0].pop();
		}
		while(zy[1].size()){
			zy[1].pop();
		}
		while(zy[2].size()){
			zy[2].pop();
		}
		for(int i=1;i<=n;i++){
			int q,w,e;
			for(int j=0;j<3;j++){
				cin >> a[i][j];
				int xian=a[i][j];
			}
			if(a[i][0]>=a[i][1] && a[i][0]>=a[i][2]){
				q=0;
				if(a[i][1]>=a[i][2]){
					w=1;
					e=2;
				}
				else{
					w=2;e=1;
				}
			}
			else if(a[i][1]>=a[i][0] && a[i][1]>=a[i][2]){
				q=1;
				if(a[i][2]>=a[i][0]){
					w=2;
					e=0;
				}
				else{
					w=0;
					e=2;
				}
			}
			else{
				q=2;
				if(a[i][1]>=a[i][0]){
					w=1;
					e=0;
				}
				else{
					w=0;
					e=1;
				}
			}
			int b1=a[i][q],b2=a[i][w],b3=a[i][e];
			int cha=b1-b2;
			//cout << q << " " << now[q] << endl;
			if(now[q]==n/2){
				int zuixiao=zy[q].top();
				//cout << q << " " << zuixiao << endl;
				if(zuixiao>=cha){
					ans+=b2;
					zy[w].push(b2-b3);
				}
				else{
					ans+=b1;
					//cout << ans << endl;
					ans-=zuixiao;
					zy[q].pop();
					zy[q].push(cha);
				}
			}
			else{
				ans+=b1;
				now[q]++;
				zy[q].push(cha);
			}
		}
		cout << ans << endl;
		
	}
	return 0;
}