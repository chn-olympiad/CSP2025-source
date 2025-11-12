#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int score[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int R;
	cin>>R;
	score[1]=R;
	for(int i=2;i<=n*m;i++){
		cin>>score[i];
	}
	sort(score+1,score+n*m+1,greater<int>());
	int ans=0;
	int x,y;
	for(int i=1;i<=m;i++){//lie
		if(i%2==1){
			for(int j=1;j<=n;j++){
				ans++;
				a[j][i]=score[ans];
				if(score[ans]==R){
					cout<<i<<" "<<j;
					return 0;
				}
				
			}
		}if(i%2==0){
			for(int j=n;j>=1;j--){
				ans++;
				a[j][i]=score[ans];
				if(score[ans]==R){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
