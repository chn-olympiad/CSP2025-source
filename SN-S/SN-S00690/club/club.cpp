#include<bits/stdc++.h>
using namespace std;
struct sb{
	int num,lov;
};
int a[100000][3],t;
sb b1[100000],b2[100000],b3[100000];
bool swp(sb a,sb b){
	return a.lov>b.lov;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int l1=0,l2=0,l3=0;
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=a[i][1] && a[i][0]>=a[i][2]){
				b1[l1].num=i;
				b1[l1].lov=a[i][0];
				
				l1++;
				
			}
			if(a[i][1]>a[i][0] && a[i][1]>=a[i][2]){
				b2[l2].num=i;
				b2[l2].lov=a[i][1];
				
				l2++;
				
			}
			if(a[i][2]>a[i][0] && a[i][2]>a[i][1]){
				
				b3[l3].num=i;
				b3[l3].lov=a[i][2];
				
				l3++;
				
			}
			
		}
		
		sort(b1,b1+l1,swp);
		sort(b2,b2+l2,swp);
		sort(b3,b3+l3,swp);
		while(l1>n/2 || l2>n/2 || l3>n/2){
			if(l1>n/2){
				l1--;
				if(a[b1[l1].num][1]>=a[b1[l1].num][2]){
					b2[l2].lov=b1[l1].lov;
					b2[l2].num=b1[l1].num;
					l2++;
				}else{
					b3[l3].lov=b1[l1].lov;
					b3[l3].num=b1[l1].num;
					l3++;
				}
			}
			if(l2>n/2){
				l2--;
				if(a[b2[l2].num][0]>=a[b2[l1].num][2]){
					b1[l1].lov=b2[l2].lov;
					b1[l1].num=b2[l2].num;
					l1++;
				}else{
					b3[l3].lov=b2[l2].lov;
					b3[l3].num=b2[l2].num;
					l3++;
				}
			}
			if(l3>n/2){
				l3--;
				if(a[b3[l3].num][0]>=a[b3[l3].num][1]){
					b1[l1].lov=b3[l3].lov;
					b1[l1].num=b3[l3].num;
					l1++;
				}else{
					b2[l2].lov=b3[l3].lov;
					b2[l2].num=b3[l3].num;
					l2++;
				}
			}
		}
		int mx=0;
		for(int i=0;i<l1;i++){
			mx+=a[b1[i].num][0];
		}
		for(int i=0;i<l2;i++){
			mx+=a[b2[i].num][1];
		}
		for(int i=0;i<l3;i++){
			mx+=a[b3[i].num][2];
		}
		cout<<mx;
	}
}
