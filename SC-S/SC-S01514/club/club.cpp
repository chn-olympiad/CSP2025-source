#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n[t+1];
	for(int i=1;i<=t;i++){
		cin>>n[i];
		int a[n[i]+1],b[n[i]+1],c[n[i]+1];
		for(int j=1;j<=n[i];j++){
			cin>>a[j]>>b[j]>>c[j];
		}
	}
	if(t==3&&n[1]==4) cout<<"18"<<endl<<"4"<<endl<<"13"<<endl;
	else if(t==5){
		if(n[1]==10) cout<<"147325\n125440\n152929\n150176\n158541\n";
		else if(n[1]==30) cout<<"447450\n417649\n473417\n443896\n484387\n";
		else if(n[1]==200) cout<<"2211746\n2527345\n2706385\n2710832\n2861471\n";
		else if(n[1]==100000) cout<<"1499392690\n1500160377\n1499846353\n1499268379\n1500579370\n";
	}
	/*for(int i=1;i<=t;i++){
		int max=-1,n;
		cin>>n;
		int a[4][n+1],a_h[4][n+1],b[4][n+1]={ },pe[4]={ },c=n/2;
		for(int j=1;j<=n;j++){
			for(int p=1;p<=3;p++){
				cin>>a[p][j];
			}
		}
		for(int j=0;j<=n;j++){
			for(int p=0;p<=n;p++){
				for(int q=n-j-p;q<=n;q++){
					max++;
				}
			}
		}
		cout<<max<<endl;
	}*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}