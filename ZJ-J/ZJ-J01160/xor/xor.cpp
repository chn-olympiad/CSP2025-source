#include <bits/stdc++.h>
using  namespace std;
vector<int> a;
struct Node{
	int x,y;
};
vector<Node> v;
int n,k;
bool check(int l,int r){
    int ans=a[l];
    if(l>=a.size() || r>=a.size()){
    	return 0;
	}
    for(int i=l;i<r;i++){
        ans=ans^a[i+1];
    }
    if(ans==k){
        return 1;
    }else{
        return 0;
    }
}
bool isCross(Node a,Node b){
    if(a.x<=b.x&&b.x<=a.y||a.x<=b.y&&b.y<=a.y || b.x<=a.x&&a.x<=b.y||b.x<=a.y&&a.y<=b.y){
        return 1;
    }
    return 0;
}
int anyCross(Node a,vector<Node> v){
	for(auto i=0;i<v.size();i++){
        if(isCross(a,v[i])){
            return i;
        }
    }
    return -1;
}
int main(){
    //cerr<<"deb\n";
    // Only 40 scores, aminoas
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    int ans=0;
    for(int l=0;l<=n;l++){
        for(int i=0;i<n-l+1;i++){
            int crs = anyCross({i,i+l},v);
            //cerr<<"Crs"<<crs<<endl;
            if(check(i,i+l) && crs<=-1){
                //cerr<<"Deb"<<i<<":"<<i+l<<endl;
                v.push_back({i,i+l});
                i+=l;
                ans++;
            }
        }
    }
    cout<<ans;
}
