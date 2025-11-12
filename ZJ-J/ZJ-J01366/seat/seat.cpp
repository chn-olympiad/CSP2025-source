#include<bits/stdc++.h>
using namespace std;

int n,m;
int soc[20005];

int solve(int x){
	int lie=ceil(x*1.0/n*1.0);
	int hang=-1;
	
	if(lie%2==0){//start from n
		int tmp=x%n;
		if(tmp==0){
			hang=1;
		}else{
			hang=n-tmp+1;
		}
		
		
		//cout<<tmp<<endl;
	}else{ // start from 1
		int tmp=x%n;
		if(tmp==0){//tmp==n
			hang=n;
		}else{
			hang=tmp;
		}
		
		
	}
	
	cout<<lie<<" "<<hang<<endl;
}

int main(){

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>soc[i];
		
	}
	int findex=soc[1];
	//cout<<findex<<endl;
	sort(soc+1,soc+1+n*m);
	
	int index=1;
	
	for(int i=n*m;i>=1;i--){
		//cout<<soc[i]<<endl;
		if(soc[i]==findex){
			break;
		}
		index++;
	}
	
	//cout<<index<<endl;
	
	solve(index);
	
	
	
	
	
	return 0;
}
//By StuffyWalk Problem 2
