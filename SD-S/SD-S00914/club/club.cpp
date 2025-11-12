#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int T,n,aa[100010];
struct node{
	int v,c,s,pp; bool is_add=0;
}arr[300010];
bool cmp(node x,node y){
	return x.c<y.c;
}
bool cmp1(int ff,int kk){
	return ff>kk;
}
bool check(int xx){
	for(int i=1;i<=3*n;i++){
		if(arr[i].pp==xx){
			if(arr[i].is_add==1){
				return 0;
			}
		}
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(); cout.tie();
	freopen("club.in","r",stdin); freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int sum=0;
		int poi=0;
		memset(arr,0,sizeof arr);
		bool is_A=1;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			aa[i]=x;
			if(y!=0||z!=0)
				is_A=0;
			int temp[3]; temp[0]=x;temp[1]=y;temp[2]=z;
			sort(temp,temp+3);
			int ch;
			if(temp[2]==x){
				ch=max(y,z)-x;
			}else ch=temp[2]-x;
			arr[i].c=ch;
			arr[i].v=x;
			arr[i].s=0;
			arr[i].pp=i;
			
			if(temp[2]==y){
				ch=max(x,z)-y;
			}else ch=temp[2]-y;
			arr[i+n].c=ch;
			arr[i+n].v=y;
			arr[i+n].s=1;
			arr[i+n].pp=i;
			
			if(temp[2]==z){
				ch=max(x,y)-z;
			}else ch=temp[2]-z;
			arr[i+2*n].c=ch;
			arr[i+2*n].v=z;
			arr[i+2*n].s=2;
			arr[i+2*n].pp=i;
		}
		if(is_A){
			sort(aa+1,aa+1+n,cmp1);
			for(int i=1;i<=n/2;i++){
				sum+=aa[i];
			}
			cout<<sum<<'\n';
			continue;
		}
		sort(arr+1,arr+1+3*n,cmp);
		int cnt0=0,cnt1=0,cnt2=0;
		for(int i=1;i<=3*n;i++){
//			cerr<<arr[i].c<<' '<<arr[i].v<<' '<<arr[i].s<<'\n';
			if(arr[i].s==0&&cnt0<n/2){
				if(check(arr[i].pp)){
					sum+=arr[i].v;
					cnt0++;
					arr[i].is_add=1;
				}
			}
			if(arr[i].s==1&&cnt1<n/2){
				if(check(arr[i].pp)){
					sum+=arr[i].v;
					cnt1++;
					arr[i].is_add=1;
				}
			}
			if(arr[i].s==2&&cnt2<n/2){
				if(check(arr[i].pp)){
					sum+=arr[i].v;
					cnt2++;
					arr[i].is_add=1;
				}
			}
//			cerr<<sum<<'\n';
		}
		
		
		cout<<sum<<'\n';
	}
	return 0;
}

