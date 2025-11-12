#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
    int n,t,ans=0;
    cin>>t;
    cin>>n;
    cin>>ans;
    n%2==0;
	int i1,i2,i3;
	cin>>i1,i2,i3;
	for(i1=0;i1<=10;i1++){
		for(i2=0;i2<=10;i2++){
			for(i3=0;i3<=10;i3++){
				if(i1>i2>i3){
					cout<<i1;
				}
				else if(i2>i1>i3){
					cout<<i2;
				}
				else{
					cout<<i3;
				}
			
				ans=i1+i2+i3;
				cout<<ans;
				}
			}
		}
	}
	
	}
	
	
	
	
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
