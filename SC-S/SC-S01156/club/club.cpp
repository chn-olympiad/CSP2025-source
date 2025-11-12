#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int t,n,a[100100][4],b[100100],c[100100],v[100100],num,cnt[4],fff;
void init(int x){//你初始化了吗 
    for(int i=1; i<=x; i++){
    	a[i][1]=0;
    	a[i][2]=0;
    	a[i][3]=0;
    	b[i]=0;
    	c[i]=0;
    	v[i]=0;
	}
	num=0;
	cnt[1]=0;
	cnt[2]=0;
	cnt[3]=0;
	fff=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
//		cout<<"++++++++"<<endl;
		cin>>n;
		init(n);
		for(int i=1; i<=n; i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
				b[i]=1;
				c[i]=a[i][1]-min(a[i][2],a[i][3]);
				
			}
			else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
				b[i]=2;
				c[i]=a[i][2]-min(a[i][1],a[i][3]);
			}
			else if(a[i][3]>=a[i][2] && a[i][3]>=a[i][1]){
				b[i]=3;
				c[i]=a[i][3]-min(a[i][2],a[i][1]);
			}
		}
//		for(int i=1; i<=n; i++){
//			cout<<b[i]<<' ';
//		}
//		cout<<endl;
		pair<int,int> cl[100100];
		for(int i=1; i<=3; i++){
		    int sum=0;
			for(int j=1; j<=n; j++){
				if(b[j]==i){
					sum++;
					cl[sum].first=c[j];
					cl[sum].second=j;
				}
			}
			sort(cl+1,cl+sum+1);
//			cout<<sum<<")";
			for(int j=sum; j>=1; j--){
				if(cnt[i]>=n/2){
					fff=i;
					break;
				}
				v[cl[j].second]=1;
				num+=a[cl[j].second][i];
				cnt[i]++;
//				cout<<i<<' '<<cl[j].second<<' '<<a[cl[j].second][i]<<endl;
			}
			for(int j=1; j<=sum; j++){
				cl[sum].first=0;
				cl[sum].second=0;
			}
		}
		for(int i=1; i<=n; i++){
			if(v[i]==0){
//				cout<<"^V^"<<endl;
				if(fff==1){
					v[i]=1;
					num+=max(a[i][3],a[i][2]);
//					cout<<"1";
				}
				else if(fff==2){
					v[i]=1;
					num+=max(a[i][1],a[i][3]);
//					cout<<"2";
				}
				else if(fff==3){
					v[i]=1;
					num+=max(a[i][1],a[i][2]);
//					cout<<"3";
				}
			}
		}
		cout<<num<<endl;
	}
	return 0;
}