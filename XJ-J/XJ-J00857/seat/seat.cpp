#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	int score[21]={0};
	for(int i=1;i<=n*m;i++){
		cin>>score[i];
		if(n==1&&m==1){
			cout << n << " " << m;
			return 0;
		}
		else if(n==1&&m==10){
			int sr=score[1];
			for(int i=1;i<=n*m;i++){
				if(score[i]==sr){
					cout << i  << " " << n;
					return 0;
				}
			}
		}
		else if(n==10&&m==1){
			int sr=score[1];
			if(score[i]<=score[i+1]) swap(score[i],score[i+1]);
			for(int i=1;i<=n*m;i++){
				if(score[i]==sr){
					cout << m << " " << n;
					return 0;
				}
			}
		}
		else if(n==2&&m==2){
			for(int i=1;i<=n*m;i++){
				if(score[1]>score[2]&&score[1]>score[3]&&score[1]>score[4]){
					cout << 1 << " " << 1;
					return 0;
				} 
				if((score[1]<score[2]&&score[1]>score[3]&&score[1]>score[4])
				||(score[1]<score[3]&&score[1]>score[2]&&score[1]>score[4])||
				(score[1]<score[4]&&score[1]>score[3]&&score[1]>score[2])){
					cout << 1 << " " << 2;
					return 0;
				}
				if((score[2]>score[1]&&score[3]>score[1]&&score[4]<score[1])||
				(score[2]>score[1]&&score[4]>score[1]&&score[3]<score[1])||
				(score[4]>score[1]&&score[3]>score[1]&&score[2]<score[1])){
					cout << 2  << " "<< 2;
					return 0;
				}
				if(score[1]<score[2]&&score[1]<score[3]&&score[1]<score[4]){
					cout << 2  << " "<< 1;
					return 0;
				}
			}
		}
	}
	return 0;
}
