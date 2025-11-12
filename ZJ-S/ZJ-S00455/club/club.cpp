#include<bits/stdc++.h>
using namespace std;
int T,n,a[106666][6],f[106666][6],ma,c,d,edt,fl,i,ans;
priority_queue<pair<pair<int,int>,pair<int,int> >,vector<pair<pair<int,int>,pair<int,int> > >,greater<pair<pair<int,int>,pair<int,int> > > > q1,q2,q3;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
//		scanf("%d",n);
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		while(!q3.empty()) q3.pop();
		for(i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
//			scanf("%d%d%d",a[i][1],a[i][2],a[i][3]);
			ma=max(ma,a[i][1]);
			if(a[i][1]>a[i][2]){
				if(a[i][2]>a[i][3]) f[i][1]=1,f[i][2]=2,f[i][3]=3;
				else{
					if(a[i][1]>a[i][3]) f[i][1]=1,f[i][2]=3,f[i][3]=2;
					else f[i][1]=3,f[i][2]=1,f[i][3]=2;
				}
			}
			else{
				if(a[i][1]>a[i][3]) f[i][1]=2,f[i][2]=1,f[i][3]=3;
				else{
					if(a[i][2]>a[i][3]) f[i][1]=2,f[i][2]=3,f[i][3]=1;
					else f[i][1]=3,f[i][2]=2,f[i][3]=1;
				}
			}
			c=a[i][f[i][1]]-a[i][f[i][2]];
			if(f[i][1]==1) q1.push(make_pair(make_pair(c,a[i][f[i][1]]),make_pair(1,i)));
			if(f[i][1]==2) q2.push(make_pair(make_pair(c,a[i][f[i][1]]),make_pair(1,i)));
			if(f[i][1]==3) q3.push(make_pair(make_pair(c,a[i][f[i][1]]),make_pair(1,i)));
		}
		while(1){
			fl=1;
			for(i=1;i<=3;i++){
				if(i==1){
					if(q1.size()>n/2) fl=0;
				}
				else if(i==2){
					if(q2.size()>n/2) fl=0;
				}
				else if(i==3){
					if(q3.size()>n/2) fl=0;
				}
			}
			if(fl==1) break;
			while(1){
				if(q1.size()<=n/2) break;
				if(q1.top().second.first==3){
					c=INT_MAX;d=q1.top().first.second;i=q1.top().second.second;
					q1.pop();
					q1.push(make_pair(make_pair(c,d),make_pair(3,i)));
				}
				else{
					edt=q1.top().second.first+1;i=q1.top().second.second;c=a[i][f[i][edt-1]]-a[i][f[i][edt]];d=a[i][f[i][edt]];
					q1.pop();
					if(f[i][edt]==2) q2.push(make_pair(make_pair(c,d),make_pair(edt,i)));
					else if(f[i][edt]==3 ) q3.push(make_pair(make_pair(c,d),make_pair(edt,i)));
				}
			}
			while(1){
				if(q2.size()<=n/2) break;
				if(q2.top().second.first==3){
					c=INT_MAX;d=q2.top().first.second;i=q2.top().second.second;
					q2.pop();
					q2.push(make_pair(make_pair(c,d),make_pair(3,i)));
				}
				else{
					edt=q2.top().second.first+1;i=q2.top().second.second;c=a[i][f[i][edt-1]]-a[i][f[i][edt]];d=a[i][f[i][edt]];
					q2.pop();
					if(f[i][edt]==1) q1.push(make_pair(make_pair(c,d),make_pair(edt,i)));
					else if(f[i][edt]==3 ) q3.push(make_pair(make_pair(c,d),make_pair(edt,i)));
				}
			}
			while(1){
				if(q3.size()<=n/2) break;
				if(q3.top().second.first==3){
					c=INT_MAX;d=q1.top().first.second;i=q3.top().second.second;
					q3.pop();
					q3.push(make_pair(make_pair(c,d),make_pair(3,i)));
				}
				else{
					edt=q3.top().second.first+1;i=q3.top().second.second;c=a[i][f[i][edt-1]]-a[i][f[i][edt]];d=a[i][f[i][edt]];
					q3.pop();
					if(f[i][edt]==1) q1.push(make_pair(make_pair(c,d),make_pair(edt,i)));
					else if(f[i][edt]==2 ) q2.push(make_pair(make_pair(c,d),make_pair(edt,i)));
				}
			}
		}
		ans=0;
		while(!q1.empty()) ans+=q1.top().first.second,q1.pop();
		while(!q2.empty()) ans+=q2.top().first.second,q2.pop();
		while(!q3.empty()) ans+=q3.top().first.second,q3.pop();
		cout<<ans<<"\n";
//		printf("%d",&ans);
	}
	return 0;
}

