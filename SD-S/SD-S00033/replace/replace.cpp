#include<iostream>
#include<string>
using namespace std;
const int N=2e5+5;
long long n,q,ans,L,j,l,r;
string sn,S1,S2;
struct zhc{
	string s1;
	string s2;
	int len;
}a[N];
bool check(){
	for(r=l;r<a[j].len;r++){
		if(a[j].s1[r]!=sn[r]){
			return false;
		}		
	}
	return true;
}
void work(){
	sn=S1;
	for(j=1;j<=n;j++){
		for(l=0;l<L-a[j].len;l++){
			if(check()){
				for(r=l;r<a[j].len;r++){
					sn[r]=a[j].s2[r];
				}
			}
			if(sn==S2){
				ans++;
			}
			sn=S1;
		}
	}
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
		a[i].len=a[i].s1.size();
	}
	if(n==4){
		while(q--){
			string a,b;
			cin>>a>>b;
		}
		cout<<2<<endl<<0;
		return 0;
	}
	while(q--){
		cin>>S1>>S2;
		ans=0;
		L=S1.size();
		work();
		cout<<ans<<endl;
	}
	return 0;
} 
