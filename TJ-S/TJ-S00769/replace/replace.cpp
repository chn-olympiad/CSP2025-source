#include<bits/stdc++.h>
using namespace std;
const int N=200010,L=5000010;;
int n,q;
long long ans;
string t1,t2;
struct A{
	string s1,s2;
	int l;
}a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
		a[i].l=a[i].s1.length();
	}
	while(q--){
		ans=0;
		cin>>t1>>t2;
		int l=t1.length();
		for(int i=1;i<=n;i++){
			for(int j=0;j<l-a[i].l+1;j++){
				bool flag=true;
				for(int x=0;x<a[i].l;x++){
					//cout<<x<<' '<<j+x<<endl;
					//cout<<a[i].s1[x]<<' '<<t1[j+x]<<' '
					//<<a[i].s2[x]<<' '<<t2[j+x]<<endl;
					if(a[i].s1[x]!=t1[j+x]||a[i].s2[x]!=t2[j+x]){
						flag=false;
						//cout<<"()";
						break;
					}
				}
				if(flag){
					//cout<<"hahahahahaha\n";
					for(int x=0;x<=j;x++){
						if(a[i].s1[x]!=t1[j+x]||a[i].s2[x]!=t2[j+x]){
							flag=false;
							//cout<<"()";
							break;
						}
					}
					for(int x=j+a[i].l;x<l;x++){
						if(a[i].s1[x]!=t1[j+x]||a[i].s2[x]!=t2[j+x]){
							flag=false;
							//cout<<"()";
							break;
						}
					}
					if(flag)
						ans++;
				}	
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
