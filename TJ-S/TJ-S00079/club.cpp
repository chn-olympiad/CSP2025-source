#include<bits/stdc++.h>
using namespace std;
struct xx{
	int one,two,three;
};
xx arr[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t>>n;
	int sum=0;
	int yzr=0;
	int ezr=0;
	int szr=0;
	for(int w=1;w<=t;w++){
		for(int i=1;i<=n;i++){
			cin>>arr[i].one>>arr[i].two>>arr[i].three;
			sort(arr[1].one,arr[n+1].one);
			sort(arr[1].two,arr[n+1].two);
			sort(arr[1].three,arr[n+1].three);
			for(int j=i;j>=1;j--){
			
				if(arr[j].one>arr[n].two>arr[n].three){
					yzr++;
					if(yzr<=n/2){
						sum+=arr[j].one;
					}else{
						ezr++;
						if(ezr<=n/2){
							sum+=arr[n].two;
							ezr++;
							if(arr[j].two>arr[n].three&&ezr<=n/2){
								sum+=arr[j].two;
							}
							szr++;
							if(szr<=n/2){
								sum+=arr[n].three;
								szr++;
								if(szr<=n/2){
									sum+=arr[j].three;
								}
							}
						}
					}
				
				}
				if(arr[j].two>arr[n].one>arr[n].three){
					ezr++;
					if(ezr<=n/2){
						sum+=arr[j].two;
					}else{
						yzr++;
						if(yzr<=n/2){
							sum+=arr[n].one;
							yzr++;
							if(arr[j].one>arr[n].three&&yzr<=n/2){
								sum+=arr[j].one;
							}
							szr++;
							if(szr<=n/2){
								sum+=arr[n].three;
								szr++;
								if(szr<=n/2){
									sum+=arr[j].three;
								}
							}
						}
					}
				
				}
				if(arr[j].three>arr[n].two>arr[n].one){
					szr++;
					if(szr<=n/2){
						sum+=arr[j].three;
					}else{
						ezr++;
						if(ezr<=n/2){
							sum+=arr[n].two;
							ezr++;
							if(arr[j].two>arr[n].three&&ezr<=n/2){
								sum+=arr[j].two;
							}
							yzr++;
							if(yzr<=n/2){
								sum+=arr[n].one;
								yzr++;
								if(yzr<=n/2){
									sum+=arr[j].one;
								}
							}
						}
					}
				
				}
				if(arr[j].one>arr[n].three>arr[n].two){
					yzr++;
					if(yzr<=n/2){
						sum+=arr[j].one;
					}else{
						szr++;
						if(szr<=n/2){
							sum+=arr[n].three;
							szr++;
							if(arr[j].three>arr[n].two&&szr<=n/2){
								sum+=arr[j].three;
							}
							ezr++;
							if(ezr<=n/2){
								sum+=arr[n].two;
								ezr++;
								if(ezr<=n/2){
									sum+=arr[j].two;
								}
							}
						}
					}
				
				}
				if(arr[j].two>arr[n].three>arr[n].one){
					ezr++;
					if(ezr<=n/2){
						sum+=arr[j].two;
					}else{
						szr++;
						if(szr<=n/2){
							sum+=arr[n].three;
							szr++;
							if(arr[j].three>arr[n].one&&szr<=n/2){
								sum+=arr[j].three;
							}
							yzr++;
							if(yzr<=n/2){
								sum+=arr[n].one;
								yzr++;
								if(yzr<=n/2){
									sum+=arr[j].one;
								}
							}
						}
					}
				
				}
				if(arr[j].three>arr[n].one>arr[n].two){
					szr++;
					if(szr<=n/2){
						sum+=arr[j].three;
					}else{
						yzr++;
						if(yzr<=n/2){
							sum+=arr[n].one;
							yzr++;
							if(arr[j].one>arr[n].two&&yzr<=n/2){
								sum+=arr[j].one;
							}
							ezr++;
							if(ezr<=n/2){
								sum+=arr[n].two;
								ezr++;
								if(ezr<=n/2){
									sum+=arr[j].two;
								}
							}
						}
					}
				
				}
			}
		}
	}	
	cout<<sum<<endl;
	
	
	
	
	return 0;
}
