#include <bits/stdc++.h>
using namespace std;
int t,n,person[4],ans;
struct A{
	int a1,a2,a3,max,minimax,maxi,minimaxi;
}a[100005];
bool cmp(A x,A y){
	return (x.max-x.minimax)<(y.max-y.minimax);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=person[1]=person[2]=person[3]=0;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a1>=a[i].a2&&a[i].a2>=a[i].a3){
				a[i].max=a[i].a1;
				a[i].minimax=a[i].a2;
				a[i].maxi=1;
				a[i].minimaxi=2;
				person[1]++;
			}
			else if(a[i].a1>=a[i].a3&&a[i].a3>=a[i].a2){
				a[i].max=a[i].a1;
				a[i].minimax=a[i].a3;
				a[i].maxi=1;
				a[i].minimaxi=3;
				person[1]++;
			}
			else if(a[i].a2>=a[i].a1&&a[i].a1>=a[i].a3){
				a[i].max=a[i].a2;
				a[i].minimax=a[i].a1;
				a[i].maxi=2;
				a[i].minimaxi=1;
				person[2]++;
			}
			else if(a[i].a2>=a[i].a3&&a[i].a3>=a[i].a1){
				a[i].max=a[i].a2;
				a[i].minimax=a[i].a3;
				a[i].maxi=2;
				a[i].minimaxi=3;
				person[2]++;
			}
			else if(a[i].a3>=a[i].a1&&a[i].a1>=a[i].a2){
				a[i].max=a[i].a3;
				a[i].minimax=a[i].a1;
				a[i].maxi=3;
				a[i].minimaxi=1;
				person[3]++;
			}
			else if(a[i].a3>=a[i].a2&&a[i].a2>=a[i].a1){
				a[i].max=a[i].a3;
				a[i].minimax=a[i].a2;
				a[i].maxi=3;
				a[i].minimaxi=2;
				person[3]++;
			}
			ans+=a[i].max;
		}
		sort(a+1,a+n+1,cmp);
		if(person[1]<=n/2&&person[2]<=n/2&&person[3]<=n/2){
			cout<<ans<<endl;
		}
		else if(person[1]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].maxi==1){
						ans-=a[i].max-a[i].minimax;
						person[1]--;
						person[a[i].minimaxi]++;
				}
				if(person[1]<=n/2){
					cout<<ans<<endl;
					break;
				}
			}
		}
		else if(person[2]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].maxi==2){
						ans-=a[i].max-a[i].minimax;
						person[2]--;
						person[a[i].minimaxi]++;
				}
				if(person[2]<=n/2){
					cout<<ans<<endl;
					break;
				}
			}
		}
		else if(person[3]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].maxi==3){
						ans-=a[i].max-a[i].minimax;
						person[3]--;
						person[a[i].minimaxi]++;
				}
				if(person[3]<=n/2){
					cout<<ans<<endl;
					break;
				}
			}
		}
	}
	return 0;
}