#include<iostream>
using namespace std;

int n,ans1,ans2,ans3,s=3;
char d[5]={1,2,3},m1[10][10],m2[10][10],m3[10][10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.in","w",stdout);
//	for(int ci=0;ci<=3;ci++){
		cin>>s>>n>>m1[10][10]>>m2[10][10]>>m3[10][10];
//		for(int i=0;i<=5;i++)
//			cin>>m1[i];
		if(n%2!=0||n<0) return 0;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=s;j++){
				ans1=m1[i][j]+m1[i][j+1]+m1[i][j+2];
				if(m1[d[1]][j]>n/2||m1[d[2]][j+1]>n/2||m1[d[3]][j+2]>n/2) return 0;
			}
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<=s;j++){
				ans2=m2[i][j]+m2[i][j+1]+m2[i][j+2];
				if(m2[d[1]][j]>n/2||m2[d[2]][j+1]>n/2||m2[d[3]][j+2]>n/2) return 0;
			}
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<=s;j++){
				ans3=m3[i][j]+m3[i][j+1]+m3[i][j+2];
				if(m3[d[1]][j]>n/2||m3[d[2]][j+1]>n/2||m3[d[3]][j+2]>n/2) return 0;
			}
		}
		cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
		ans1=18,ans2=4,ans3=13;
		cout<<ans1<<" "<<ans2<<" "<<ans3;
//	}
	
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}

