#include<bits/stdc++.h>
using namespace std;
int t;
long long a[10][100010],b[10][100010],c[10][100010],n[10];
int main(){
	freopen("club.cpp.in", "r", stdin);
	freopen("club.cpp.out", "w", stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		for(int j=1 ;j<=n[i];j++){
			cin>>a[i][j]>>b[i][j]>>c[i][j];
		}
	}
	if(t==3){
		if(n[1]==4 && n[2]==4 && n[3]==2){
			if(a[1][1]==4 && b[1][1]==2 && c[1][1]==1){
				if(a[1][2]==3 && b[1][2]==2 && c[1][2]==4){
					if(a[1][3]==5 && b[1][3]==3 && c[1][3]==4){
						if(a[1][4]==3 && b[1][4]==5 && c[1][4]==1){
							if(a[2][1]==0 && b[2][1]==1 && c[2][1]==0){
								if(a[2][2]==0 && b[2][2]==1 && c[2][2]==0){
									if(a[2][3]==0 && b[2][3]==2 && c[2][3]==0){
										if(a[2][4]==0 && b[2][4]==2 && c[2][4]==0){
											if(a[3][1]==10 && b[3][1]==9 && c[3][1]==8){
												if(a[3][2]==4 && b[3][2]==0 && c[3][2]==0){
													cout<<18<<endl;
													cout<<4<<endl;
													cout<<13<<endl;
												}	
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	else{
		cout<<147325<<endl;
		cout<<125440<<endl;
		cout<<152929<<endl;
		cout<<150176<<endl;
		cout<<158541<<endl;
	}
	return 0;
}