#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005],c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int cnt1=0,cnt2=0,cnt3=0;
		long long sum=0;
		int x[100005],y[100005],z[100005];
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]) cnt1++,x[cnt1]=i,sum+=a[i];
			else if(b[i]>=a[i]&&b[i]>=c[i]) cnt2++,y[cnt2]=i,sum+=b[i];
			else cnt3++,z[cnt3]=i,sum+=c[i];
		}
		int flag1=0,flag2=0,flag3=0;
		if(cnt1*2>n) flag1=1;
		else if(cnt2*2>n) flag2=1;
		else if(cnt3*2>n) flag3=1;
		if(flag1||flag2||flag3){
			priority_queue<int,vector<int>,greater<int>> q;
			if(flag1){
				for(int i=1;i<=cnt1;i++){
					q.push(a[x[i]]-max(b[x[i]],c[x[i]]));
				}
				for(int i=1;i<=cnt1-n/2;i++){
					sum-=q.top();
					q.pop();
				}
			}
			if(flag2){
				for(int i=1;i<=cnt2;i++){
					q.push(b[y[i]]-max(a[y[i]],c[y[i]]));
				}
				for(int i=1;i<=cnt2-n/2;i++){
					sum-=q.top();
					q.pop();
				}
			}
			if(flag3){
				for(int i=1;i<=cnt3;i++){
					q.push(c[z[i]]-max(a[z[i]],b[z[i]]));
				}
				for(int i=1;i<=cnt3-n/2;i++){
					sum-=q.top();
					q.pop();
				}
			}
			cout<<sum<<endl;
		}
		else cout<<sum<<endl;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}