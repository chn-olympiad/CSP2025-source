#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],b[N];
int n,key,cnt;
map<int,int>m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>key;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			int sum=a[i-j+1];
			for(int k=i-j+2;k<=i;k++)sum=sum^a[k];
			if(sum==key){
				if(m[i-j+1]==0)m[i-j+1]=1e9;
				m[i-j+1]=min(m[i-j+1],i);
			}
		}
	}
	int odd=0,pre=0,ans=m.size();
	for(int i=1;i<=n;i++){
		if(m[i]!=0){
			if(pre==m[i]||(pre<=m[i]&&odd>=i)||(pre>=m[i]&&odd<=i)){
				ans--;
			}
			else odd=i,pre=m[i];
		}
	}
	cout<<ans;
	return 0;
}//20-25pts(?)
