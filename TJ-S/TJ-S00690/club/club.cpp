#include<bits/stdc++.h>
using namespace std;
int t;
int n,a,b,c;
int s(int a,int b,int c){
	if(a>b){
		if(a>c){
			return 1;
		}
		if(a<c){
			return 3;
		}
	}
	if(a<b){
		if(b<c){
			return 3; 
		}
		if(b>c){
			return 2;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int sum=0,a1=0,a2=0,a3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			if(s(a,b,c)==1){
				if(a1<n/2){
					sum+=a;
					a1++;
				}
				else{
					if(s(0,b,c)==2){
						if(a2<n/2){
							sum+=b;
							a2++;
						}
						else{
							if(a3<n/2){
								sum+=c;
								a3++;
							}
						}
					}
					else{
						if(a3<n/2){
							sum+=c;
							a3++;
						}
						else{
							if(a2<n/2){
								sum+=b;
								a2++;
							}
						}
					}
				}
			}
			else if(s(a,b,c)==2){
				if(a2<=n/2){
					sum+=b;
					a2++;
				}
				else{
					if(s(a,0,c)==1){
						if(a1<=n/2){
							sum+=a;
							a1++;
						}
						else{
							if(a3<=n/2){
								sum+=c;
								a3++;
							}
						}
					}
					else{
						if(a3<=n/2){
							sum+=c;
							a3++;
						}
						else{
							if(a1<=n/2){
								sum+=a;
								a1++;
							}
						}
					}
				}
			}
			else if(s(a,b,c)==3){
				if(a3<=n/2){
					sum+=c;
					a3++;
				}
				else{
					if(s(a,b,0)==1){
						if(a1<=n/2){
							sum+=a;
							a1++;
						}
						else{
							if(a2<=n/2){
								sum+=b;
								a2++;
							}
						}
					}
					else{
						if(a2<=n/2){
							sum+=b;
							a2++;
						}
						else{
							if(a1<=n/2){
								sum+=a;
								a1++;
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
