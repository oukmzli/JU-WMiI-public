// Denys Kyrychenko
#include <iostream>
using namespace std;

int rectangular(int l, int v, int p, int h, int w, int d, int cube[32][32][32], int side) {
    int sum = 0;
    if (l < 0) {h+= l; l = 0;} if (p < 0) {d+=p; p = 0;} if (v < 0) {w+=v; v = 0;}
    if (d > side) d = side; if (w > side) w = side; if (h > side) h = side;
    if (p < side/2) d+=p; else { int temp = p; p-=d; d = temp; }
    if (l < side/2) h+=l; else { int temp = l; l-=h; h = temp; }
    if (v < side/2) w+=v; else { int temp = v; v-=w; w = temp; }
    if (l < 0) l = 0; if (p < 0) p = 0; if (v < 0) v = 0;
    
    for (int i = p; i <= d; ++i)
        for (int j = l; j <= h; ++j)
            for (int k = v; k <= w; ++k)
                sum += cube[i][j][k];
    return sum;
}

bool isOctant(int i, int j, int k, int p, int l, int v, int r) {
    if (((p-i)*(p-i))+((l-j)*(l-j))+((v-k)*(v-k)) <= (r*r)) return true;
    return false;
}

int abs(int n) {
    return n >= 0 ? n : -n;
}

bool isTetrahedron (int i, int j, int k, int p, int l, int v, int e) {
    if (abs(p-i)+abs(l-j)+abs(v-k) <= e) return true;
    return false;
}

int octant(int l, int v, int p, int r, int cube[32][32][32], int side) {
    int sum = 0;
    int pr = r, lr = r, vr = r;
    int po = p, lo = l, vo = v;
    
    if (p < side/2) pr+=p; else { p -= pr; pr = po; }
    if (l < side/2) lr+=l; else { l -= lr; lr = lo; }
    if (v < side/2) vr+=v; else { v -= vr; vr = vo; }
    
    for (int i = p; i <= pr; ++i)
        for (int j = l; j <= lr; ++j)
            for (int k = v; k <= vr; ++k) {
                if (i >= 0 && j >= 0 && k >= 0 && isOctant(i, j, k, po, lo, vo, r)) sum+=cube[i][j][k];
            }
    return sum;
}

int tetrahedron(int l, int v, int p, int e, int cube[32][32][32], int side) {
    int sum = 0;
    int pe = e, le = e, ve = e;
    int po = p, lo = l, vo = v;
    
    if (p < side/2) pe+=p; else { p -= pe; pe = po; }
    if (l < side/2) le+=l; else { l -= le; le = lo; }
    if (v < side/2) ve+=v; else { v -= ve; ve = vo; }
    
    for (int i = p; i <= pe; ++i)
        for (int j = l; j <= le; ++j)
            for (int k = v; k <= ve; ++k) {
                if (i >= 0 && j >= 0 && k >= 0 && isTetrahedron(i, j, k, po, lo, vo, e)) sum+=cube[i][j][k];
            }
    return sum;
}

void fillMatrix(int cube[32][32][32], long long matrix[32][32], int side, int id, char k) {
    if (k == 'p') {
        for (int i = 0; i < side; ++i)
            for (int j = 0; j < side; ++j)
                matrix[i][j] = cube[id][i][j];
    } else if (k == 'l') {
        for (int i = 0; i < side; ++i)
            for (int j = 0; j < side; ++j)
                matrix[i][j] = cube[i][id][j];
    } else if (k == 'v') {
        for (int i = 0; i < side; ++i)
            for (int j = 0; j < side; ++j)
                matrix[i][j] = cube[i][j][id];
    }
}

long long determinant(long long matrix[32][32], int side) {
    if (side == 0) return 1;
    if (side == 1) return matrix[0][0];
    if (side == 2) return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
    
    for (int q = 0; q < side; ++q)
        for (int i = q + 1; i < side; ++i) {
            bool rowEquality = 1;
            for (int j = 0; (j < side); ++j)
                if(matrix[q][j] != matrix[i][j]) rowEquality = 0;
            if (rowEquality) return 0;
        }
    
    long long result = 0;
    int sign = 1;
    
    for (int k = 0; k < side; ++k) {
        
        long long minor[32][32];
        int n = 0;
        for (int i = 1; i < side; ++i) {
            int m = 0;
            for (int j = 0; j < side; ++j) {
                if (j != k) { minor[n][m] = matrix[i][j]; m++; }
            } n++;
        }
        
        if (matrix[0][k] != 0)
            result += sign * matrix[0][k] * determinant(minor, side - 1);
        sign *= -1;
    }
    return result;
}

int main() {
    int cube[32][32][32];
    int side; cin >> side;
    if (side < 0 || side > 32 || side % 2 != 0) return 0;
    
    for (int d = 0; d < side; ++d) {
        for (int h = 0; h < side; ++h) {
            for (int w = 0; w < side; ++w) {
                cin >> cube[d][h][w];
            }
        }
    }
    
    char operation;
    do {
        cin >> operation;
        if (operation == 'C') {
            int l, v, p, h, w, d;
            cin >> l >> v >> p >> h >> w >> d;
            cout << rectangular(l, v, p, h, w, d, cube, side) << "\n";
        }
        else if (operation == 'T') {
            int l, v, p, e;
            cin >> l >> v >> p >> e;
            cout << tetrahedron(l, v, p, e, cube, side) << "\n";
        }
        else if (operation == 'O') {
            int l, v, p, r;
            cin >> l >> v >> p >> r;
            cout << octant(l, v, p, r, cube, side) << "\n";
        }
        else if (operation == 'D') {
            char k; int id;
            cin >> k >> id;
            long long matrix[32][32];
            fillMatrix(cube, matrix, side, id, k);
            cout << determinant(matrix, side) << "\n";
        }
    } while (operation != 'E');
    
    return 0;
}
