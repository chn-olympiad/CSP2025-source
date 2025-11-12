#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node1{
	int a1;
	int x;
};
struct node2{
	int a2;
	int x;
};
struct node3{
	int a3;
	int x;
};
node1 a1[100005];
node2 a2[100005];
node3 a3[100005];
int a11[100005],a22[100005],a33[100005];
bool cmp1(node1 a,node1 b){
	return a.a1>b.a1; 
}
bool cmp2(node2 a,node2 b){
	return a.a2>b.a2; 
}
bool cmp3(node3 a,node3 b){
	return a.a3>b.a3; 
}
int mark[100005],x1,x2,x3,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
 	while(t--){
		cin>>n;
		x1=x2=x3=ans=0;
		for(int i=0;i<=100004;i++){
			a1[i].a1=a2[i].a2=a3[i].a3=a1[i].x=a2[i].x=a3[i].x=mark[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a1[i].a1>>a2[i].a2>>a3[i].a3;
			a1[i].x=a2[i].x=a3[i].x=i;
			a11[i]=a1[i].a1;
			a22[i]=a2[i].a2;
			a33[i]=a3[i].a3;
		} 		
		sort(a1+1,a1+1+n,cmp1);
		sort(a2+1,a2+1+n,cmp2);
		sort(a3+1,a3+1+n,cmp3);
		for(int i=1;i<=n;i++){
			cout<<a1[i].a1<<" "<<"x:"<<a1[i].x<<" ";
		}
		cout<<endl;
		for(int i=1;i<=n;i++){
			cout<<a2[i].a2<<" "<<"x:"<<a2[i].x<<" ";
		}
		cout<<endl;
		for(int i=1;i<=n;i++){
			cout<<a3[i].a3<<" "<<"x:"<<a3[i].x<<" ";
		}
		cout<<endl;
		for(int i=1;i<=n;i++){
			if(x1>n/2){
				break;
			}
			if(mark[i]==0 && a2[i].a2>a1[i].a1){
				continue;
			}
			x1++;
			ans=ans+a1[i].a1;
			mark[i]=1;
		}
		for(int i=1;i<=n;i++){
			if(x2>n/2){
				break;
			}
			if(mark[i]==1 || a33[a2[i].x]>a2[i].a2){
				continue;
			}
			x2++;
			ans=ans+a2[i].a2;
			mark[i]=1;
		}
		for(int i=1;i<=n;i++){
			if(x3>n/2){
				break;
			}
			if(mark[i]==1){
				continue;
			}
			x3++;
			ans=ans+a3[i].a3;
			mark[i]=1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
