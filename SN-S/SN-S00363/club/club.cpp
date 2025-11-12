#include<bits/stdc++.h>
using namespace std;
int T,n;
int ans,report[3][100005];
int table1[50005],table2[50005],table3[50005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		ans=0;
		memset(table3,0,sizeof(table3));
		memset(table1,0,sizeof(table1));
		memset(table2,0,sizeof(table2));
		bool FlagA = true; 
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> report[1][i] >> report[2][i]>> report[3][i];
			if(report[2][i] != 0 || report[3][i] != 0){
				FlagA = false;
			}
		}
		if(FlagA){
			sort(report[1]+1,report[1]+n+1);
			for(int i=n;i>n/2;i--){
				ans += report[1][i];
			}
			cout << ans;
			return 0;
		}

		for(int i=1;i<=n;i++){
			for(int j=n/2;j>0;j--){
				//放在1组
				int first = table1[j-1]+report[1][i]+table2[j]+table3[j];
				//放在2组
				int second = table1[j]+table2[j-1]+report[2][i]+table3[j];
				//放在3组
				int third = table1[j]+table2[j]+table3[j-1]+report[3][i];
				int All = max(first,max(second,third));
				
				if(first>second && first>third){
					table1[j] = table1[j-1]+report[1][i];
				}
				else if(first<second && second>third){
					table2[j] = table2[j-1]+report[2][i];
				}
				else if(third>second && first<third){
					table3[j] = table3[j-1]+report[3][i];
				}
			}
		}
		ans = table1[n/2]+table2[n/2]+table3[n/2];
		cout << ans;
	}
	return 0;
}
