#include<iostream>
#include<vector>
using namespace std;
#define MAXSIZE 30
/*三元组定义*/
struct triple{
    int row, col;
    int val;
    triple(): row(-1), col(-1), val(-1) {}
    triple(int r, int c, int v): row(r), col(c), val(v) {} 
};
/*稀疏矩阵定义*/
struct SparseMatrix {
    int Rows, Cols, size;
    triple elem[MAXSIZE];
    SparseMatrix(): Rows(0), Cols(0), size(0) {}
    SparseMatrix(int r, int c): Rows(r), Cols(c), size(0) {}
    void append(int r, int c, int v) {
        elem[size++] = triple(r, c, v);
    }
};
/*稀疏矩阵乘法实现*/
SparseMatrix multiplySparseMatrix(SparseMatrix a, SparseMatrix b) {
    if (a.Cols != b.Rows) return SparseMatrix();
    SparseMatrix c(a.Rows, b.Cols);
    vector<vector<int>> v(a.Rows + 1, vector<int> (b.Cols + 1));
    for (int i = 0; i < a.size; ++i) {
        for (int j = 0; j < b.size; ++j) {
            if (a.elem[i].col == b.elem[j].row) {v[a.elem[i].row][b.elem[j].col] += a.elem[i].val * b.elem[j].val;}
        }
    }
    for (int i = 1; i <= a.Rows; ++i) {
        for (int j = 1; j <= b.Cols; ++j) {
            if (v[i][j]) c.append(i, j, v[i][j]);
        }
    }
    return c;
}
int main() {
    int r, c, s, v;
    cin>>r>>c>>s;
    SparseMatrix A(r, c);
    while (s--) {
        cin>>r>>c>>v;
        A.append(r, c, v);
    }
    cin>>r>>c>>s;
    SparseMatrix B(r, c);
    while (s--) {
        cin>>r>>c>>v;
        B.append(r, c, v);
    }
    SparseMatrix C = multiplySparseMatrix(A, B);
    cout<<C.Rows<<endl<<C.Cols<<endl<<C.size<<endl;
    for (int i = 0; i < C.size; i += 1) {
        cout<<C.elem[i].row<<","<<C.elem[i].col<<","<<C.elem[i].val<<endl;
    }
}
