#include<bits/stdc++.h>
using namespace std;
int n,k,a[500100];
long long cnt;
bool ud[500100];
void fdxr(int lt,int rt){
	int ls[500100];
	for(int e=lt;e<=rt;e++) ls[e]=a[e];
	for(int p=2;p<=rt-lt+1;p++){
		for(int j=lt;j<=rt-p+1;j++){
			ls[j]^=a[j+p-1];
			if(ls[j]==k){
				if(j+p>rt-2) cnt++;
				else{
					cnt++;
					fdxr(lt,j-1);
					fdxr(j+p,rt);	
				}
				return;
			}
		}	
    }
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ud[i]=1;
			cnt++;
		}
	}
	int bf=1;
	ud[n+1]=1;
	int nw;
	for(int i=1;i<=n+1;i++){
		if(ud[i]==1){
			nw=i-1;
			fdxr(bf,nw);
			bf=i+1;	
		}		
	}
	cout<<cnt<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
