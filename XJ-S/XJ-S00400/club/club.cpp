#include <bits/stdc++.h>
using namespace std;
int  t,n,score[5],satis[100000][3],mou[3];
queue q1<10000>,q2<10000>,q3<10000>;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		//cout<<i<<endl;
		for(int j=1;j<=n;j++){
			cin>>satis[j][1]>>satis[j][2]>>satis[j][3];
			}
		}
	for(int i=1;i<=t;i++){
		score[i]=0;
		for(int j=1;j<=n;j++){
			int a=max(satis[j][1],max(satis[j][2],satis[j][3]));			
			if((a==satis[j][1]) && mou[1]<(n/2)){
			q1.push(a);
			mou[1]++;
			}
			if(a==satis[j][2] && mou[2]<(n/2)){
			q2.push(a);
			mou[2]++;
			}
			if((a==satis[j][3]) && mou[3]<(n/2)){
			q3.push(a);
			mou[3]++;			
			}
			}
		cout<<score[i]<<endl;
		}
		
	
	return 0;
	}
	
	
	
	
	
	

 
