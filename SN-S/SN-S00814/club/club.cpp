#include <bits/stdc++.h>

// .  .  .  . 
// 屎 山 大 作
// 菩 萨 保 佑
// .  .  .  . 

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t,n,t1,t2,t3,max,m_m,n_2,on2=-1,r1,r2;
	int ans[5] = {0};
	int h[100001][3];
	int info[100001][2]; // 0:mark 1:index
	
	std::cin >> t;
	for (int x=0;x<t;x++){
		std::cin >> n;
		for (int x2=0;x2<n;x2++){
			std::cin >> h[x2][0] >> h[x2][1] >> h[x2][2];
			if ((t1>t2) && (t1>t3)){
				info[x2][0] = t1;
				info[x2][1] = 0;
			}
			if ((t2>t3) && (t2>t1)){
				info[x2][0] = t2;
				info[x2][1] = 1;
			}
			if ((t3>t2) && (t3>t1)){
				info[x2][0] = t3;
				info[x2][1] = 2;
			}
		}
		
		t1=0;t2=0;t3=0;n_2=n/2;
		for(int d=0;d<n;d++){                                    //       ==============
			if (on2==-1){                                        //      =             =
				if (t1>n_2){                                     //     ================
					on2=0;                                       //     =  =   =   =
					r1=1;r2=2;                                   //    =    =  =  =
				}                                                //    =     = = =
				else if (t2>n_2){                                //    =  =============
					on2=1;	                                     //   =      = = =
					r1=0;r2=2;	                                 //   =    =   =  =
				}                                                //   =  =     =   =
				else if (t3>n_2){
					on2=2;	
					r1=0;r2=1;	
				}
				else{
					max=0;
					for(int tt=0;tt<n;tt++){
						if (info[tt][0] > max){
							max=info[tt][0];
							info[tt][0] = 0;
							m_m=tt;
						}
					}
					ans[x]+=h[m_m][info[m_m][1]];
					switch (info[m_m][1]) {
						case 0:
							t1++;
							break;
						case 1:
							t2++;
							break;
						case 2:
							t3++;
							break;
					}
				}
			}
			else {
				if (info[d][1]==on2){
					if (h[d][r1] > h[d][r2]){
						ans[x]+=h[d][r1];
					}
					else {
						ans[x]+=h[d][r2];
					}
				}
				else{
					ans[x]+=info[d][0];
				}
			}
		}
	}
	for (int x=0;x<t;x++){
		std::cout << ans[x] << "\n";	
	}
	
	
	return 0; 
}
