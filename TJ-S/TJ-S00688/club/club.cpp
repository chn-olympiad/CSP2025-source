#include<bits/stdc++.h>
using namespace std;int l[100000][8];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,d[4]={},s=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			l[i][3]=0;l[i][4]=0;l[i][5]=0;l[i][6]=0;
			cin>>l[i][0]>>l[i][1]>>l[i][2];
		}for(int i=1;i<=n;i++){int m1=6,m2=6;
			for(int j=0;j<3;j++){
				if(l[i][m1]<l[i][j]){
					m2=m1;m1=j;
				}else if(l[i][m2]<l[i][j]){
					m2=j;
				}
			}l[i][3]=m1;l[i][4]=m2;
			l[i][5]=l[i][l[i][3]]-l[i][l[i][4]];
			
		}for(int i=1;i<=n;i++){
			d[l[i][3]]++;s+=l[i][l[i][3]];
		}if(d[0]>n/2||d[1]>n/2||d[2]>n/2){
			if(d[0]>n/2){
				for(int i=1;i<=d[0]-n/2;i++){int mi=214748364,k=0;
					for(int j=1;j<=n;j++){
						if(l[j][3]==0&&mi>l[j][5]){
							mi=l[j][5];k=j;
						}
					}s-=l[k][5];l[k][3]=l[k][4];
				}
			}else if(d[1]>n/2){
				for(int i=1;i<=d[1]-n/2;i++){int mi=214748364,k=0;
					for(int j=1;j<=n;j++){
						if(l[j][3]==1&&mi>l[j][5]){
							mi=l[j][5];k=j;
						}
					}s-=l[k][5];l[k][3]=l[k][4];
				}
			}else if(d[2]>n/2){
				for(int i=1;i<=d[2]-n/2;i++){int mi=214748364,k=0;
					for(int j=1;j<=n;j++){
						if(l[j][3]==2&&mi>l[j][5]){
							mi=l[j][5];k=j;
						}
					}s-=l[k][5];l[k][3]=l[k][4];
				}
			}cout<<s<<endl;
		}else cout<<s<<endl;
	}
}/*3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
