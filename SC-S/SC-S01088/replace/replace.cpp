#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
struct Pair{
	string a,b;
}a[200010];
int n,q;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i].a>>a[i].b;
	for(int _=1;_<=q;_++){
		Pair in,dif;
		cin>>in.a>>in.b;
		int la=in.a.size()-1,lb=in.b.size()-1;
		int l=0,r=0;
		while(l+r<min(la,lb)-1&&in.a[l]==in.b[l])l++;
		while(l+r<min(la,lb)-1&&in.a[la-r]==in.b[lb-r])r++;
		for(int i=l;i<=la-r;i++)dif.a.push_back(in.a[i]);
		for(int i=l;i<=lb-r;i++)dif.b.push_back(in.b[i]);
//		cout<<dif.a<<" "<<dif.b<<endl;
		
		int cnt=0;
		for(int i=1;i<=n;i++){
			int kfa=0,kfb=0;
			for(int j=0;j<=int(a[i].a.size()-dif.a.size());j++){
				int kf=1;
				for(int k=0;k<(int)dif.a.size();k++)
					if(a[i].a[j+k]!=dif.a[k]){
						kf=0;
						break;
					}
				if(kf){
					kfa=1;
					break;
				}
			}
			if(!kfa)continue;
			for(int j=0;j<=int(a[i].b.size()-dif.b.size());j++){
				int kf=1;
				for(int k=0;k<(int)dif.b.size();k++)
					if(a[i].b[j+k]!=dif.b[k]){
						kf=0;
						break;
					}
				if(kf){
					kfb=1;
					break;
				}
			}
			if(kfb)cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
