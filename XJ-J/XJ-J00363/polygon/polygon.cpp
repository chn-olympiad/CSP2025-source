#include<iostream>
#include<algorithm>

using namespace std;

int r[100000];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>r[i];
	} 
	sort(r+1,r+n+1);
	
	int ans = 0,max,sum = 0;
	max = r[n]*2;







	if(n == 3){
		sum = r[1]+r[2]+r[3];
	}
	if(sum>max){
		cout<<1;
	}else{
		cout<<0;
	}
	
	if(r[i]+r[j]+r[k] == max){
						sum++;
					}
	if(n = 4){
		for(int i = 1;i<=n;i++){
			for(int j = 2;j<=n;j++){
				for(int k = 3;k<=n;++){
					if(r[i]+r[j]+r[k] == max){
						sum++;
					}	
				}
				
			}
		}
		for(int i = 1;i<=n;i++){
			for(int j = 2;j<=n;j++){
				for(int k = 3;k<=n;j++){
					for(int h = 4;h<=n;h++){
						if(r[i]+r[j]+r[k]+r[h] == max){
							sum++;
						}
					}	
				}
				
			}
		}
		cout<<sum;
	}
	if(n = 5){
		for(int i = 1;i<=n;i++){
			for(int j = 2;j<=n;j++){
				for(int k = 3;k<=n;++){
					if(r[i]+r[j]+r[k] == max){
						sum++;
					}	
				}
				
			}
		}
		for(int i = 1;i<=n;i++){
			for(int j = 2;j<=n;j++){
				for(int k = 3;k<=n;j++){
					for(int h = 4;h<=n;h++){
						if(r[i]+r[j]+r[k]+r[] == max){
							sum++;
						}
					}	
				}
				
			}
		}
		
		
		
		
		for(int i = 1;i<=n;i++){
			for(int j = 2;j<=n;j++){
				for(int k = 3;k<=n;j++){
					for(int h = 4;h<=n;h++){
						for(int p = 5;p<=n;p++){
							if(r[i]+r[j]+r[k]+r[h]+r[p] == max){
								sum++;
							}
						}
					}	
				}
				
			}
		}
	cout<<sum;
	}
	
	
	
	return 0;
} 
