#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][6],max1,mid1,min1,ans=0,o;
int q[3][100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(q,-1,sizeof(q));
		ans=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			max1=0;
			min1=0;
			for(int j=1;j<3;j++){
				if(a[i][j]>=a[i][max1]) max1=j;
				if(a[i][j]<=a[i][min1]) min1=j;
			}
			for(int j=0;j<3;j++){
				if(j!=max1&&j!=min1) mid1=j;
			}
//			cout<<max1<<"   ";
			a[i][3]=max1;
//			cout<<i<<"   ";
			a[i][4]=a[i][max1]-a[i][mid1];
			a[i][5]=mid1;
//			cout<<a[i][4]<<"######";
			
//			for(int k=0;k<n;k++){
//				cout<<"(";
//				for(int p=0;p<5;p++){
//					cout<<a[k][p]<<" ";
//				}
//				cout<<"), ";
//			}
//			cout<<endl;
		}
		
		for(int i=0;i<n;i++){
			o=i;
			for(int j=i+1;j<n;j++){
				if(a[o][a[o][3]]<a[j][a[j][3]]) o=j;
			}
			if(q[a[o][3]][100000]+1<(int)(n/2)){
				ans+=a[o][a[o][3]];
				q[a[o][3]][q[a[o][3]][100000]]=o;
				q[a[o][3]][100000]++;
			}
			else{
				ans+=a[o][a[o][3]];
				q[a[o][3]][q[a[o][3]][100000]]=o;
				int k=INT_MAX;
				for(int k1=0;k1<=q[a[o][3]][100000];k1++){
					k=min(k,a[q[a[o][3]][k1]][4]);
//					cout<<a[q[a[o][3]][k1]][4];
				}
				ans-=a[q[a[o][3]][k]][4];
				q[a[q[a[o][3]][k]][5]][100000]++;
				q[a[o][3]][k]-=q[a[o][3]][k];
			}
			
			swap(a[o],a[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
