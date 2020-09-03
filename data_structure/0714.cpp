#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct e {
    char start, end;
    int weight;
    e() {}
    e(char _start, char _end, int _weight): start(_start), end(_end), weight(_weight) {}
    bool operator < (const e & other) const {
        return weight > other.weight;
    }
};
struct v {
    bool visited;
    char name;
    vector<e> out;
} letters[27];
int prim() {
    for (int i = 0; i < 26; i++) {
        letters[i].name = i + 'A';
        letters[i].visited = false;
    }
    priority_queue<e> pq;
    for (int i = 0; i < letters[0].out.size(); i++) {
        pq.push(letters[0].out[i]);
    }
    letters[0].visited = true;
    int val = 0;
    while (!pq.empty()) {
        e cur = pq.top();
        pq.pop();
        if (letters[cur.end - 'A'].visited) continue;
        letters[cur.end - 'A'].visited = true;
        //cout << cur.end << " " << cur.weight << endl;
        val += cur.weight;
        for (int i = 0; i < letters[cur.end - 'A'].out.size(); i++) {
            pq.push(letters[cur.end - 'A'].out[i]);
        }
    }
    return val;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        char start, end;
        int weight;
        int num;
        cin >> start >> num;
        for (int j = 0; j < num; j++) {
            cin >> end >> weight;
            letters[start - 'A'].out.push_back(e(start, end, weight));
            letters[end - 'A'].out.push_back(e(end, start, weight));
        }
    }
    cout << prim() << endl;
    return 0;
}