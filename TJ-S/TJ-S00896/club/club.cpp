#include <bits/stdc++.h>
using namespace std;
//int a[100005],b[100005],c[100005];
int dp[5][100005];
struct Node{
	int a,b,c;
}d[100005];
int cmp(Node x,Node y){
	return max(x.a,max(x.b,x.c))>=max(y.a,max(y.b,y.c));
}
//int cmpb(Node x,Node y){
//	return x.b>=y.b;
//}
//int cmpc(Node x,Node y){
//	return x.c>=y.c;
//}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
//	while(t--){
//		int n;
//		cin>>n;
//		for(int i= 1;i<=n;i++){
//			cin>>a[i]>>b[i]>>c[i];
//		}
//		sort(a+1,a+n+1,cmp);
//		int sum = 0;
//		for(int i = 1;i<=n/2;i++){
//			sum+= a[i];
//		}
//		cout<<sum<<endl;
	while(t--){
		int n;
		cin>>n;
		for(int i = 1;i<=n;i++){
			cin>>d[i].a>>d[i].b>>d[i].c;
		}
		int sa = 0,sb = 0;
		sort(d+1,d+n+1,cmp);
		int sum = 0;
		for(int i = 1;i<=n;i++){
			if(max(d[i].a,d[i].b) == d[i].a && sa<n/2){
				sa++;
				sum += d[i].a;
			}
			if(max(d[i].a,d[i].b) == d[i].a && sa>=n/2){
				sb++;
				sum += d[i].b;
			}
			if(max(d[i].a,d[i].b) == d[i].b && sb<n/2){
				sb++;
				sum += d[i].b;
			}
			if(max(d[i].a,d[i].b) == d[i].b && sb>=n/2){
				sa++;
				sum += d[i].a;
			}
		}
		
		
		cout<<sum<<endl;
		
		
		
		
		
		
		
		
		
		
	}	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		return 0;
		
}
	
	
	
	
	
	
	
	
	
	
	
	
	

 
