#include<bits/stdc++.h>
using namespace std;
int grade[100000];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,rrr;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>grade[i];
		
	}
	rrr=grade[1];
	sort(grade+1,grade+m*n+1);

	int i=1,j=1;
	for(int k=n*m-1;k>=1;k--){
		if(i%2==0){
			j--;
		}
		else{
			j++;
		}		
		
		
		
		if(j>n||j<1){

			i+=1;
			if(i%2==0){
				j--;
			}
			else{
				j++;
			}			
			
		}	
	

		if(grade[k]==rrr){
			cout<<i<<" "<<j;
			return 0;
		}
		
		
	}
	
	
	
	
	
}
