#include<bits/stdc++.h>
using namespace std;
int a[100100][3],mk[100100],cha1[100100],cha2[100100];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		memset(a,0,sizeof(a));
		memset(mk,0,sizeof(mk));
		memset(cha1,0,sizeof(cha1));
		memset(cha2,0,sizeof(cha2));
		bool flag1=true,flag2=true;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0){
				flag1=false;
			}if(a[i][3]!=0){
				flag2=false;
			}
		}if(flag1==true){
			int ans1=0;
			for(int i=1;i<=n;i++){
				mk[i]=a[i][1];
			}
			sort(mk+1,mk+1+n);
			for(int i=n;i>=n/2+1;i--){
				ans1+=mk[i];
			}
			cout<<ans1<<endl;
		}else{
		if(flag2==true){
			long long cnt1=0,cnt2=0,ans=0;
			for(int i=1;i<=n;i++){
				if(a[i][1]>=a[i][2]){
					cnt1++;	
					cha1[cnt1]=abs(a[i][1]-a[i][2]);
					ans+=a[i][1];
				}if(a[i][1]<a[i][2]){
					cnt2++;	
					cha2[cnt2]=abs(a[i][2]-a[i][1]);
					ans+=a[i][2];
				}
			}
			sort(cha1+1,cha1+1+cnt1);
			sort(cha2+1,cha2+1+cnt2);
			if(cnt1<cnt2){
				for(int i=1;i<=(cnt2-cnt1)/2;i++){
					ans-=cha2[i];
				}
			}if(cnt1>cnt2){
				for(int i=1;i<=(cnt1-cnt2)/2;i++){
					ans-=cha1[i];
				}
			}cout<<ans<<endl;	
		}if(flag2!=true){
			int maxx1,maxx2;
			if(n==2){
				maxx1=max(a[1][1],max(a[1][2],a[1][3]));
				maxx2=max(a[2][1],max(a[2][2],a[2][3]));
				if(a[1][1]==maxx1){
					if(a[2][1]==maxx2){
						cout<<a[1][1]+a[2][1]-min(min(abs(a[2][1]-a[2][2]),abs(a[2][1]-a[2][3])),min(abs(a[1][1]-a[1][2]),abs(a[1][1]-a[1][3])));
					}if(a[2][1]==maxx2){
						cout<<maxx1+maxx2;
					}if(a[2][1]==maxx2){
						cout<<maxx1+maxx2;					
					}
				}if(a[1][2]==maxx1){
					if(a[2][1]==maxx2){
						cout<<maxx1+maxx2;						
					}if(a[2][2]==maxx2){
						cout<<a[1][2]+a[2][2]-min(min(abs(a[2][2]-a[2][1]),abs(a[2][2]-a[2][3])),min(abs(a[1][2]-a[1][1]),abs(a[1][2]-a[1][3])));						
					}if(a[2][3]==maxx2){
						cout<<maxx1+maxx2;						
					}
				}if(a[1][3]==maxx1){
					if(a[2][1]==maxx2){
						cout<<maxx1+maxx2;						
					}if(a[2][2]==maxx2){
						cout<<maxx1+maxx2;						
					}if(a[2][3]==maxx2){
						cout<<a[1][3]+a[2][3]-min(min(abs(a[2][3]-a[2][2]),abs(a[2][3]-a[2][1])),min(abs(a[1][3]-a[1][2]),abs(a[1][3]-a[1][1])));						
					}
				}
			}
		}
		}
	} 
	return 0;
}
