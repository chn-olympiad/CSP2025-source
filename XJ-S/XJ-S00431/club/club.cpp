//#include<bits/stdc++.h>
//using namespace std;
//int sum,ans;
//const int N=1e5;
//int n;
//int club[5];
//int a[N][5],vic[N][5];
//void choose(int depth){
//	if(depth>n){
//		return;
//	}
//	for(int i=1;i<=n;i++){
//		if(club[depth]>n/2){
//			continue;
//		}
//		if(vic[i][depth]==1)continue;
//		cout<<sum<<"+";
//		sum+=a[i][depth];
//		cout<<a[i][depth]<<"***";
//		vic[i][depth]=1;
//		club[depth]++;
//		//depth++;
//		choose(depth);
//		ans=max(sum,ans);
//		//sum-=a[i][depth];
//		//club[depth]--;
//		vic[i][depth]=0;
//		//cout<<"*"<<sum;
//		depth++;
//		sum=0;
//	}
//}
//int main(){
//	//freopen("club.in","r",stdin);
//	//freopen("club.out","w",stdout);
//	int t;
//	cin>>t;
//	while(t--){
//		cin>>n;
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++){
//				cin>>a[i][j];
//			}
//		}
//		choose(1);
//		cout<<ans<<endl;
//		ans=0;sum=0;
//	}
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
int sum;
const int N=1e5;
int n;
int as,bs,cs;
struct stk {
	int num;
	int t;
} a[N],b[N],c[N];
void choose() {

	for(int i=1; i<=n; i++) {
		int max1=max(a[i].t,b[i].t);
		int max2=max(max1,c[i].t);
		if(a[i].t==max2)as++;
		if(b[i].t==max2)bs++;
		else cs++;
		sum+=max2;

	}
}
bool cmp(stk a,stk b) {
	return a.t>=b.t;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		sum=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i].t>>b[i].t>>c[i].t;
			a[i].num=i;
			b[i].num=i;
			c[i].num=i;
		}
//		sort(a+1,a+n+1,cmp);
//		sort(b+1,b+n+1,cmp);
//		sort(c+1,c+n+1,cmp);
		choose();
		cout<<sum<<endl;
	}

	return 0;
}
