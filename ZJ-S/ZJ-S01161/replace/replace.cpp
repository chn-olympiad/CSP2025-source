#include<bits/stdc++.h>
using namespace std;
int n,q,l,r,cl[10010],cr[10010];
string a[10010],b[10010],quesx[10010],quesy[10010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for(int i=1;i<=q;i++) cin>>quesx[i]>>quesy[i];
	for(int i=1;i<=q;i++){
		int ans=0;
		for(int k=1;k<=n;k++){
			for(int idx1=0;idx1<quesx[i].size()-a[k].size();idx1++){
				int flag=0;
				for(int idx2=0;idx2<a[k].size();idx2++){
					if(quesx[i][idx1+idx2]!=a[k][idx2]||quesy[i][idx1+idx2]!=b[k][idx2]){
						flag=1;
						break;
					}
				}
				if(flag==0){
					for(int kkk=0;kkk<idx1;kkk++){
						if(quesx[i][kkk]!=quesy[i][kkk]){
							flag=1;
							break;
						}
					}
					if(flag==1) continue;
					for(int kkk=idx1+a[k].size()-1;kkk<quesx[i].size();kkk++){
						if(quesx[i][kkk]!=quesy[i][kkk]){
							flag=1;
							break;
						}
					}
					if(flag==1) continue;
					else ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	//忘记背AC自动机的还有救吗 
	return 0;
}
