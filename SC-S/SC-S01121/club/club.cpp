#include<iostream>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		int ans=0;
		int a[1000][4];
		for(int k=1;k<=n;k++){
			for(int j=1;j<=3;j++){
				cin>>a[k][j];
			}
		}
		if(n==2){
			int cnt1=0,cnt2=0,cnt3=0;
			int save1=0,save2=0;
			for(int j=1;j<=3;j++){
				if(a[1][j]>cnt1){
					cnt1=a[1][j];
					save1=j;
				}
			}for(int j=1;j<=3;j++){
				if(a[2][j]>cnt1){
					cnt2=a[2][j];
					save2=j;
				}
			}
			if(cnt1>cnt2){
				for(int j=1;j<=3&&j!=save1;j++){
					if(a[2][j]>cnt3){
						cnt3=a[2][j];
					}
				}
				ans=cnt1+cnt3;
			}else if(cnt2>=cnt1){
				for(int j=1;j<=3&&j!=save2;j++){
					if(a[1][j]>cnt3){
						cnt3=a[1][j];
					}
				}
				ans=cnt2+cnt3;
			}
			cout<<ans;
		}/*else if(n==4){
			int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
			int save1=0,save2=0,save3=0,save4=0;
			for(int j=1;j<=3;j++){
				if(a[1][j]>cnt1){
					cnt1=a[1][j];
					save1=j;
				}
			}for(int j=1;j<=3;j++){
				if(a[2][j]>cnt1){
					cnt2=a[2][j];
					save2=j;
				}
			}for(int j=1;j<=3;j++){
				if(a[3][j]>cnt1){
					cnt3=a[3][j];
					save3=j;
				}
			}for(int j=1;j<=3;j++){
				if(a[4][j]>cnt1){
					cnt4=a[4][j];
					save4=j;
				}
			}
			if(cnt1>cnt2&&cnt1>cnt3&&cnt1>cnt4){
				if(cnt2>cnt3&&cnt2>cnt4){
					if(cnt3>cnt4){
						for(int j=1;j<=3&&j!=save1;j++){
							if(a[2][j]>cnt3){
								cnt3=a[2][j];
							}
						}
					}else{
						
					}
				}else if(cnt3>cnt2&&cnt3>cnt4){
					
				}else if(cnt4>cnt2&&cnt4>cnt3){
					
				}
			}
		}
		
	}*/
	fclose(stdin);
	fclose(stdout);
	return 0;
} 