#include <bits/stdc++.h>
using namespace std;
const int N=210;
int a[N],b[N],c[N],ans,n;
void S(int id,int sum,int l1,int l2,int l3){
	if(id>n){
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(l1!=0){
			if(id==n){
				ans=max(ans,sum);
				return ;
			} 
			S(id+1,sum+a[id],l1-1,l2,l3);
		}
		if(l2!=0){
			if(id==n){
				ans=max(ans,sum);
				return ;
			}
			S(id+1,sum+b[id],l1,l2-1,l3);
		}
		if(l3!=0){
			if(id==n){
				ans=max(ans,sum);
				return ;
			}
			S(id+1,sum+c[id],l1,l2,l3-1);
		}
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		int fl1=1,fl2=1,fl3=1;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]!=0){
				fl1=0;
			}
			if(b[i]!=0){
				fl2=0;
			}
			if(c[i]!=0){
				fl3=0;
			}
		}
		if(fl1){
			if(fl2){
				if(fl3){
					cout<<0<<endl;
					continue;
				}
				sort(c+1,c+n+1);
				for(int i=n;i>n/2;i--){
					ans+=c[i];
				}
				cout<<ans<<endl;
				continue;
			}
			if(fl3){
				sort(b+1,b+n+1);
				for(int i=n;i>n/2;i--){
					ans+=b[i];
				}
				cout<<ans<<endl;
				continue;
			}
		}
		if(fl2){
			if(fl3){
				sort(a+1,a+n+1);
				for(int i=n;i>n/2;i--){
					ans+=a[i];
				}
				cout<<ans<<endl;
				continue;
			}
		}
		S(1,0,n/2,n/2,n/2);
		cout<<ans<<endl;
	}
	return 0;
}
