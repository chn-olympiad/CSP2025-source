#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,myd=0;
        cin>>n;
		vector< vector< pair<int,int> > >a(n,vector< pair<int,int> >(3));
        vector< pair<int,int> >b(n);
        vector< int >club(3);
        for(int i=0;i<n;i++){
        	for(int j=0;j<3;j++){
        		cin>>a[i][j].first;//满意度
        		a[i][j].second=j;//社团编号
			}stable_sort(a[i].begin(),a[i].end());//以满意度排序 小到大
			b[i].first=a[i][2].first;//最大满意度
			b[i].second=a[i][2].second;//最大满意度编号
		}sort(b.begin(),b.end());//以每人最大满意度排序
		for(int i=n-1;i>=0;i--){
			for(int j=2;j>=0;j--){
				if(club[a[i][b[i].second].second]<n/2){
					club[a[i][b[i].second].second]++;
					myd+=a[i][b[i].second].first;
				}
			}
		}cout<<myd<<'\n';
    }
    return 0;
}
