/*
Rui Alexandre Tapadinhas - 2018283200
David Marcelino Mendes Palaio - 2018283864

Mooshak 
sub 
*/

/*
g++ -std=c++17 -Wall -Wextra -O2 Project3.cpp -lm
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>


using namespace std;

int num_operations, op_time, num_dependencies, dep, option, num_operations_done = 0;
vector<int> op_times;
map<int,vector<int>> dependencies;
vector<bool> visited;

bool bfs(int v);
void print_map(map<int, vector<int>> &map1);
void project3();


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (cin >> num_operations) {
        op_times.resize(num_operations+1);
        for (int op = 1; op < num_operations+1; op++) {
            cin >> op_time;
            op_times[op] = op_time;
            cin >> num_dependencies;
            //cout << op << ":";
            dependencies[op] = vector<int>();
            for (int d = 0; d < num_dependencies; d++) {
                cin >> dep;
                dependencies[op].push_back(dep);
                //cout << dep << " ";
            }
            //cout << endl;
        }
        cin >> option;

        //print 
        print_map(dependencies);

        project3();


        dependencies.clear();
        op_times.clear();
    }
}


void print_map(map<int, vector<int>> &map1) {
    for (int dep = 1; dep < (int)map1.size()+1; dep++) {
        cout << dep << ":";
        for (auto d: map1[dep]) {
            cout << d << " ";
        }
        cout << endl;
    }
}

/*bool trains_stations(int v) {
    queue<int> Q;
    type[v] = 1;
    Q.push(v);
    while (Q.empty() == false) {
        int node1 = Q.front(); 
        Q.pop();

        for (int node2: adj_graph[node1]) {
            if (type[node2] == -1) {
                type[node2] = 1 - type[node1];
                Q.push(node2);
            }
            else if (type[node2] == type[node1]) {
                return false;
            }
        }
    }
    return true;
}*/

bool bfs(int v) {
    cout << "entrei" << endl;
    queue<int> Q;
    visited[v] = true;
    Q.push(v);
    if (Q.empty() == true) {
        cout << "empty" << endl;
        cout << Q.empty() << endl;
    }
    while (Q.empty() == false) {
        cout << "na queue" << endl;
        int node1 = Q.front(); 
        Q.pop();

        for (int depend: dependencies[node1]) {
            cout << depend << endl;
            if (visited[depend] == false) {
                visited[depend] = true;
                Q.push(depend);
                cout << depend << endl;
            }
            /*else if (type[node2] == type[node1]) {
                return false;
            }*/
        }
    }
    return true;
}


void project3() {
    int least_dep = 0;
    bool check_init = false;
    while (num_operations_done != num_operations) {
        for (auto p_node: dependencies) {
            cout << "try init" << endl;
            if ((int)p_node.second.size() == least_dep && check_init == false) {
                cout << "init" << endl;
                check_init = true;
                bfs(p_node.first);
            }
        }
    }
}