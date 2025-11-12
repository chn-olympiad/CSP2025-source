#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s,w=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		int x;
		cin>>x;
		if(i==0){
			s=x;
		}else{
			if(x>s)w++;
		}
	}
	int ans1=(w)/n+1;
	int ans2;
	if(ans1%2==1){
		ans2=(w)%n+1;
	}else{
		ans2=n-(w)%n;
	}
	printf("%d %d",ans1,ans2);
}
