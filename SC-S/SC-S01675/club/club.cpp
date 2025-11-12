#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;
struct pe{
    pair<int,int> v[4];
    int m[4],cnt=1;
}a[MAXN];
int n,t,ans;
struct CLUB{
    int val;
    priority_queue<pair<int,int>> peo;
}club[5];
void use(int id){
	int idc=a[id].m[a[id].cnt],idv=a[id].v[4-a[id].cnt].first;
    if(club[idc].val<n/2){
        club[idc].val++;
        club[idc].peo.push(make_pair(-idv,id));
        ans+=idv;
    }
	else if(club[idc].peo.top().first>-idv){
        ans+=idv+club[idc].peo.top().first;
        pair<int,int> c=club[idc].peo.top();
        a[c.second].cnt++;
        use(c.second);
        club[idc].peo.pop();
        club[idc].peo.push(make_pair(-idv,id));
    }
    else if(club[idc].peo.top().first==-idv){
        pair<int,int> c=club[idc].peo.top();
        if(a[c.second].v[4-a[c.second].cnt].first>=idv){
            a[id].cnt++;
            use(id);
        }
        //else if(a[c.second].v[4-a[id].cnt].first==idv){
            //if()
        //}
        else{
			ans+=idv;
            a[c.second].cnt++;
            use(c.second);
            club[idc].peo.pop();
            club[idc].peo.push(make_pair(-idv,id));
        }
    }
    else{
        a[id].cnt++;
        use(id);
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                scanf("%d",&a[i].v[i].first);
                a[i].v[i].second=i;
            } 
            sort(a[i].v+1,a[i].v+4);
            a[i].m[1]=a[i].v[3].second;
            a[i].m[2]=a[i].v[2].second;
            a[i].m[3]=a[i].v[1].second;
        }
        ans=0;
        for(int i=1;i<4;i++){
            club[i].val=0;
            while(!club[i].peo.empty()){
				club[i].peo.pop();
			}
        }
        for(int i=1;i<=n;i++){
            use(i);
        }
		cout<<ans<<endl;
    }
    return 0;
}