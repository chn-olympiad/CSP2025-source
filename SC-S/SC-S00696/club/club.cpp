#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int qwe1,qwe2;
}q[N];
int a[N],b[N],c[N],d[N],ans=0,ans1=0;
int a1=0,a2=0,a3=0;
int t;
bool cmp(int A,int B){
	return A>B;
}
bool cmp1(node A,node B){
	return A.qwe1>B.qwe1;
}
bool cmp2(node A,node B){
	return A.qwe2<B.qwe2;
}
void dfs(int n,int nnn){
	if(n==0){
		if(a1<=nnn/2&&a2<=nnn/2&&a3<=nnn/2){
			for(int i=1,j=nnn;i<=nnn;i++,j--){
				if(d[j]==1){
					ans1+=a[i];
				}else if(d[j]==2){
					ans1+=b[i];
				}else if(d[j]==3){
					ans1+=c[i];
				}
			}
		}
		ans=max(ans,ans1);
		ans1=0;
		return;
	}
	for(int i=1;i<=3;i++){
		d[n]=i;
		if(i==1){
			a1++;
			if(a1>nnn/2){
				a1--;
				continue;
				
			}
		}else if(i==2){
			a2++;
			if(a2>nnn/2){
				a2--;
				continue;
			}
		}else{
			a3++;
			if(a3>nnn/2){
				a3--;
				continue;
			}
		}
		dfs(n-1,nnn);
		if(i==1){
			a1--;
		}else if(i==2){
			a2--;
		}else{
			a3--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int T=1;T<=t;T++){
		int n;
		cin>>n;
		bool A=1,B=1;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0){
				A=0;
			}
			if(c[i]!=0){
				B=0;
			}
		}
		if(n<=30){
			dfs(n,n);
			cout<<ans<<"\n";
			ans=0;
		}else if(A){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i];
			}
			cout<<ans<<"\n";
			ans=0;
		}else if(B){
			for(int i=1;i<=n;i++){
				q[i].qwe1=a[i];
			}
			for(int i=1;i<=n;i++){
				q[i].qwe2=b[i];
			}
			sort(q+1,q+1+n,cmp1);
			int shou=1,wei=1;
			for(int i=1;i<n;i++){
				if(q[i].qwe1==q[i+1].qwe1){
					wei=i+1;
				}else{
					wei=i+1;
					sort(q+shou,q+1+wei,cmp2);
					shou=wei;
				}
			}
			for(int i=1;i<=n/2;i++){
				ans+=q[i].qwe1;
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=q[i].qwe2;
			}
			cout<<ans<<"\n";
			ans=0;
		}
	}
	return 0;
}