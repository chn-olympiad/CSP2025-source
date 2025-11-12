#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10,mod=1e9+9,base=131;
int n,q,bs[N],ans=0;
long long len[N],s1[N],s2[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	
	bs[0]=1;
	for(int i=1;i<=n;i++)
		bs[i]=bs[i-1]*base%mod;
	
	for(int i=1;i<=n;i++){
		string cs1,cs2;
		long long x1=0,x2=0; 
		cin>>cs1>>cs2;
		len[i]=cs1.size();
		for(int j=0;j<len[i];j++){
			x1=(x1*base+cs1[j])%mod;
			x2=(x2*base+cs2[j])%mod;
		}
		s1[i]=x1;
		s2[i]=x2;
	}
		
	for(int i=1;i<=q;i++){
		ans=0;
		string ct1,ct2;
		cin>>ct1>>ct2;
		int sz=ct1.size();
		ct1=' '+ct1;
		ct2=' '+ct2;
		
		vector<long long> t1(sz+1),t2(sz+1); 
		for(int j=1;j<=sz;j++){
			t1[j]=(t1[j-1]*base+ct1[j])%mod;
			t2[j]=(t2[j-1]*base+ct2[j])%mod;
		}
		for(int j=1;j<=sz;j++){
			for(int k=1;k<=n;k++){
				if(j+len[k]-1>sz)continue;
//				cout<<j<<' '<<k<<' '<<(t1[j+len[k]-1]-t1[j-1]*bs[len[k]]%mod+mod)%mod<<' '<<(t2[j+len[k]-1]-t2[j-1]*bs[len[k]]%mod+mod)%mod<<'\n';
//				cout<<n-(j+len[k]-1)+1<<'\n';
//				cout<<s1[k]<<' '<<s2[k]<<'\n';
				
				if((t1[j+len[k]-1]-t1[j-1]*bs[len[k]]%mod+mod)%mod==s1[k]){
					
					if((t2[j+len[k]-1]-t2[j-1]*bs[len[k]]%mod+mod)%mod==s2[k]){
//						cout<<"???-----------------"<<j<<' '<<j+len[k]-1<<'\n';
//						cout<<"!!!"<<s1[k]*bs[sz-(j+len[k]-1)]<<' '<<s2[k]*bs[sz-(j+len[k]-1)]<<'\n';
//						cout<<t1[sz]<<' '<<t2[sz]<<" "<<sz-(j+len[k]-1)<<'\n';
						if((t1[sz]-s1[k]*bs[sz-(j+len[k]-1)]%mod+mod)%mod==(t2[sz]-s2[k]*bs[sz-(j+len[k]-1)]%mod+mod)%mod){
//							cout<<"???"<<k<<'\n';
							ans++;
						}
							
					}
						
				}
			}
		}
		cout<<ans<<'\n';
	} 
	
	return 0;
} 