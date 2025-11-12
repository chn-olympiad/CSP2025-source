#include<bits/stdc++.h>
using namespace std;

//struct cg{
//	int from;
//	int to;
//	int cost;
//};

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int nbak=n;
		int a[3][1005],stu[3][1005];
//		vector<pair<int,int> > cost[100005];
//		cg change[100005];
//		memset(amax,0,sizeof(amax));
		for(int i=1; i<=n; i++) {

			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if(a[1][i]>a[2][i]&&a[1][i]>a[3][i]) {
				stu[1][i]=1;
				if(a[2][i]>a[3][i]) {
					stu[2][i]=2;
					stu[3][i]=3;
				} else {
					stu[2][i]=3;
					stu[3][i]=2;
				}
			}

			if(a[2][i]>a[1][i]&&a[2][i]>a[3][i]) {
				stu[1][i]=2;
				if(a[1][i]>a[3][i]) {
					stu[2][i]=1;
					stu[3][i]=3;
				} else {
					stu[2][i]=3;
					stu[3][i]=1;
				}
			}

			if(a[3][i]>a[1][i]&&a[3][i]>a[2][i]) {
				stu[1][i]=3;
				if(a[1][i]>a[2][i]) {
					stu[2][i]=1;
					stu[3][i]=2;
				} else {
					stu[2][i]=2;
					stu[3][i]=1;
				}
			}

		}
		int d[3];
		d[1]=0;
		d[2]=0;
		d[3]=0;
		int res=0;

		for(int i=1; i<=n; i++) {

			res+=a[stu[1][i]][i];
			d[stu[1][i]]++;
//			res+=a[stu[1][i]][i];
//			d[stu[1][i]]++;
			
		}
//		for(int i=1;i<=n;i++)cout<<stu[1][i]<<endl;
//		for(int i=1; i<=3; i++) {
//			cout<<d[i]<<' '<<n<<endl;
//			if(d[i]>n/2) {
//				int cost[3];cost[1]=cost[2]=cost[3]=2e4+5;
//				for(int j=1;j<=n;j++){
//					cout<<stu[1][j]<<endl;
//					cout<<a[stu[1][j]][j]<<' '<<a[stu[2][j]][j]<<' '<<a[stu[3][j]][j]<<endl;
//					if(stu[1][j]==i){
//						cout<<a[stu[1][j]][j]<<' '<<a[stu[2][j]][j]<<' '<<a[stu[3][j]][j]<<endl;
//						if(stu[1][j]-stu[2][j]<cost[1]){
//							if(stu[1][j]-stu[2][j]<cost[2]){
//								if(stu[1][j]-stu[2][j]<cost[3])
//									cost[3]=stu[1][j]-stu[2][j];
//								else
//									cost[2]=stu[1][j]-stu[2][j];
//							}
//							else{
//								cost[1]=stu[1][j]-stu[2][j];
//							}
//						}
//					}
//				}
//				cout<<cost[1]<<' '<<cost[2]<<' '<<cost[3]<<endl;
//				res=res-cost[1]-cost[2]-cost[3];
//			}
//		}
		cout<<res<<endl;
	}
	return 0;
}


