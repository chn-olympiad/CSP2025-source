#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][4],n;
int a1[N];
long long mx=-1;
void init(){
	memset(a,0,sizeof(a));
	mx=-1;
	return;
}
long long dfs(int id,long long bu,int a1,int a2,int a3){
	if(id==n+1){
		//cout<<bu<<endl;
		if(bu>mx){
			mx=bu;
		}
		return bu;
	}
	if(a1<n/2){
		dfs(id+1,bu+a[id][1],a1+1,a2,a3);
	}if(a2<n/2){
		dfs(id+1,bu+a[id][2],a1,a2+1,a3);
	}if(a3<n/2){
		dfs(id+1,bu+a[id][3],a1,a2,a3+1);
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T){
		//cout<<T<<endl;
		init();
		cin>>n;
		bool flag2=true;
		bool flag3=true;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			a1[i]=a[i][1];
			if(a[i][2]!=0){
				flag2=false;
			}if(a[i][3]!=0){
				flag3=false;
			}
		}
		if(flag2 && flag3){
			sort(a1,a1+n+1);
			long long ans=0;
			for(int i=n;i>n/2;i--){
				ans+=a1[i];
			}
			cout<<ans<<endl;
			T--;
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<mx<<endl;
		T--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
 
