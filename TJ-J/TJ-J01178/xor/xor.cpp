#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
int a[500005];
int n,k;
int f[500005];//存储的是正式区间
vector<int> df;//存储的是待定区间 
ll ans=0;
int q=0;
int main(){
	memset(f,-1,sizeof(f));
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]==k){
		ans++;
		f[1]==++q;
	}
	else{
		df.push_back(1);
	}
	for(int i=2;i<=n;i++){
		if(a[i]==k){//如果可以单独成区间 
//cout<<1<<":"<<i<<endl;
			ans++;//增加区间数,并且单独作为一个区间 
			f[i]=++q;
		}
		else{//如果不能单独成区间 
			//如果可以加入与这个数相邻的区间 
			bool joined=false;
			if(f[i-1]!=-1){
				if(a[i]^k==k){
					f[i]=f[i-1];//加入这个区间,并且ans不变 
				}
				joined=true;
			}
			else{
				for(int j=0;j<df.size();j++){
					int x=a[i],y=a[df[j]];
					if((x^y)==k&& df[j]!=-1){
						f[df[j]]=++q;
						f[i]=q;
						df[j]=-1;
//cout<<(x ^ y ==k)<<"\n";
						ans++;//如果加入的是待定区间,ans++ 
						joined=true;
					}
				}
			}
			if(!joined){//如果加入不了其他区间 
				df.push_back(i);
				//单独成待定区间 
			}
		}
	}
//	for(int i=0;i<df.size();i++){
//		cout<<df[i]<<" ";
//	}
	cout<<ans;
	return 0;
} 
