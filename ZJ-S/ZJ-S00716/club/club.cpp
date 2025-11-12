#include<bits/stdc++.h>
using namespace std;

int a[100005][5];
int b[100005][2];
int c[100005];
int cnt[5];
int T;
int n;

int find(int x,int y){
	for(int i=1;i<=3;i++){
		if(x==a[y][i])return i;
	}
}

int cmp(int x,int y){
	return (x<y);
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;

	while(T--){

		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(cnt,0,sizeof(cnt));
		

		int ans=0;
		
		cin>>n;

		for(int i=1;i<=n;i++){

			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i][0]=max(a[i][1],max(a[i][2],a[i][3]));//maxx
			
			cnt[find(b[i][0],i)]++;
			
//			if(b[i][0]==a[i][1])cnt[1]++;
//			else if(b[i][0]==a[i][2])cnt[2]++;
//			else if(b[i][0]==a[i][3])cnt[3]++;
//			
			int sum=a[i][1]+a[i][2]+a[i][3];
			int minn=min(a[i][1],min(a[i][2],a[i][3]));
			int medi=sum-b[i][0]-minn;
			b[i][1]=b[i][0]-medi;// make the minnest cha
			
			ans+=b[i][0];
		}
		
//		cout<<ans<<endl;
//		cout<<cnt[1]<<' '<<cnt[2]<<' '<<cnt[3]<<endl;
//		for(int i=1;i<=n;i++){
//			cout<<b[i][1]<<' ';
//		}
//		cout<<endl;
//		
		bool flag=0;
		int cnt1=0,k1;
		for(int k=1;k<=3;k++){
			if(cnt[k]>(n/2)){
				flag=1;
				k1=k;
				for(int i=1;i<=n;i++){
					if(find(b[i][0],i)==k){//maxx is in k line
						c[++cnt1]=b[i][1];			
					}
				}
			}
		}
		if(!flag)cout<<ans<<endl;
		else{
			sort(c+1,c+1+cnt1,cmp);
			for(int i=1;i<=(cnt[k1]-n/2);i++){
				ans-=c[i];
			}
			cout<<ans<<endl;
		}
	}
}