//4 2 1   1
//3 2 4   3
//5 3 4   1
//3 5 1   2
//
//
//
//10 9 8   1
//4 0 0    1
//
//2020 14533 18961     3     3: 7
//2423 15344 16322     3     2: 1
//1910 6224 16178      3     1: 2
//2038 9963 19722      3     Tot: 10
//8375 10557 5444  	 2     Half: 5
//3518 14615 17976 	 3
//6188 13424 16615 	 3
//8769 509 4394    	 1
//958 3195 9953    	 3
//16441 5313 10926 	 1
//#include<bits/stdc++.h>
//using namespace std;
//
////struct cg{
////	int from;
////	int to;
////	int cost;
////};
//
//int main() {
//	freopen("1.in","r",stdin);
////	freopen("club.out","w",stdout);
//	int t;
//	cin>>t;
//	while(t--) {
//		int n;
//		cin>>n;
//		int nbak=n;
//		int a[3][1005],stu[3][1005];
////		vector<pair<int,int> > cost[100005];
////		cg change[100005];
////		memset(amax,0,sizeof(amax));
//		for(int i=1; i<=n; i++) {
//
//			cin>>a[1][i]>>a[2][i]>>a[3][i];
//			if(a[1][i]>a[2][i]&&a[1][i]>a[3][i]) {
//				stu[1][i]=1;
//				if(a[2][i]>a[3][i]) {
//					stu[2][i]=2;
//					stu[3][i]=3;
//				} else {
//					stu[2][i]=3;
//					stu[3][i]=2;
//				}
//			}
//
//			if(a[2][i]>a[1][i]&&a[2][i]>a[3][i]) {
//				stu[1][i]=2;
//				if(a[1][i]>a[3][i]) {
//					stu[2][i]=1;
//					stu[3][i]=3;
//				} else {
//					stu[2][i]=3;
//					stu[3][i]=1;
//				}
//			}
//
//			if(a[3][i]>a[1][i]&&a[3][i]>a[2][i]) {
//				stu[1][i]=3;
//				if(a[1][i]>a[2][i]) {
//					stu[2][i]=1;
//					stu[3][i]=2;
//				} else {
//					stu[2][i]=2;
//					stu[3][i]=1;
//				}
//			}
//
//		}
//		int d[3];
//		d[1]=0;
//		d[2]=0;
//		d[3]=0;
//		int res=0;
//
//		for(int i=1; i<=n; i++) {
//			res+=a[stu[1][i]][i];
//			d[stu[1][i]]++;	
//		}
//		for(int i=1;i<=n;i++){
//			cout<<stu[1][i]<<' '<<stu[2][i]<<' '<<stu[3][i]<<endl;
//		}
//		for(int i=1; i<=3; i++) {
//			cout<<d[i]<<' '<<n<<endl;
//			if(d[i]>n/2){
//				int reqcg=d[i]-(n/2);
//				int cost[10000];
//				memset(cost,0x3f,sizeof(cost));
//				for(int j=1;j<=n;j++){
//					int g=1;
//					if(stu[1][j]==i){
//						int p=1;
//						cout<<a[stu[1][j]][j]<<' '<<a[stu[2][j]][j]<<' '<<a[stu[3][j]][j]<<endl;
//						for(int i=1;i<=reqcg;i++){
//							int p=111;
//							if(cost[i]>(stu[1][j]-stu[2][j])){
//								cost[i+1]=cost[i];
//								cost[i]=stu[1][j]-stu[2][j];
//							}
//						}
//						cout<<"did"<<endl;
//					}
//				}
//				cout<<"succeed"<<endl;
//			}
////			if(d[i]>n/2) {
////				int cost3;cost1=cost2=cost3=2e4+5;
////				for(int j=1;j<=n;j++){
////					cout<<stu[1][j]<<endl;
////					cout<<a[stu[1][j]][j]<<' '<<a[stu[2][j]][j]<<' '<<a[stu[3][j]][j]<<endl;
////					if(stu[1][j]==i){
////						cout<<a[stu[1][j]][j]<<' '<<a[stu[2][j]][j]<<' '<<a[stu[3][j]][j]<<endl;
////						if(stu[1][j]-stu[2][j]<cost1){
////							if(stu[1][j]-stu[2][j]<cost2){
////								if(stu[1][j]-stu[2][j]<cost3)
////									cost3=stu[1][j]-stu[2][j];
////								else
////									cost2=stu[1][j]-stu[2][j];
////							}
////							else{
////								cost1=stu[1][j]-stu[2][j];
////							}
////						}
////					}
////				}
////				cout<<cost1<<' '<<cost2<<' '<<cost3<<endl;
////				res=res-cost1-cost2-cost3;
////			}
//		}
//		cout<<res<<endl;
//	}
//	return 0;
//}
//
//




