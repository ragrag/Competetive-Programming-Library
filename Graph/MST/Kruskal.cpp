#include <bits/stdc++.h>
#define INF 1000000000
#define fast ios_base::sync_with_stdio(false)
#define pb push_back
#define nl cout<<endl
#define rep(i, n)	for(int i=0;i<n;i++)
#define rep2(i,n) for(int i=1;i<=n;i++)
#define vprint(x)  copy(x.begin(), x.end(), ostream_iterator<int>(cout, " "))
#define vrprint(x)  copy(x.rbegin(), x.rend(), ostream_iterator<int>(cout, " "))
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

vector < vector < ii > > adj;


int maxx;			//minimax
vi visited;
bool dfs(int u, int to) {
    if(u==to)
        return true;

	visited[u] = 1;
	bool found = false;
	for (auto v: adj[u]) {
		if (visited[v.first] == 0 && dfs(v.first,to))
    {
                 maxx = max(maxx,v.second);
                 return true;
	}
}
return false;
}


vi pset(200005);
void initSet(int n) {
  pset.assign(n, 0);
  for (int i = 0; i < n; i++) pset[i] = i;
}
int findSet(int i) {
  return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}
bool isSameSet(int i, int j) {
  return findSet(i) == findSet(j);
}
void unionSet(int i, int j) {
  pset[findSet(i)] = findSet(j);
}

int main() {

  int n, e;
  cin >> n >> e;

  adj.assign(n, vector < ii > ());
  vector < pair < int, ii > > EdgeList;
  for (int i = 0; i < e; i++) {
    int from, to, w;
    cin >> from >> to >> w;
    EdgeList.pb(mp(w, ii(from, to)));
    adj[from].pb(mp(to, w));
    adj[to].pb(mp(from, w));
  }

  sort(EdgeList.begin(), EdgeList.end());
  int mst_cost = 0;
  initSet(n);
  for (int i = 0; i < e; i++) {
    pair < int, ii > front = EdgeList[i];
    if (!isSameSet(front.second.first, front.second.second)) {
      mst_cost += front.first;
      unionSet(front.second.first, front.second.second);
    }

  }

  cout << mst_cost << endl;
  
  //Second Best MST
 vector < pair < pair<int,int> , int > > taken;  //Push taken edges from the first MST here
int minmst = INF;
  for (int i = 0; i < taken.size(); i++) {
        initSet(n+1);
        int tempst=0;
        int cnt=0;
        for (int j=0;j<e;j++)
        {
            pair < int, ii > front = EdgeList[j];
            if ( (front.second.first == taken[i].first.first ) && (front.second.second == taken[i].first.second) && front.first == taken[i].second )
            {
                continue;
            }
            else if (!isSameSet(front.second.first, front.second.second)) {
              tempst += front.first;
              unionSet(front.second.first, front.second.second);
              cnt++;
            }
        }
        if(cnt == n-1 )
            minmst = min(minmst,tempst);
  }

  cout<<minmset<<endl;
  
  
  //minimax
  int from,to; 
  cin >>from>>to;
  visited = vi(n+1);
  maxx=0;
  dfs(from,to);
  cout<<maxx;

  return 0;
}