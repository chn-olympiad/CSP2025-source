#include<bits/stdc++.h>
using namespace std;
int n,a[1000500],b[1000500],c[1000500];
long long sum = 0;
priority_queue<int,vector<int>,greater<int> > chaa,chab,chac;
int main(){
	int t;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sum = 0;
		while(!chaa.empty()){
			chaa.pop();
		}
		while(!chab.empty()){
			chab.pop();
		}
		while(!chac.empty()){
			chac.pop();
		}
	for(int i = 1;i<=n;i++){
	 	scanf("%d%d%d",&a[i],&b[i],&c[i]);
	 	sum+=max({a[i],b[i],c[i]});
		if(c[i]>b[i]&&c[i]>a[i]){
			chac.push(c[i]-max(a[i],b[i]));
		}	
		if(b[i]>c[i]&&b[i]>a[i]){
			chab.push(b[i]-max(a[i],c[i]));
		}	
		if(a[i]>b[i]&&a[i]>c[i]){
			chaa.push(a[i]-max(c[i],b[i]));
		}	
	}
	while((int)chaa.size()>n/2){
		sum-=chaa.top();
		chaa.pop();
	}
	while((int)chab.size()>n/2){
		sum-=chab.top();
		chab.pop();
	}
	while((int)chac.size()>n/2){
		sum-=chac.top();
		chac.pop();
	}
	cout<<sum<<endl;
	}
	
	return 0;
}

