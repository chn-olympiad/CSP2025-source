// 
#include<bits/stdc++.h>
using namespace std;
int T;
int N;
typedef pair<int,int> P;
int a[100010],b[100010],c[100010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		long long sum=0;
		priority_queue<P,vector<P>,greater<P> > que1,que2,que3;
		for(int i=1;i<=N;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=1;i<=N;i++){
			if(a[i]>=max(b[i],c[i])){
				if(que1.size()<N/2){
					que1.push(P(a[i]-max(b[i],c[i]),i));
					sum+=a[i];
				}
				else{
					int t=que1.top().first;
					if(a[i]-max(b[i],c[i])<t){
						if(b[i]>c[i]){
							que2.push(P(b[i]-c[i],i));
							sum+=b[i];
						}
						else {
							que3.push(P(c[i]-b[i],i));
							sum+=c[i];
						}
					}
					else{
						int x=que1.top().second;
						que1.pop();
						sum-=a[x];
						que1.push(P(a[i]-max(b[i],c[i]),i));
						sum+=a[i];
						if(b[x]>c[x]){
							que2.push(P(b[x]-c[x],x));
							sum+=b[x];
						}
						else{
							que2.push(P(c[x]-b[x],x));
							sum+=c[x];
						}
					}
				}
			continue;
		}
		if(b[i]>=max(a[i],c[i])){
				if(que2.size()<N/2){
					que2.push(P(b[i]-max(a[i],c[i]),i));
					sum+=b[i];
				}
				else{
					int t=que2.top().first;
					//cout<<t<<" "<<que2.top().second<<endl;
					if(b[i]-max(a[i],c[i])<t){
						if(a[i]>c[i]){
							que1.push(P(a[i]-c[i],i));
							sum+=a[i];
						}
						else {
							que3.push(P(c[i]-a[i],i));
							sum+=c[i];
						}
					}
					else{
						int x=que2.top().second;
						que2.pop();
						sum-=b[x];
						sum+=b[i];
						que2.push(P(b[i]-max(a[i],c[i]),i));
						if(a[x]>c[x]){
							que1.push(P(a[x]-c[x],x));
							sum+=a[x];
						}
						else{
							que3.push(P(c[x]-a[x],x));
							sum+=c[x];
						}
					}
			}
			continue;
		}
				if(que3.size()<N/2){
					que3.push(P(c[i]-max(a[i],b[i]),i));
					sum+=c[i];
				}
				else{
					int t=que3.top().first;
					if(c[i]-max(a[i],b[i])<t){
						if(a[i]>b[i]){
							que1.push(P(a[i]-b[i],i));
							sum+=a[i];
						}
						else {
							que2.push(P(b[i]-a[i],i));
							sum+=b[i];
						}
					}
					else{
						int x=que3.top().second;
						que3.pop();
						sum-=c[x];
						sum+=c[i];
						que3.push(P(c[i]-max(b[i],a[i]),i));
						if(a[x]>b[x]){
							que1.push(P(a[x]-b[x],x));
							sum+=a[x];
						}
						else{
							que3.push(P(b[x]-a[x],x));
							sum+=b[x];
						}
					}
				}
		}
		printf("%lld\n",sum);
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}

