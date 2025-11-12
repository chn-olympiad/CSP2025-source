#include<bits/stdc++.h> 
using namespace std;
const int N=1e5+5;
struct club{
	int ans[4];
	int sum;
}a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		int a1,a2,a3;
		for(int i=1;i<=n;i++){
			cin>>a[i].ans[1]>>a[i].ans[2]>>a[i].ans[3];
			sort(a[i].ans+1,a[i].ans+n+1,cmp);
		}
		int maxx=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int q1=1;q1<=n;q1++){
						for(int q2=1;q2<=n;q2++){
							for(int q3=1;q3<=n;q3++){
								if(a[i].ans[q1]+a[j].ans[q2]+a[k].ans[q3]>maxx){
									maxx=a[i].ans[q1]+a[j].ans[q2]+a[k].ans[q3];
									cout<<a[i].ans[q1]<<' '<<a[j].ans[q2]<<' '<<a[k].ans[q3]<<endl; 
								} 
							} 
						} 
					}
				}
			}
		}
		cout<<maxx<<endl;
	}
	return 0;
}

