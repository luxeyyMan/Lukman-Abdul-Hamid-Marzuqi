#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;

int calculateCost(vector<vector<int>> &graph, vector<int> &path) {
    int cost = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        cost += graph[path[i]][path[i + 1]];
    }
    cost += graph[path.back()][path[0]];
    return cost;
}

int main() {
    string nama, nim, kelas, universitas;


    cout << "==============================================\n";
    cout << "           PROGRAM BRUTE FORCE TSP            \n";
    cout << "==============================================\n\n";

    cout << ">> Masukkan Data Mahasiswa\n";
    cout << "Nama        : ";
    getline(cin, nama);
    cout << "NIM         : ";
    getline(cin, nim);
    cout << "Kelas       : ";
    getline(cin, kelas);
    cout << "Universitas : ";
    getline(cin, universitas);

    int n;
    cout << "\n>> Masukkan Jumlah Kota: ";
    cin >> n;
    cin.ignore();

    vector<string> namaKota(n);
    cout << "\n>> Masukkan Nama Kota\n";
    for (int i = 0; i < n; i++) {
        cout << "Nama kota ke-" << i + 1 << ": ";
        getline(cin, namaKota[i]);
    }

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "\n>> Masukkan Matriks Jarak Antar Kota (baris per baris):\n";
    for (int i = 0; i < n; i++) {
        cout << "Baris ke-" << i + 1 << ": ";
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "\n>> Matriks Jarak Antar Kota\n";
    cout << setw(15) << " ";
    for (int j = 0; j < n; j++)
        cout << setw(15) << namaKota[j];
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(15) << namaKota[i];
        for (int j = 0; j < n; j++)
            cout << setw(15) << graph[i][j];
        cout << endl;
    }

    vector<int> path(n);
    for (int i = 0; i < n; i++) path[i] = i;

    int minCost = INT_MAX;
    vector<int> bestPath;
    int count = 1;

    cout << "\n>> Evaluasi Seluruh Rute\n";
    cout << "----------------------------------------------------------------------------\n";
    cout << left << setw(10) << "Rute" << setw(50) << "Urutan" << "Total Jarak" << endl;
    cout << "----------------------------------------------------------------------------\n";

    do {
        int cost = calculateCost(graph, path);
        cout << left << setw(10) << ("Rute " + to_string(count++) + ":");
        for (int i = 0; i < path.size(); i++) {
            cout << namaKota[path[i]];
            if (i != path.size() - 1) cout << " -> ";
        }
        cout << " -> " << namaKota[path[0]];
        cout << setw(10) << "   " << " | " << cost << endl;

        if (cost < minCost) {
            minCost = cost;
            bestPath = path;
        }
    } while (next_permutation(path.begin() + 1, path.end()));

    cout << "\n>> RUTE TERPENDEK\n";
    cout << "Rute Optimal   : ";
    for (int i = 0; i < bestPath.size(); i++) {
        cout << namaKota[bestPath[i]];
        if (i != bestPath.size() - 1) cout << " -> ";
    }
    cout << " -> " << namaKota[bestPath[0]] << endl;
    cout << "Total Jarak    : " << minCost << "\n";

    cout << "\n==============================================\n";
    cout << "                DATA MAHASISWA                \n";
    cout << "==============================================\n";
    cout << "Nama        : " << nama << endl;
    cout << "NIM         : " << nim << endl;
    cout << "Kelas       : " << kelas << endl;
    cout << "Universitas : " << universitas << endl;
    cout << "==============================================\n";

    return 0;
}
