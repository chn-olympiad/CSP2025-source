#include<iostream>
using namespace std;
freopen("club.in";"r";stdin);
freopen("club.out";"w";stdout);
int main(){
	int yi=0,er=0,san=0,bu=0,duyi=0,duer=0,dusan=0,du=0;
	int a,b,c;
	int t,n,an=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a>>b>>c;
			if(a>b&&a>c){
				yi++;
				duyi+=a;
			}
			else if(b>a&&b>c){
				er++;
				duer+=b;
			}
			else if(c>a&&c>b){
				san++;
				dusan+=c;
			}
		bu=n/2;
		if(yi<=bu){
			du+=duyi;
		}
		else if(er<=bu){
			du+=duer;
		}
	    else if(san<=bu){
	    	du+=dusan;
		}
		}
	    cout<<du;
	}
	return 0;
}
