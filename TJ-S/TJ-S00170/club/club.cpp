#include<bits/stdc++.h>
using namespace std;
struct node{
int a1,a2,a3;
};
int  main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        int w=n/2;
        vector<node> a(n+1);
        //vector<int> q(n+1)
        vector<int>z(2);
        vector<int>k(2);
        vector<int>qq;
        long long ans1=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
            z[1]=a[i].a1-a[i].a2;
            k[1]=a[i].a1-a[i].a3;
            if(z[1]<k[1]){
                qq.push_back(z[1]);
            }
            else
                qq.push_back(k[1]);

            ans1+=a[i].a1;
        }
       sort(qq.begin(),qq.end());
       for(int i=0;i<n/2;i++){
        ans1-=qq[i];
       }
       cout<<ans1<<endl;
	}
	return 0;
}
