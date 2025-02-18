#include <bits/stdc++.h>
#define ll long long

#define inff 1e16+123
using namespace std;

const ll mx = 1e7+11;
vector<pair<ll, ll>> adj[mx];
ll dist[mx];

void dijkstra(ll s, ll n){
    for (ll i = 1; i <= n; i++) dist[i] = inff;
    dist[s] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, s});

    while(!pq.empty()){
        ll u = pq.top().second;
        ll curD = pq.top().first;
        pq.pop();
        if(dist[u] < curD) continue;

        for(auto p : adj[u]){
            ll v = p.first;
            ll w = p.second;
            if (curD + w < dist[v]){
                dist[v] = curD + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }\

    dijkstra(1, n);
    for(int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }
    cout<<"\n";

    return 0;
}
