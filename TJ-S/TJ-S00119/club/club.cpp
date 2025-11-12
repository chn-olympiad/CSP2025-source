#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int N=1e5+10;
const int INF=2e4+10;
int a[N][4];
bool f[N];
int n,sum=0,ma=-1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		bool only1=1;
		scanf("%d",&n);
		int lim=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
			//only1
			if(a[i][2]!=0||a[i][3]!=0){
				only1=0;
			}
		}if(only1){
			vector<int> temp(n+1);
			for(int i=1;i<=n;i++){
				temp[i]=a[i][1];
			}sort(temp.begin()+1,temp.end(),greater<int>());
			for(int i=1;i<=lim;i++){
				sum+=temp[i];
			}printf("%d\n",sum);
			continue;
		}//else
		vector<int> cn(4,0);
		vector<int> rec(n+1);
		int sum=0;
		for(int i=1;i<=n;i++){
			int ma=a[i][1],ma_c=1;
			for(int j=2;j<=3;j++){
				if(a[i][j]>ma){
					ma=a[i][j];
					ma_c=j;
				}
			}
			rec[i]=ma;
			sum+=ma;
			cn[ma_c]++;			
		}bool flag=1;
		int k;
		for(int i=1;i<=3;i++){
			if(cn[i]>lim){
				k=i;
				flag=0;
			}
		}
		while(flag==0) {
			int mi=INF,mi_lie,mi_hang;
			for(int j=1;j<=4;j++){
				if(rec[j]==a[j][k]){	
					if(k==1){
						if(rec[j]-a[j][2]>=rec[j]-a[j][3]&&mi>=rec[j]-a[j][3]){
							mi=rec[j]-a[j][3];
							mi_lie=3;
							mi_hang=j;
						}else if(rec[j]-a[j][2]<rec[j]-a[j][3]&&mi>rec[j]-a[j][2]){
							mi=rec[j]-a[j][2];
							mi_lie=2;
							mi_hang=j;
						}
					}if(k==2){
						if(rec[j]-a[j][1]>=rec[j]-a[j][3]&&mi>=rec[j]-a[j][3]){
							mi=rec[j]-a[j][3];
							mi_lie=3;
							mi_hang=j;
							
						}else if(rec[j]-a[j][1]<rec[j]-a[j][3]&&mi>rec[j]-a[j][1]){
							mi=rec[j]-a[j][1];
							mi_lie=1;
							mi_hang=j;
							
						}
					}if(k==3){
						if(rec[j]-a[j][1]>=rec[j]-a[j][2]&&mi>=rec[j]-a[j][2]){
							mi=rec[j]-a[j][2];
							mi_lie=2;
							mi_hang=j;
						}else if(rec[j]-a[j][1]<rec[j]-a[j][2]&&mi>rec[j]-a[j][1]){
							mi=rec[j]-a[j][1];
							mi_lie=1;
							mi_hang=j;
						}
					}
				}
			}
			sum-=mi;
			rec[mi_hang]=a[mi_hang][mi_lie];
			cn[k]--;
			cn[mi_lie]++;	
			flag=1;
			for(int i=1;i<=3;i++){
				if(cn[i]>lim){
					k=i;
					flag=0;
				}
			}
		}printf("%d\n",sum);
	}
	return 0;
}
