// 王尉骁 SN-S00485 西安市铁一中滨河高级中学
#include <bits/stdc++.h>
using namespace std;
long long t;
long long b[10001][10001];
int sum=0;
int maxn=-99999;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		sum=0;
		int a=0;
		cin>>a;
		for(int i=1;i<=a;i++){
			for(int j=1;j<=3;j++){
				cin>>b[i][j];
			}
		}
		for(int i=1;i<=a;i++){
				for(int j=1;j<=3;j++){
					if(b[i][j]>maxn){
						maxn=b[i][j];
					}
				}
				sum+=maxn;
		}
		cout<<sum<<endl;
	}
	return 0;
}
