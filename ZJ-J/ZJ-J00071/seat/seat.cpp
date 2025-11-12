#include<bits/stdc++.h>
using namespace std;
long long n,m,p,sc[1005];
long long se[1005][1005];
long long si=1,sj=1,rsc;
bool pd=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	p=n*m;
	for(int i=1;i<=p;i++){
		cin>>sc[i];
	}
	rsc=sc[1];
	sort(sc+1,sc+p+1);
	
	for(int i=p;i>=1;i--){
		se[si][sj]=sc[i];
//		cout<<sj<<" "<<si<<endl;
		if(sc[i]==rsc){
			cout<<sj<<" "<<si;
			break;
		}
		if(pd==0){
			if(si==m){
				pd=1;
				sj++;
			}
			else si++;
		}
		else{
			if(si==1){
				pd=0;
				sj++;
			}
			else si--;
		}
	}
	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<se[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
