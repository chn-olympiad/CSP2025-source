#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,q;
//string a[N],b[N];
unordered_map<string,string>mp;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		mp[a]=b;
	}
	for(int i=1;i<=q;i++){
		string x,y;
		cin>>x>>y;
		int lx=x.size(),ly=y.size(),s=0;
		if(lx!=ly){
			cout<<"0\n";
			continue;
		}
		for(int j=0;j<lx;j++){
			string px,py;
			bool f=0;
			for(int k=j;k<lx;k++){
				px+=x[k];
				py+=y[k];
				if(mp.count(px)&&mp[px]==py){
					if(!f) f=1;
					else{
						f=0;
						break;
					}
				}
//				cout<<px<<" "<<py<<"\n";
			}
			if(f) s++;
		} 
		cout<<s<<'\n';
	}
	return 0;
}
