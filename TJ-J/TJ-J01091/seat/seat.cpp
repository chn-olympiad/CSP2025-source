#include<bits/stdc++.h>//hujunqin
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int R=0;
	int score[121]={0};
	int k=0;
	for(;k<n*m;k++){
		cin>>score[k];
	}
	R=score[0];
	sort(score,score+n*m);
	k--;
	int seat[11][11]={0};
	for(int i=0;i<m;i++){
		for(int j=0;j<n&&i%2==0;j++){
			if(score[k]==R){
				cout<<i+1<<" "<<j+1;
				return 0;
			}
			k--;
		}
		for(int j=n-1;j>=0&&i%2==1;j--){
			if(score[k]==R){
				cout<<i+1<<" "<<j+1;
				return 0;
			}
			k--;
		}
	}
	return 0;
}
