#include <bits/stdc++.h>
    #define INF 1000000000
    #define fast ios_base::sync_with_stdio(false)
    #define pb push_back
    #define nl cout<<endl
    #define mp make_pair
    #define rep(i,n) for(int i=0;i<n;i++)
    #define rep2(i,n) for(int i=1;i<=n;i++)
    #define vprint(x)  copy(x.begin(), x.end(), ostream_iterator<int>(cout, " "))
    #define vrprint(x)  copy(x.rbegin(), x.rend(), ostream_iterator<int>(cout, " "))
    using namespace std;
    typedef long long ll;
    typedef vector <int> vi;
    typedef pair<int,int> ii;
    typedef pair<int,ii> iii;
    int main()
    {
    fast;
    //freopen ("out.h","w",stdout);
int k,n,m;
cin>>k>>n>>m;
int z=0;
int tot=0;
while(true)
{
//cout<<z<<endl;
 if(z<=m && z+n<=(k-1)  )
        tot++;
    else break;
        z++;
}
cout<<tot<<endl;
            return 0;
    }
