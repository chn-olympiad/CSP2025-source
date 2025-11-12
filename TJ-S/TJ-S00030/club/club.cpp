#include<bits/stdc++.h>
using namespace std;
int q[4];
int ans=0;
int db[100005],b1[100005],b11[100005];
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t;
cin>>t;
for(int asd=0;asd<t;asd++){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a1,a2,a3;
		cin>>a1>>a2>>a3;
		b1[i]=max(a1,max(a2,a3));
		ans+=b1[i];
		b11[i]=(b1[i]==a1?1:(b1[i]==a2?2:3));
		q[b11[i]]++;
		db[i]=b1[i]==a1?a1-max(a2,a3):(b11[i]==2?a2-max(a1,a3):a3-max(a1,a2));
		if(q[1]>n/2){
			q[0]=1;
		}
		else if(q[2]>n/2){
			q[0]=2;
		}
		else if(q[3]>n/2){
			q[0]=3;
		}
		if(q[0]&&b11[i]==q[0]){
			int we=30000,qw=-1;
			for(int j=0;j<i;j++){
				if(b11[j]==q[0]&&b1[j]!=-1){
					we=min(we,min(db[i],db[j]));
					qw=we==db[i]?i:(we==j?j:qw);
				}
			}
			ans-=we;
			b1[qw]=-1;
		}
			cout<<b1[i]<<b11[i]<<" "<<db[i]<<endl;
	}
	cout<<ans;
	cout<<endl<<endl;
	ans=0;
	q[1]=0;q[2]=0;q[3]=0;q[0]=0;
	for(int i=0;i<n;i++){
		b1[i]=0;b11[i]=0;db[i]=0;
	}
}
return 0;
}

