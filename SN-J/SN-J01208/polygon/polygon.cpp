#include<bits/stdc++.h>
using namespace std;
const int N=5005;
long long a,b,c,d,e,f,g=0,h,ans;
bool imsb=0;
int aa[N];
struct node{
	int aaa[N];
};
void dfs(int x,int y,int z,int sum,int maxn,node xx){
	if(x>a){
		//cout<<x<<" "<<y<<" "<<sum<<" "<<maxn<<endl;
		
		if(sum-g>2*maxn&&z!=0){
			if(imsb)ans++;
			if(sum==0){
				imsb=1;
				g+=aa[1];
			}
//			for(int i=1;i<=a;i++){
//				cout<<"-"<<xx.aaa[i]<<" ";
//			}
//			cout<<"="<<maxn<<"="<<sum<<endl;
			
				
		}
		return;
	}
	xx.aaa[x]=aa[x];
	dfs(x+1,y,z+1,sum+aa[x],max(maxn,aa[x]),xx);
	xx.aaa[x]=0;
	dfs(x+1,y,z,sum,maxn,xx);
}
node xx;
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>aa[i];
	}
//			maxn=INT_MIN;
//			sum=0;
//			for(int k=i;k<=j;k++){
//				sum+=aa[k];
//				maxn=max(maxn,aa[k]);
//			}
//			if(sum>maxn*2){
//				ans++;
//			}
	dfs(1,a,1,0,-1145114,xx);
	dfs(1,a,1,aa[1],aa[1],xx);
	
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
