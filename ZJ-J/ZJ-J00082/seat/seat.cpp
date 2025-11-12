#include<iostream>
#include<algorithm>
using namespace std;
int score[101];
int tmp[101];
//int mp[11][11];
const bool up=1;
const bool down=0;
//void merge(int s,int t){
//	if(s==t)return;
//	int mid=s+(t-s)/2;
//	merge(s,mid);
//	merge(mid+1,t);
//	for(int i=1;i<=mid;i++)tmp[i]=score[i];
//	int i=s-1,j=mid,top=s-1;
//	while(i<=mid&&j<=t){
//		if(tmp[i]<score[j]){
//			score[++top]=tmp[++i];
//		}else{
//			score[++top]=score[++j];
//		}
//	}
//	while(i<=mid)score[++top]=tmp[++i];
//	while(j<=t)score[++top]=score[++j];
//}
bool cmp(int a,int b){
	return a>=b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++){
		cin>>score[i];
	}int aim=score[1];
	sort(score+1,score+n*m+1,cmp);
	int x=1;
	int y=1;
	bool dir=down;
	for(int i=1;i<=n*m;i++){
		//mp[y][x]=score[i];
		if(score[i]==aim){
			cout<<x<<' '<<y<<endl;
			break;
		}
		if(dir==down){
			if(y==n){
				x++;
				dir=up;
			}
			else y++;
		}
		else if(dir==up){
			if(y==1){
				x++;
				dir=down;
			}
			else y--;
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=n;j++){
//			cout<<mp[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	return 0;
}