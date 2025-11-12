#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=5e5+10;
int a[N];
bool b[N];
int main(){
	IOS
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int cnt=0;
	for(int i=1;i<=n;i++){//区间长度 i 2 
		for(int j=1;j<=n;j++){//区间从 j 开始 1 
			if(i+j-1<=n){//区间都在合法范围 
				int sum=0;//异或和 
				bool flag=1;//重复使用标志器 
				int t=i+j-1;
				for(int k=j;k<=i+j-1;k++){//区间遍历 
					if(b[k]){//b[k]为true -> 使用过 
						flag=0;
						t=k;
						break;
					}
					sum^=a[k];
					b[k]=true;
				}
				if(sum==k&&flag){
					cnt++;
				}else{
					if(!flag){
						for(int k=j;k<=t-1;k++)
						b[k]=false;
					}else{
						for(int k=j;k<=t;k++)
						b[k]=false;
					}
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}

