#include<bits/stdc++.h>
using namespace std;
int a[100044][3];
int minn(int q,int w){
	if(q<w)return q;
	return w;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int z;
	cin>>z;
	long long ans;
	while(z--){
		int x,c,v,b;
		ans=0;
		cin>>x;
		for(int i=1;i<=x;i++){
			cin>>c>>v>>b;
			a[i][0]=v+b;a[i][1]=c+b;a[i][2]=c+v;
			ans+=c+v+b;
		}
		priority_queue<int> q1,q2,q3;
		int xx=x/2;
		int w1=0,w2=0,w3=0;
		for(int i=1;i<=x;i++){
			if(a[i][0]<=a[i][1]&&a[i][0]<=a[i][2]){
				q1.push(a[i][0]-minn(a[i][1],a[i][2]));
				ans-=a[i][0];
				w1++;
				if(w1>xx){
					ans+=q1.top();
					q1.pop();
				}
			}
			else if(a[i][1]<=a[i][0]&&a[i][1]<=a[i][2]){
				q2.push(a[i][1]-minn(a[i][0],a[i][2]));
				ans-=a[i][1];
				w2++;
				if(w2>xx){
					ans+=q2.top();
					q2.pop();
				}
			}
			else{
				q3.push(a[i][2]-minn(a[i][1],a[i][0]));
				ans-=a[i][2];
				w3++;
				if(w3>xx){
					ans+=q3.top();
					q3.pop();
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
