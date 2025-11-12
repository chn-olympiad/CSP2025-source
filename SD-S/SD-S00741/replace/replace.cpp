#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
	int x,y,z;
}a[5000010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int l=0,r=s1.size()-1;
		while(l<=r&&s1[l]==s2[l]){
			l++;
		}
		while(r>=0&&s1[r]==s2[r]){
			r--;
		}
		a[i].x=l-1;
		a[i].y=r-l+1;
		a[i].z=s1.size()-r;
		if(s1[l]=='b'){
			a[i].y=-a[i].y;
		}
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int l=0,r=s1.size()-1;
		while(s1[l]==s2[l]){
			l++;
		}
		while(s1[r]==s2[r]){
			r--;
		}
		int ans=0,k=r-l+1;
		if(s1[l]=='b'){
			k=-k;
		}
		for(int i=1;i<=n;i++){
			if(a[i].y==k&&a[i].x<=l-1&&a[i].z<=s1.size()-r){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
