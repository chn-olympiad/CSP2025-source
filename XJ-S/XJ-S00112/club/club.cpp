#include<bits/stdc++.h>
using namespace std;

const int N=100050;
int n;
int arr[N][3];
long long ans=0;
int k;
int num[3];//三个部门现有人数 

void dfs(int id,long long v){
	ans=max(ans,v);
	if(id==n)
		return;
	for(int a=0;a<3;a++){
		if(num[a]+1<=k){
			num[a]++;
			dfs(id+1,v+arr[id][a]);
			num[a]--;
		}
	}
}

bool cmp(int x,int y){
	return x>y; 
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		ans=0;
		num[0]=0,num[1]=0,num[2]=0;
		k=0;
		cin>>n;
		for(int a=0;a<n;a++)
			for(int b=0;b<3;b++)
				cin>>arr[a][b];
		k=n/2;
		//特判
		bool x=true,y=true,z=true;
		for(int a=0;a<n;a++){
			if(arr[a][0]!=0)
				x=false;
			if(arr[a][1]!=0)
				y=false;
			if(arr[a][2]!=0)
				z=false;
		}
		bool is=false;
		if(y&&z){
			int i[n];
			for(int a=0;a<n;a++)
				i[a]=arr[a][0];
			sort(i,i+n,cmp);
			ans=0;
			for(int a=0;a<k;a++)
				ans+=i[a];
			cout<<ans<<endl; 
			is=true;
		}else if(x&&y){
			int i[n];
			for(int a=0;a<n;a++)
				i[a]=arr[a][2];
			sort(i,i+n,cmp);
			ans=0;
			for(int a=0;a<k;a++)
				ans+=i[a];
			cout<<ans<<endl; 
			is=true;
		}else if(x&&z){
			int i[n];
			for(int a=0;a<n;a++)
				i[a]=arr[a][1];
			sort(i,i+n,cmp);
			ans=0;
			for(int a=0;a<k;a++)
				ans+=i[a];
			cout<<ans<<endl; 
			is=true;
		}
		if(!is){
			dfs(0,0);//暴力深搜 
			cout<<ans<<endl;
		}
		for(int a=0;a<n;a++)
			for(int b=0;b<3;b++)
				arr[a][b]=0;
	}
	return 0;
}
