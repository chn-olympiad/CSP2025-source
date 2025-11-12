#include<bits/stdc++.h>
using namespace std;
const int N=500005;
bool b[N][25];
long long F[N];
int sl[N];
int n,ans=0;
bool k[25];
bool bj[N];
int res;
void find(int l,int r){
	for(int i=l;i<=r;i++){
		if(bj[i]==1){
			find(l,i-1);
			find(i+1,r);
			return ;
		}
	}
	
	for(int f=0;f<=r-l;f++){
		for(int i=l;i<=r;i++){
			int j=i+f;
			if(j>r) break;
			for(int s=0;s<=21;s++){
				int v=0;
				for(int m=i;m<=j;m++){
					if(b[m][s]==1)
						v++;
				}
				if(v%2!=k[s]) break;
				if(s==21){
					//cout<<i<<" "<<j<<endl;
					ans++;
					for(int m=i;m<=j;m++){
						bj[m]=1;
					}
					find(l,i-1);
					find(j+1,r);
					return ;
				}
			}
		}
			
	}
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	long long sss;
	cin>>sss;
	res=-1;
	while(sss!=0){
		res++;
		k[res]=sss%2;
		sss=sss/2;
	}
	for(int i=1;i<=n;i++){
		cin>>sss;
		F[i]=sss;
		sl[i]=-1;
		while(sss!=0){
			sl[i]++;
			b[i][sl[i]]=sss%2;
			sss=sss/2;
		}
	}
	find(1,n);
	cout<<ans;
	return 0;
}