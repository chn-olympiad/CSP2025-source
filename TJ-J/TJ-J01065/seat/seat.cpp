#include<bits/stdc++.h>
using namespace std;
int n,m,l;
int score[101];
int LittleR_Score,rank;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>score[i];
	LittleR_Score=score[1];
	sort(score+1,score+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(LittleR_Score==score[i]){
			rank=i;
			break;
		}
	}
	if(rank%n==0){
		cout<<rank/n<<" ";
		l=rank/n;
	}else{
		cout<<rank/n+1<<" ";
		l=(rank/n)+1;
	}
	if(l%2==1){
		if(rank%n==0) cout<<n;
		else cout<<rank%n;
	}else{
		if(rank%n==0) cout<<1;
		else cout<<n-rank%n+1; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
