#include<bits/stdc++.h>
using namespace std;
namespace solve{
	inline int read(){
		int x=0,f=1;char ch=getchar();
		while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
		while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
		return x*f;
	}
	int a[100005][4];
	priority_queue<int>pq1,pq2,pq3;
	inline void solveT(){
		int n=read();
		for(int i=1;i<=n;i++){
			a[i][1]=read();
			a[i][2]=read();
			a[i][3]=read();
		}
		while(!pq1.empty())pq1.pop();
		while(!pq2.empty())pq2.pop();
		while(!pq3.empty())pq3.pop();
		int num1=0,num2=0,num3=0,rlt=0;
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				num1++;rlt+=a[i][1];
				if(a[i][1]-a[i][2]<a[i][1]-a[i][3])
					pq1.push(-a[i][1]+a[i][2]);
				else pq1.push(-a[i][1]+a[i][3]);
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				num2++;rlt+=a[i][2];
				if(a[i][2]-a[i][1]<a[i][2]-a[i][3])
					pq2.push(-a[i][2]+a[i][1]);
				else pq2.push(-a[i][2]+a[i][3]);
			}
			else{
				num3++;rlt+=a[i][3];
				if(a[i][3]-a[i][1]<a[i][3]-a[i][2])
					pq3.push(-a[i][3]+a[i][1]);
				else pq3.push(-a[i][3]+a[i][2]);
			}
			if(num1>n/2)rlt+=pq1.top(),pq1.pop(),num1--; 
			if(num2>n/2)rlt+=pq2.top(),pq2.pop(),num2--;
			if(num3>n/2)rlt+=pq3.top(),pq3.pop(),num3--;
		}
		cout<<rlt<<endl;
	}
	inline signed solve(){
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
		int T=read();
		while(T--)solveT();
		return 0;
	}
}
int main(){return solve::solve();}