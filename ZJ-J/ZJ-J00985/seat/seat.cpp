#include <bits/stdc++.h>

using namespace std;
int n,m;
const int N=1e5+5;
struct Node{
	int score;
	bool f=0;
}test[N];

bool cmp(Node a,Node b){
	return a.score>b.score;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	test[1].f=1;
	for(int i=1;i<=n*m;i++){
		cin>>test[i].score;
	}
	sort(test+1,test+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(test[i].f){
			int c=i;
			int ans1=(c-1)/n+1;
			int ans2=0;
//			cout<<c<<endl;
			if(ans1%2==0){
				ans2=n-((c-1)%n);
			}
			else{
				ans2=(c-1)%n+1;
			}
			cout<<ans1<<' '<<ans2<<endl;
			break;
		}
	}
	return 0;
}

