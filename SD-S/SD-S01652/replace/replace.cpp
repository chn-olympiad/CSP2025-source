#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#define ull unsigned long long
using namespace std;
const int N=1e3+10,L=2e3+10,NN=2e5+10,LL=5e6+10;
int n,q,L1;
int ls1[NN],ls2[NN],lt1,lt2;
int curbs1[NN],curbs2[NN],curbt1,curbt2;
string s1[NN],s2[NN],t1,t2;
ull p[L],hs1[N][L],hs2[N][L],ht1[L],ht2[L];
ull pp[LL],hss1[LL],hss2[LL],htt1[LL],htt2[LL];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	if(q==1){
		pp[0]=1;
		for(int i=1;i<=LL-10;i++){
			pp[i]=pp[i-1]*13331;
		}
		for(int i=1;i<=n;i++){
			cin>>s1[i]>>s2[i];
			ls1[i]=s1[i].size();
			ls2[i]=s2[i].size();
			s1[i]=' '+s1[i];
			s2[i]=' '+s2[i];
		}
		cin>>t1>>t2;
		lt1=t1.size();
		lt2=t2.size();
		t1=' '+t1;
		t2=' '+t2;
		for(int i=1;i<=lt1;i++){
			htt1[i]=htt1[i-1]*13331+(t1[i]-'a'+1);
		}
		for(int i=1;i<=lt2;i++){
			htt2[i]=htt2[i-1]*13331+(t2[i]-'a'+1);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=ls1[i];j++){
				hss1[j]=hss1[j-1]*13331+(s1[i][j]-'a'+1); 
			}
			for(int j=1;j<=ls2[i];j++){
				hss2[j]=hss2[j-1]*13331+(s2[i][j]-'a'+1); 
			}
			bool flag=0;
			for(int j=1;j+ls1[i]-1<=lt1;j++){
				int l=j,r=j+ls1[i]-1;
				if(htt1[r]-htt1[l-1]*pp[r-l+1]==hss1[ls1[i]]){
					
//					cout<<l<<endl;
					
					if(htt1[lt1]-(hss1[ls1[i]]*pp[lt1-r])+(hss2[ls2[i]]*pp[lt2-r])==htt2[lt2]){
						flag=1;
						break;
					}
				}
			}
			if(flag){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	p[0]=1;
	for(int i=1;i<=L-10;i++){
		p[i]=p[i-1]*13331;
	}
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		ls1[i]=s1[i].size();
		ls2[i]=s2[i].size();
		L1+=ls1[i];
		L1+=ls2[i];
		s1[i]=' '+s1[i];
		s2[i]=' '+s2[i];
	}
	if(L1>2000){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=ls1[i];j++){
				if(s1[i][j]=='b'){
					curbs1[i]=j;
					break;
				}
			}
			for(int j=1;j<=ls2[i];j++){
				if(s2[i][j]=='b'){
					curbs2[i]=j;
					break;
				}
			}
		}
		while(q--){
			int ans=0;
			cin>>t1>>t2;
			lt1=t1.size();
			lt2=t2.size();
			if(lt1!=lt2){
				cout<<0;
				continue;
			}
			t1=' '+t1;
			t2=' '+t2;
			for(int i=1;i<=lt1;i++){
				if(t1[i]=='b'){
					curbt1=i;
					break;
				}
			}
			for(int i=1;i<=lt2;i++){
				if(t2[i]=='b'){
					curbt2=i;
					break;
				}
			}
			for(int i=1;i<=n;i++){
				if(curbs1[i]<=curbt1&&ls1[i]-curbs1[i]+1<=lt1-curbt1+1){
					if(curbs2[i]-curbs1[i]==curbt2-curbt1){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=ls1[i];j++){
			hs1[i][j]=hs1[i][j-1]*13331+(s1[i][j]-'a'+1); 
		}
		for(int j=1;j<=ls2[i];j++){
			hs2[i][j]=hs2[i][j-1]*13331+(s2[i][j]-'a'+1); 
		}
	}
	while(q--){
		int ans=0;
		cin>>t1>>t2;
		lt1=t1.size();
		lt2=t2.size();
		t1=' '+t1;
		t2=' '+t2;
		for(int i=1;i<=lt1;i++){
			ht1[i]=ht1[i-1]*13331+(t1[i]-'a'+1);
		}
		for(int i=1;i<=lt2;i++){
			ht2[i]=ht2[i-1]*13331+(t2[i]-'a'+1);
		}
		for(int i=1;i<=n;i++){
			bool flag=0;
			for(int j=1;j+ls1[i]-1<=lt1;j++){
				int l=j,r=j+ls1[i]-1;
				if(ht1[r]-ht1[l-1]*p[r-l+1]==hs1[i][ls1[i]]){
					
//					cout<<l<<endl;
					
					if(ht1[lt1]-(hs1[i][ls1[i]]*p[lt1-r])+(hs2[i][ls2[i]]*p[lt2-r])==ht2[lt2]){
						flag=1;
						break;
					}
				}
			}
			if(flag){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
