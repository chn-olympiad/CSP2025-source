#include<bits/stdc++.h>
using namespace std;
struct node{
	string s,ss;
	int num;
}a[10010];
int n,k;
string q,qq;
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin >> n >> k;
	for(int i =1;i<=n;i++){
		string x,xx;
		cin >> x >> xx;
		a[i].s = x;
		a[i].ss = xx;
		a[i].num = x.size();
	}
	while(k--){
		cin >> q >> qq;
		int ans =0;
		if(q.size()!=qq.size()){
			cout << 0 << endl;
			continue;
		}
		for(int i = 0;i<q.size();i++){
			for(int j=q.size();j>i+1;j--){
				string x = "";
				for(int z=i;z<j;z++) x=x+q[z];
				int l = x.size();	
				for(int z=1;z<=n;z++){
					if(a[z].num!=l) continue;
					if(a[z].s==x){
						string xx="",yy="",zz="";
						for(int t=0;t<i;t++) xx=xx+q[t];
						for(int t=j+1;t<=q.size();t++) yy=yy+q[t]; 
						zz = xx + a[z].ss + yy;
						cout << xx <<" "<< a[z]<<endl;
						if(qq==zz){
							ans++;
							
						}

					} 
					
				}

			}
		}
		cout <<ans << endl;
	}
	return 0;
}

