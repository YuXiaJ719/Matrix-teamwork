Matrix operator*(Matrix a, Matrix b) {
    Matrix c(a.rows, b.cols);
    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.rows; j++) {
            for (int k = 0; k < a.cols; k++) {
                c.mat[i * a.rows + j] += a.mat[i * a.cols + k] * b.mat[k * b.cols + j];
            }
        }
    }
    return c;
}
