#include<bits/stdc++.h>
using namespace std;
int a[5][100005];
int id[100005];
int cha[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int ans=0;
		int n;
		cin>>n;
		int yi=0,er=0,san=0;
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			int A,B,C;
			A=a[1][i];
			B=a[2][i];
			C=a[3][i];
			if(A>=B&&A >=C){
				id[i]=1;
				ans+=A;
				yi++;
			}
			else if(B>=A&&B>=C){
				id[i]=2;
				ans+=B;
				er++;
			}
			else{
				id[i]=3;
				ans+=C;
				san++;
			}
		}
		if(yi>n/2){
			int top=0;
			for(int i=1;i<=n;i++){
				if(id[i]==1){
					cha[++top]=a[1][i]-max(a[2][i],a[3][i]);
				}
			}
			sort(cha+1,cha+top+1);
			for(int i=1;i<=yi-n/2;i++){
				ans-=cha[i];
			}
			cout<<ans<<"\n";
		}
		else if(er>n/2){
			int top=0;
			for(int i=1;i<=n;i++){
				if(id[i]==2){
					cha[++top]=a[2][i]-max(a[1][i],a[3][i]);
				}
			}
			sort(cha+1,cha+top+1);
			for(int i=1;i<=er-n/2;i++){
				ans-=cha[i];
			}
			cout<<ans<<"\n";
		}
		else if(san>n/2){
			int top=0;
			for(int i=1;i<=n;i++){
				if(id[i]==3){
					cha[++top]=a[3][i]-max(a[2][i],a[1][i]);
				}
			}
			sort(cha+1,cha+top+1);
			for(int i=1;i<=san-n/2;i++){
				ans-=cha[i];
			}
			cout<<ans<<"\n";
		}
		else{
			cout<<ans<<"\n";
		}
	}
	return 0;
} 