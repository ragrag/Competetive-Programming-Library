#include <bits/stdc++.h>
#define INF 1000000000
#define fast ios_base::sync_with_stdio(false)
#define pb push_back
#define nl cout<<endl
#define mp make_pair
#define rep(i, n)	for(int i=0;i<n;i++)
#define rep2(i,n) for(int i=1;i<=n;i++)
#define vprint(x)  copy(x.begin(), x.end(), ostream_iterator<int>(cout, " "))
#define vrprint(x)  copy(x.rbegin(), x.rend(), ostream_iterator<int>(cout, " "))
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair<int,int> ii;

vector <int> dist;
vector <vector<ii>> adj;

vi p;

void printPath(int u, int s) {
if (u == s) { cout<<s; return; }
printPath(p[u],s);
cout<<" "<<u; }

void dijkstra(int s) {
    dist[s] = 0;
    priority_queue < ii, vector < ii > , greater < ii > > pq;
    pq.push(ii(0, s));
    while (!pq.empty()) {
      ii front = pq.top(); pq.pop();
      int d = front.first, u = front.second;
      if (d > dist[u])  continue;
      for (auto v: adj[u]) {
        if (dist[u] + v.second < dist[v.first]) {
          dist[v.first] = dist[u] + v.second;
		  p[v.first] = u;
          pq.push(ii(dist[v.first], v.first));
        }
      }
    }
}
int main()
{
int n,e;
cin>>n>>e;

adj = vector < vector<ii> > (n+1);
dist = vi(n+1, INF);
p = vector<int>(n+1);
    for (int i = 0;i < e;i++)
	{
		int from, to,w;
		cin >> from >> to>>w;
	    adj[from].push_back(mp(to,w));
	  //adj[to].push_back(mp(from,w));
	}

int source,dest;
cin>>source>>dest;

dijkstra(source);

cout<<dist[dest]<<endl;
printPath(dest, source);

		return 0;
}
