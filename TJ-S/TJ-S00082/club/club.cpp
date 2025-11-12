# include<bits/stdc++.h>
using namespace std;
long long t,n,a[100010][6],ma=INT_MIN;
long long cnt[4],sum,p,h;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		ma=INT_MIN;
		cnt[1]=0,cnt[2]=0,cnt[3]=0;
		sum=0;
		p=0;
		h=0;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			a[j][4]=max(a[j][1],max(a[j][2],a[j][3]));
			if(a[j][4]==a[j][1]){
				a[j][2]-=a[j][4];
				a[j][3]-=a[j][4];
				cnt[1]++;
				sum+=a[j][4];
				a[j][5]=1;
			}
			else if(a[j][4]==a[j][2]){
				a[j][1]-=a[j][4];
				a[j][3]-=a[j][4];
				cnt[2]++;
				sum+=a[j][4];
				a[j][5]=2;
			}
			else{
				a[j][2]-=a[j][4];
				a[j][1]-=a[j][4];
				cnt[3]++;
				sum+=a[j][4];
				a[j][5]=3;
			}
		}	
		while(cnt[1]>n/2){
				for(int j=1;j<=n;j++){
					if(a[j][5]==1){
						if(a[j][2]>ma){
							ma=a[j][2];
							p=j;
							h=2;
						}
						if(a[j][3]>ma){
							ma=a[j][3];
							p=j;
							h=3;
						}
					}
				}
				sum+=ma;
				cnt[1]--;
				cnt[h]++;
				a[p][5]=h;
				a[p][1]=INT_MIN;
			}
			ma=INT_MIN;
			while(cnt[2]>n/2){
				for(int j=1;j<=n;j++){
					if(a[j][5]==2){
						if(a[j][1]>ma){
							ma=a[j][1];
							p=j;
							h=1;
						}
						if(a[j][3]>ma){
							ma=a[j][3];
							p=j;
							h=3;
						}
					}
				}
				sum+=ma;
				cnt[2]--;
				cnt[h]++;
				a[p][5]=h;
				a[p][2]=INT_MIN;
			}
			ma=INT_MIN;
			while(cnt[3]>n/2){
				for(int j=1;j<=n;j++){
					if(a[j][5]==3){
						if(a[j][2]>ma){
							ma=a[j][2];
							p=j;
							h=2;
						}
						if(a[j][1]>ma){
							ma=a[j][1];
							p=j;
							h=1;
						}
					}
				}
				sum+=ma;
				cnt[3]--;
				cnt[1]++;
				a[p][5]=h;
				a[p][3]=INT_MIN;
			}
			cout<<sum<<endl;	
			
		}	
	return 0;
	}
	

